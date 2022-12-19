#pragma once
#include <random>
#include <algorithm>
#include <iterator>
#include <vector>
#include <fstream>

template<class RandomIt, class URBG>
void shuffle_to_nearly_sorted(RandomIt first, RandomIt last, URBG&& g) {
    typedef typename std::iterator_traits<RandomIt>::difference_type diff_t;
    typedef std::uniform_int_distribution<diff_t> distr_t;
    typedef typename distr_t::param_type param_t;

    distr_t D;
    diff_t n = last - first;
    for (diff_t i = n - 1; i > 0; --i) {
        using std::swap;
        if (D(g, param_t(0, 100)) > 4) continue;
        swap(first[i], first[D(g, param_t(0, i))]);
    }
}

template<class RandomIt, class URBG>
void generate_sorted(RandomIt first, RandomIt last, URBG&& g) {
    typedef typename std::iterator_traits<RandomIt>::difference_type diff_t;
    typedef std::uniform_int_distribution<diff_t> distr_t;
    typedef typename distr_t::param_type param_t;

    distr_t D;
    diff_t n = last - first;
    for (diff_t i = n - 1; i > 0; --i) {
        first[i] = D(g, param_t(0, INT32_MAX));
    }
    std::sort(first, last);
}