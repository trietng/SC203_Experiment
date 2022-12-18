#include "experiment.hpp"
#include "output.hpp"
#include "file.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	int sample[] = { 1, 2, 3, 4, 5, 9, 8, 7 };
	if (argc == 2) {
		int experiment = atoi(argv[1]);
		switch (experiment) {
		case 1:
			experiment1::run(sample, 8);
			break;
		case 2:
			break;
		default:
			break;
		}
	}
	return 0;
}
