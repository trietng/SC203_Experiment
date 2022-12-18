#pragma once
#include <cstdint>
#include <iostream>
#include <chrono>
#include "sort.hpp"
#include "data.hpp"

namespace experiment1 {
    template <typename T>
    class EXPERIMENT {
    private:
        static inline size_t bubble_count = 0;
        static inline size_t insertion_count = 0;

        static void bubble_sort(T* arr, size_t n) {
            for (size_t i = 0; i < n - 1; i++) {
                for (size_t j = 0; j < n - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        std::swap(arr[j], arr[j + 1]);
                        bubble_count += 3;
                    }
                    ++bubble_count;
                }
                ++bubble_count;
            }
        }

        static void insertion_sort(T* arr, size_t n) {
            for (size_t i = 1; i < n; ++i) {
                size_t j = i - 1;
                T value = arr[i];
                for (; (j >= 0) && (arr[j] > value); --j) {
                    arr[j + 1] = arr[j];
                    insertion_count += 2;
                }
                arr[j + 1] = value;
                insertion_count += 2;
            }
        }
        static void countOperation(T* arr, size_t n) {
            bubble_count = insertion_count = 0;
            bubble_sort(arr, n);
            insertion_sort(arr, n);
        }
        friend void run<T>(T* arr, size_t n);
    };

    template <typename T>
    void run(T* arr, size_t n) {
        EXPERIMENT<T>::countOperation(arr, n);
        std::cout << EXPERIMENT<T>::bubble_count << " " << EXPERIMENT<T>::insertion_count;
    }
}

namespace experiment2 {
    void run(int* arr, size_t n);
}