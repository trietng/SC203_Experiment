﻿#pragma once

#include <iostream>
#include <cstring>
#include <cstdlib>

namespace sort {
    template <typename T>
    void bubble_sort(T* arr, size_t n) {
        bool k = true;
        for (size_t i = 0; (i < n - 1) && (k == true); i++) {
            k = false;
            for (size_t j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                    k = true;
                }
            }
        }
    }

	template <typename T>
    void insertion_sort(T* arr, size_t n) {
        for (size_t i = 1; i < n; ++i) {
            size_t j = i - 1;
            T value = arr[i];
            for (; (j >= 0) && (arr[j] > value); --j) {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = value;
        }
    }

    template <typename T>
    class MERGE {
    private:
        static void merge(T* arr, size_t left, size_t mid, size_t right) {
            size_t l_len = mid - left + 1, r_len = right - mid;
            T* l = new T[l_len];
            T* r = new T[r_len];
            for (size_t i = 0; i < l_len; ++i) {
                l[i] = arr[left + i];
            }
            for (size_t i = 0; i < r_len; ++i) {
                r[i] = arr[mid + i + 1];
            }
            size_t i = 0, j = 0, k = left;
            //Merge until i reach l_ren or j reach r_len
            while (i < l_len && j < r_len) {
                if (l[i] <= r[j]) {
                    arr[k] = l[i];
                    ++i;
                }
                else {
                    arr[k] = r[j];
                    ++j;
                }
                ++k;
            }
            while (i < l_len) {
                arr[k] = l[i];
                ++i;
                ++k;
            }
            while (j < r_len) {
                arr[k] = r[j];
                ++j;
                ++k;
            }
            delete[] l;
            delete[] r;
        }
        
        static void sort(T* arr, size_t left, size_t right) {
            if (left >= right) return;
            size_t mid = left + ((right - left) / 2);
            sort(arr, left, mid);
            sort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }

        friend void merge_sort<T>(T* arr, size_t n);
    };

    template <typename T>
    void merge_sort(T* arr, size_t n) {
        MERGE<T>::sort(arr, 0, n - 1);
    }

    template <typename T>
    void quick_sort(T* arr, size_t n) {
        std::qsort(
            arr,
            n,
            sizeof(T),
            [](const void* x, const void* y) {
                const T arg1 = *static_cast<const T*>(x);
                const T arg2 = *static_cast<const T*>(y);
                const auto cmp = arg1 <=> arg2;
                if (cmp < 0) return -1;
                if (cmp > 0) return 1;
                return 0;
            }
        );
    }
}