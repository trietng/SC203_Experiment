#pragma once
#include <iostream>

namespace output {
	template <typename T>
	void print(T* arr, size_t n) {
		for (size_t i = 0; i < n; ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";
	}
}