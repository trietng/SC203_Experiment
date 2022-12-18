#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <fstream>

template<class RandomIt, class URBG>
void shuffly(RandomIt first, RandomIt last, URBG&& g)
{
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

 
int main()
{
    std::vector<int> v;

    for (int i = 0; i < 100; ++i){
        v.push_back(i);
    }
    std::ofstream fout;
    fout.open("shuffled_vector.txt");
 

    std::random_device rd;
    std::mt19937 g(rd());
 
    shuffly(v.begin(), v.end(), g);
 
    for (auto i: v){
        fout << i << std::endl;
    }
    fout.close();
    return 0;
}