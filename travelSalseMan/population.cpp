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

//TODO
void Population::reduce(float ratio){
	std::sort(this->pop.begin(), this->pop.end(), comperator);
	int seperator = this->size * ratio;
	this->pop = std::vector<Individuum*>(this->pop.begin(),
		       			     this->pop.end() - seperator);
	this->size = this->pop.size();
}

//TODO
void Population::repopulate(int size){
	for (int i = 0; i < size - this->size; ++i){
		Parents p = this->selectParents();
		Individuum* indi = new Individuum(this->graph);
		indi->recombine(p.muther, p.vather);
		this->pop.push_back(indi);
	}	
}

Parents Population::selectParents(){
	Individuum* m = this->selectParent();
	Individuum* v = this->selectParent();
	int error = 0;
	while(m->getPath() == v->getPath() && error < 1000){
		v = this->selectParent();
		++error;
	}
	if(error == 1000){
		std::cout << "Error while selecting Parents." << std::endl;
	}	
	return {m, v};
}

Individuum* Population::selectParent(){
	int total_dist_sum = 0;
	for(int i = 0; i < this->pop.size(); ++i){
		total_dist_sum += this->pop[i]->getDist();
	}

	int rand = std::rand() % (total_dist_sum+1);
	int i = 0;
	int tmp_sum = this->pop[i]->getDist();
	while(rand > tmp_sum){
		++i;
		tmp_sum += this->pop[i]->getDist();
	}
 	return this->pop[i];
}

void Population::repr(){
	for (int i = 0; i < this->pop.size(); ++i){
		this->pop[i]->evaluate();
		std::cout << "[" << i << "] ";
		this->pop[i]->repr();
		std::cout << "  Distance: " << this->pop[i]->getDist() << "  Fitness: " << this->pop[i]->getFitness();
		std::cout << std::endl;
	}
}

