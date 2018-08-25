#include <cstdlib>
#include "individuum.h"

Individuum::Individuum(){
	this->muscleMass = std::rand() % 200 + 1;
}	

void Individuum::evaluate(){
	this->distance = std::abs(MUSCLE_MASS_AIM - this->muscleMass);
}

void Individuum::recombine(Individuum* i1, Individuum* i2){
	this->muscleMass = (i1->getMuscleMass() + i2->getMuscleMass()) / 2.0;
}

int Individuum::getMuscleMass(){
	return this->muscleMass;
}

int Individuum::getDist(){
	return this->distance;
}

