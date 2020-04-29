#include "includes.h"
#pragma once

template <class T, class alloc_t = allocator<T>>
class vector {
	size_t size_;
	T* data;
	alloc_t alloc;
	using Iterator = iterator<T>;	
	public:

		vector(size_t num) : size_(num), data(alloc.allocate(num)) {}	
		vector(size_t num, const T& val) : size_(num), data(alloc.allocate(num)) {
			for (size_t i = 0; i != num; ++i) {
				alloc.construct(data + i, val);
			}
		}
		vector(const vector& vec) : size_(vec.size()), data(vec.begin()) {
			for (size_t i = 0; i != size_; ++i) {
				alloc.construct(data + i, vec[i]);
			}
		}
		~vector() {
			for (size_t i = 0; i != size_; ++i) {
				alloc.destroy(data + i);
			}
			alloc.deallocate(data, size_);
		}
		size_t size() {
			return size_;
		}			
		void pop_back() {
			if (size_ > 0) {
				resize(size_ - 1);
				--size_;
			}
		}
		void push_back(const T& val) {
			resize(size_ + 1, val);
		}		
		void clear() {
			resize(0);
		}
		Iterator end() {
			return Iterator(data + size_);
		}
		Iterator begin() {
			return Iterator(data);
		}
		std::reverse_iterator<Iterator> rend() {
			return std::reverse_iterator<Iterator>(begin());
		}
		std::reverse_iterator<Iterator> rbegin() {
			return std::reverse_iterator<Iterator>(end());
		}						
		void resize(size_t n) {      
	        if (n < size_) {
	        	T* new_p = alloc.allocate(n); 
	        	for (size_t i = 0; i != n; ++i) {
	        		alloc.construct(new_p + i, data[i]);
				}
				for (size_t i = 0; i != size_; ++i) {
					alloc.destroy(data + i);
				}
				alloc.deallocate(data, size_);
				data = new_p;
				size_ = n;
			}
			else
				if (n > size_) {
					reserve(n);
				}
		}
		void resize(size_t n, const T& val) {
			size_t old_size = size_;
		    resize(n);
		    if (n > old_size) {
		        for (size_t i = old_size; i != n; ++i) {
		        	alloc.construct(data + i, val);
				}
		    }
		    size_ = n;
		}	
		void reserve(size_t n) {
			if (n > size_) {
				T* new_p = alloc.allocate(n);
				for (size_t i = 0; i != size_; ++i) {
					alloc.construct(new_p + i, data[i]);
					alloc.destroy(data + i);
				}
				alloc.deallocate(data, size_);
				data = new_p;
				size_ = n;
			}
		}
		bool empty() {
			return (size_ == 0 ? true : false);
		}
		T& operator[] (size_t ind) {
			if (ind >= size_) {
				throw std::out_of_range("");
			}
			return data[ind];
		}
};
