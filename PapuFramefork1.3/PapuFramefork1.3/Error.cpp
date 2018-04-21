#include "Error.h"
#include <iostream>

using namespace std;

void fatalError(std::string errrString) {
	cout << errrString << endl;
	cout << "Enter any key to quit " << endl;
	int tmp;
	cin >> tmp;
	exit(-1);
}