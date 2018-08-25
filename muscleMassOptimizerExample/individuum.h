#ifndef INDIVIDUUM_H
#define INDIVIDUUM_H

#include <iostream>

#define MUSCLE_MASS_AIM 100

class Individuum{
	private:
		int muscleMass;
	public:
		int distance;

		Individuum();
		int getMuscleMass();
		int getDist();
		void evaluate();
		void recombine(Individuum* i1, Individuum* i2);
};

#endif //INDIVIDUUM_H
