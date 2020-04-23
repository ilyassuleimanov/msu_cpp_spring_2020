#include "includes.h"
#pragma once

template <class T>
class iterator : 
	public std::iterator<std::random_access_iterator_tag, T> {
	
	public:	
		T* data;
	
		iterator<T>(T* ptr) : data(ptr) {}
		
		iterator<T>(const iterator<T>& it) : data(it.data) {}	
		
		iterator& operator-=(size_t num) {
			data -= num;
			return *this;
		}
		
		iterator& operator+=(size_t num) {
			data += num;
			return *this;
		}
		
		std::ptrdiff_t operator-(const iterator<T> it) {
			return data - it.data;
		}
		
		iterator operator-(size_t num) {
			return iterator<T>(data - num);
		}
		
		iterator operator+(size_t num) {
			return iterator<T>(data + num);
		}
		
		iterator& operator--() {
			--data;
			return *this;
		}
		
		iterator& operator++() {
			++data;
			return *this;
		}
		
		T& operator*() {
			return *data;
		}
		
		bool operator!=(const iterator<T>& it) {
			return !(*this == it);
		}
		
		bool operator==(const iterator<T>& it) {
					return data = it.data;
		}
};
