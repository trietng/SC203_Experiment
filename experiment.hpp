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
        static inline size_t bubble_assignment = 0;
        static inline size_t bubble_comparison = 0;
        static inline size_t bubble_lookup = 0;
        static inline size_t insertion_assignment = 0;
        static inline size_t insertion_lookup = 0;

        static void bubble_sort(T* arr, size_t n) {
            bool k = true;
            for (size_t i = 0; (i < n - 1) && (k == true); i++) {
                k = false;
                for (size_t j = 0; j < n - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        std::swap(arr[j], arr[j + 1]);
                        bubble_assignment += 3;
                        ++bubble_comparison;
                        k = true;
                    }
                    ++bubble_lookup;
                }
                ++bubble_lookup;
            }
        }

        static void insertion_sort(T* arr, size_t n) {
            for (size_t i = 1; i < n; ++i) {
                size_t j = i - 1;
                T value = arr[i];
                for (; (j >= 0) && (arr[j] > value); --j) {
                    arr[j + 1] = arr[j];
                    insertion_assignment++;
                    insertion_lookup++;
                }
                arr[j + 1] = value;
                insertion_assignment++;
                insertion_lookup++;
            }
        }
        static void countOperation(T* arr, size_t n) {
            bubble_assignment = 0;
            bubble_comparison = 0;
            bubble_lookup = 0;
            insertion_assignment = 0;
            insertion_lookup = 0;
            bubble_sort(arr, n);
            insertion_sort(arr, n);
        }
        friend void run<T>(T* arr, size_t n);
    };

    template <typename T>
    void run(T* arr, size_t n) {
        EXPERIMENT<T>::countOperation(arr, n);
        std::cout << "Bubble sort: " << EXPERIMENT<T>::bubble_assignment << " assignments, "
        << EXPERIMENT<T>::bubble_comparison << " comparisons, "
        << EXPERIMENT<T>::bubble_lookup << " lookups, "
        << EXPERIMENT<T>::bubble_assignment + EXPERIMENT<T>::bubble_comparison + EXPERIMENT<T>::bubble_lookup << " total";
        std::cout << "\nInsertion sort: " << EXPERIMENT<T>::insertion_assignment << " assigments, "
        << "0 comparisons, "
        << EXPERIMENT<T>::insertion_lookup << " lookups, "
        << EXPERIMENT<T>::insertion_assignment + EXPERIMENT<T>::insertion_lookup << " total";
    }
}

namespace experiment2 {
    void run(int* arr, size_t n);
}