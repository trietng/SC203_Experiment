#include "experiment.hpp"

void experiment1::generate() {
    std::random_device rd;
    std::mt19937 g(rd());

    std::ofstream fout;

    std::vector<int> vec(100, 0);

    generate_sorted(vec.begin(), vec.end(), g);
    shuffle_to_nearly_sorted(vec.begin(), vec.end(), g);
    fout.open("data/input/experiment1/100.txt");
    for (const auto& item : vec) {
        fout << item << "\n";
    }
    fout.close();

    vec.assign(1000, 0);
    generate_sorted(vec.begin(), vec.end(), g);
    shuffle_to_nearly_sorted(vec.begin(), vec.end(), g);
    fout.open("data/input/experiment1/1000.txt");
    for (const auto& item : vec) {
        fout << item << "\n";
    }
    fout.close();

    vec.assign(10000, 0);
    generate_sorted(vec.begin(), vec.end(), g);
    shuffle_to_nearly_sorted(vec.begin(), vec.end(), g);
    fout.open("data/input/experiment1/10000.txt");
    for (const auto& item : vec) {
        fout << item << "\n";
    }
    fout.close();
}

int* experiment1::read_text(const char* input, size_t n) {
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

void experiment1::run() {
    int* arr0, * arr1, * arr2;
    int n0 = 100, n1 = 1000, n2 = 10000;

    arr0 = read_text("data/input/experiment1/100.txt", n0);
    EXPERIMENT<int>::count_operation(arr0, n0);
    EXPERIMENT<int>::get_execution_time(arr0, n0);
    EXPERIMENT<int>::write_result("data/output/experiment1/100.txt");

    arr1 = read_text("data/input/experiment1/1000.txt", n1);
    EXPERIMENT<int>::count_operation(arr1, n1);
    EXPERIMENT<int>::get_execution_time(arr1, n1);
    EXPERIMENT<int>::write_result("data/output/experiment1/1000.txt");

    arr2 = read_text("data/input/experiment1/10000.txt", n2);
    EXPERIMENT<int>::count_operation(arr2, n2);
    EXPERIMENT<int>::get_execution_time(arr2, n2);
    EXPERIMENT<int>::write_result("data/output/experiment1/10000.txt");

    delete[] arr0, arr1, arr2;
}

void experiment2::run(int* arr, size_t n) {
	
}