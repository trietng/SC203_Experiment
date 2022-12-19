#include "experiment.hpp"
#include "output.hpp"
#include "file.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	int sample[] = { 1, 2, 3, 4, 5, 9, 8, 7 };
	size_t n = sizeof(sample) / sizeof(int);
	output::print(sample, 8);
	sort::quick_sort(sample, n);
	output::print(sample, 8);
	/*experiment1::run(sample, 8);
	if (argc == 2) {
		int experiment = atoi(argv[2]);
		switch (experiment) {
		case 1:
			experiment1::run(sample, 8);
			break;
		case 2:
			output::print(sample, 8);
			sort::quick_sort(sample, n);
			output::print(sample, 8);
			break;
		default:
			break;
		}
	}*/
	return 0;
}
