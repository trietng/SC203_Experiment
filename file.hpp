#pragma once
#include <fstream>

namespace file {
	template <typename T>
	T* read_text(const char* input);

	template <typename T>
	void write_text(T* arr, size_t n, const char* output);

	template <>
	int* read_text(const char* input) {
		std::ifstream fin(input);
		int* temp = nullptr;
		if (fin) {
			size_t n;
			fin >> n;
			temp = new int[n];
			for (size_t i = 0; i < n; ++i) {
				fin >> temp[i];
			}
		}
		return temp;
	}

	template <>
	void write_text(int* arr, size_t n, const char* output) {
		std::ofstream fout(output);
		if (fout) {
			fout << n << " ";
			for (size_t i = 0; i < n; ++i) {
				fout << arr[i] << " ";
			}
		}
	}
}