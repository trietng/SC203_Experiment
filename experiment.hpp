#pragma once
#include <cstdint>
#include <iostream>
#include <fstream>
#include <chrono>
#include "sort.hpp"
#include "data.hpp"

namespace experiment1 {
    template <typename T>
    class EXPERIMENT {
    private:
        static inline size_t bubble_assignment = 0;
        static inline size_t insertion_assignment = 0;
        static inline long long bubble_exec_time = 0;
        static inline long long insertion_exec_time = 0;

        static void bubble_sort(T* arr, size_t n) {
            bool k = true;
            for (size_t i = 0; (i < n - 1) && (k == true); i++) {
                k = false;
                for (size_t j = 0; j < n - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        std::swap(arr[j], arr[j + 1]);
                        bubble_assignment += 3;
                        k = true;
                    }
                }
            }
        }

        static void insertion_sort(T* arr, size_t n) {
            for (size_t i = 1; i < n; ++i) {
                size_t j = i - 1;
                T value = arr[i];
                for (; (j >= 0) && (arr[j] > value); --j) {
                    arr[j + 1] = arr[j];
                    insertion_assignment++;
                }
                arr[j + 1] = value;
                insertion_assignment++;
            }
        }
        static void count_operation(T* arr, size_t n) {
            bubble_assignment = 0;
            insertion_assignment = 0;
            T* tmp0 = new T[n];
            T* tmp1 = new T[n];
            memcpy(tmp0, arr, n * sizeof(T));
            memcpy(tmp1, arr, n * sizeof(T));
            bubble_sort(tmp0, n);
            insertion_sort(tmp1, n);
            delete[] tmp0, tmp1;
        }
        static void get_execution_time(T* arr, size_t n) {
            T* tmp0 = new T[n];
            T* tmp1 = new T[n];
            memcpy(tmp0, arr, n * sizeof(T));
            memcpy(tmp1, arr, n * sizeof(T));
            insertion_exec_time = sort::measure<T>(tmp0, n, &sort::insertion_sort<T>);
            bubble_exec_time = sort::measure<T>(tmp1, n, & sort::bubble_sort<T>);
            delete[] tmp0, tmp1;
        }
        static void write_result(const char* output) {
            std::ofstream fout(output);
            fout << "Bubble sort: " << bubble_assignment << " assignments";
            fout << "\nExecution time: " << bubble_exec_time << " ns";
            fout << "\nInsertion sort: " << insertion_assignment << " assigments";
            fout << "\nExecution time: " << insertion_exec_time << " ns";
        }
        friend void run();
    };

    int* read_text(const char* input, size_t n);

    void generate();

    void run();
}

