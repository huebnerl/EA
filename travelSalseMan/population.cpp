#include "population.h"

bool comperator(const Individuum *i1, const Individuum *i2){
	return i1->distance < i2->distance;
}

Population::Population(int size, std::shared_ptr<Graph> graph){
	this->size = size;
	this->graph = graph;
	for (int i = 0; i < this->size; ++i){
		this->pop.push_back(new Individuum(this->graph));
	}
}

float Population::evaluate(){
	float result = 0;
	for (int i = 0; i < this->size; ++i){
		this->pop[i]->evaluate();
		result += this->pop[i]->getDist();
	}
	return result / this->size;
}

void Population::reduce(float ratio){
	std::sort(this->pop.begin(), this->pop.end(), comperator);
	int seperator = this->size * ratio;
	this->pop = std::vector<Individuum*>(this->pop.begin(),
		       			     this->pop.end() - seperator);
	this->size = this->pop.size();
}

void Population::repopulate(int size){
	for (int i = 0; i < size - this->size; ++i){
		Parents p = this->selectParents();
		Individuum* indi = new Individuum(this->graph);
		indi->recombine(p.muther, p.vather);
		this->pop.push_back(indi);
	}	
}

Parents Population::selectParents(){
 	Individuum* m = this->pop[std::rand() % this->size];
 	Individuum* v = this->pop[std::rand() % this->size];
	return {m, v};
}

void Population::repr(){
	for (int i = 0; i < this->pop.size(); ++i){
		this->pop[i]->evaluate();
		std::cout << "[" << i << "] ";
		this->pop[i]->repr();
	}
}

