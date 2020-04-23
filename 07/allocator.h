#include "includes.h"
#pragma once

template <class T>
class allocator {
	public:		
		void destroy(T* ptr) {
			ptr->~T();
		}
		
		void deallocate(T* ptr, size_t num) {
			free(ptr);
		}
		
		void construct(T* ptr, const T& val) {
			new(ptr) T(val);
		}
		
		T* allocate(size_t num) {
			auto ptr = static_cast<T*>(malloc(num * sizeof(T)));
			if (ptr == NULL)
				throw std::bad_alloc();
			return ptr;
		}
};
