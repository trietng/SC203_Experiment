#include "experiment.hpp"
#include "output.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	int sample[] = { 1, 2, 3, 4, 5, 9, 8, 7 };
	if (argc == 2) {
		int experiment;
		int choice;
		try {
			experiment = atoi(argv[1]);
		}
		catch (...) {
			experiment = 0;
		}
		switch (experiment) {
		case 0:
			break;
		case 1:
			experiment1::run();
			break;
		case 2:
			//output::print(sample, 8);
			//sort::quick_sort(sample, n);
			//output::print(sample, 8);
			break;
		case 3:
			cout << "Generate data for experiment 1 or 2? ";
			cin >> choice;
			if (choice == 1) {
				experiment1::generate();
			}
			else if (choice == 2) {

			}
			break;
		default:
			break;
		}
	}
	return 0;
}
