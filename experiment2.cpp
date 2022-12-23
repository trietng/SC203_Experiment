#include "experiment2.hpp"


void experiment2::generate(){
    std::random_device rd;
    std::mt19937 g(rd());

    std::ofstream fout;

    std::vector<int> vec(100000, 0);

    generate_sorted(vec.begin(), vec.end(), g);
    shuffle_to_nearly_sorted(vec.begin(), vec.end(), g);
    fout.open("data/input/experiment2/1000000.txt");
    for (const auto& item : vec) {
        fout << item << "\n";
    }
    fout.close();
}

int* experiment2::read_text(const char* input, size_t n) {
    std::ifstream fin(input);
    int* temp = nullptr;
    if (fin) {
        temp = new int[n];
        for (size_t i = 0; i < n; ++i) {
            fin >> temp[i];
        }
    }
    return temp;
}

void experiment2::run() {
    int* arr0;
    int n0 = 100000;

    arr0 = read_text("data/input/experiment2/1000000.txt", n0);
    EXPERIMENT_2<int>::get_execution_time(arr0, n0);
    EXPERIMENT_2<int>::write_result("data/output/experiment2/1000000.txt");

    delete[] arr0;
}

