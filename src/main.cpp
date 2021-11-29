#include <iostream>
#include "Individual.h"

using namespace std;

int main(void) {

	srand(time(nullptr));
	Individual I(3);

	cout << I << endl;

	return 0;
}
