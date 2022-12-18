#include "experiment.hpp"

void experiment2::run(int* arr, size_t n) {
	using namespace std::chrono;
	steady_clock::time_point begin;
	steady_clock::time_point end;
	microseconds result[4]{};
	
	begin = high_resolution_clock::now();
	sort::bubble_sort(arr, n);
	end = high_resolution_clock::now();
	result[0] = duration_cast<microseconds>(end - begin);
	
	begin = high_resolution_clock::now();
	sort::insertion_sort(arr, n);
	end = high_resolution_clock::now();
	result[1] = duration_cast<microseconds>(end - begin);

	begin = high_resolution_clock::now();
	sort::merge_sort(arr, n);
	end = high_resolution_clock::now();
	result[2] = duration_cast<microseconds>(end - begin);

	begin = high_resolution_clock::now();
	sort::quick_sort(arr, n);
	end = high_resolution_clock::now();
	result[3] = duration_cast<microseconds>(end - begin);
}