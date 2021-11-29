#include "Individual.h"

using namespace std;

Individual& Individual::operator=(const Individual& other) {

	if (this == &other) {
		return *this;
	}

	delete[] _genome;
	if (other._genome) {
		_genome = new unsigned int[N*N];
		_genome = other._genome;
	} else {
		_genome = nullptr;
	}

	return *this;
}

Individual& Individual::operator=(Individual&& other) {

	delete[] _genome;
	_genome = other._genome;
	other._genome = nullptr;

	return *this;
}

unsigned int& Individual::operator()(unsigned int i, unsigned int j) {

	if (i > N || j > N) {
		throw std::out_of_range("access impossible");
	}

	return _genome[i*N+j];
}

ostream& operator<<(ostream& out, Individual& individual) {

	for (int i=0; i < N; i++) {
		
		out << "[";
		for (int j=0; j < N; j++) {

			if (j == N-1) {
				out << individual(i, j) << "]";
			} else {
				out << individual(i, j) << ", ";
			}
		}
		out << endl;
	}

	return out;
}


