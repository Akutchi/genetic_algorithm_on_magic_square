#ifndef IND_H
#define IND_H
#include <iostream>
#include <cstring>
#include <ctime>
#define N 3
#define CONSTANT 15

class Individual {

	private:
		unsigned int* _genome;

	public:
		Individual():_genome(nullptr){}
		inline Individual(const unsigned int n);
		inline ~Individual();
		inline Individual(const Individual& other);
		inline Individual(Individual&& other);

		Individual& operator=(const Individual& other);
		Individual& operator=(Individual&& other);
		unsigned int& operator()(unsigned int i, unsigned int j);
};

std::ostream& operator<<(std::ostream& out, Individual& individual);


Individual::Individual(const unsigned int n) {

	_genome = new unsigned int[N*N];
	
	unsigned int nSquared = N*N;
	for (unsigned int i=0; i < nSquared; i++) {
		_genome[i] = rand()%nSquared;
	}
}

Individual::~Individual() {
	delete[] _genome;
}

Individual::Individual(const Individual& other) {
	
	if (other._genome) {
		_genome = new unsigned int[N*N];
		_genome = other._genome;
	} else {
		_genome = nullptr;
	}
}

Individual::Individual(Individual&& other) {
	_genome = other._genome;
	other._genome = nullptr;
}
#endif
