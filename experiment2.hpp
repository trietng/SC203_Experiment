#pragma once
#include <cstdint>
#include <iostream>
#include <fstream>
#include <chrono>
#include "sort.hpp"
#include "data.hpp"

namespace experiment2 {
    template<class T>
    class EXPERIMENT_2{
        static inline long long bubble_exec_time = 0;
        static inline long long insertion_exec_time = 0;
        static inline long long quick_exec_time = 0;
        static inline long long merge_exec_time = 0;
        static void get_execution_time(T* arr, size_t n) {
            T* tmp0 = new T[n];
            T* tmp1 = new T[n];
            T* tmp2 = new T[n];
            T* tmp3 = new T[n];

            memcpy(tmp0, arr, n * sizeof(T));
            memcpy(tmp1, arr, n * sizeof(T));
            memcpy(tmp2, arr, n * sizeof(T));
            memcpy(tmp3, arr, n * sizeof(T));

            insertion_exec_time = sort::measure<T>(tmp0, n, &sort::insertion_sort<T>);
            bubble_exec_time = sort::measure<T>(tmp1, n, & sort::bubble_sort<T>);
            quick_exec_time = sort::measure<T>(tmp2, n, & sort::quick_sort<T>);
            merge_exec_time = sort::measure<T>(tmp3, n, & sort::merge_sort<T>);
            delete[] tmp0, tmp1, tmp2, tmp3;
        }
        static void write_result(const char* output) {
            std::ofstream fout(output);
            fout << "\nExecution time Bubble sort: " << bubble_exec_time << " ns";
            fout << "\nExecution time Insertion sort: " << insertion_exec_time << " ns";
            fout << "\nExecution time Quick sort: " << quick_exec_time << " ns";
            fout << "\nExecution time Merge sort: " << merge_exec_time << " ns";
        }
        friend void run();

    };
    int* read_text(const char* input, size_t n);
    void run();
    void generate();
}