#include <iostream>
#include <future>
#include <vector>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <cassert>
#include <cstring>
#pragma once

class ThreadPool {
	std::vector<std::thread> threads;
	std::queue<std::function<void()>> tasks;
	std::mutex mut;
	std::condition_variable cv;
	bool dead = false;
	
	public:
		ThreadPool(size_t poolSize) {
			for (size_t i = 0; i < poolSize; ++i) {
				threads.emplace_back([this]() {
					while(true) {
						std::unique_lock<std::mutex> lock(mut);
						cv.wait(lock, 
						[this] () {
							return !(!dead && tasks.empty());
						});
						if (dead) return;
						auto task = tasks.front();
						tasks.pop();
						task();
					}
				});
			}
		}
		~ThreadPool() {
			dead = true;
			cv.notify_all();
			for (auto& t : threads)
				t.join();
		}
		template <class Func, class... Args>
		auto exec(Func func, Args... args) -> std::future<decltype(func(args...))>{
		    std::unique_lock<std::mutex> lock(mut);
		    auto task = std::make_shared<std::packaged_task<decltype(func(args...))()>>(std::bind(func, args...));
		    tasks.push([task](){(*task)();});
		    cv.notify_one();
		    return task->get_future();
		}
};
