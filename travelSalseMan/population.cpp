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

//TODO sort by fittness and delete the two worst
void Population::reduce(float ratio){
	std::sort(this->pop.begin(), this->pop.end(), comperator);
	int seperator = this->size * ratio;
	this->pop = std::vector<Individuum*>(this->pop.begin(),
		       			     this->pop.end() - seperator);
	this->size = this->pop.size();
}

//TODO check if the new indis are already in the Population
void Population::repopulate(int size){
	Parents p = this->selectParents();
	Individuum* indi1 = new Individuum(this->graph);
	Individuum* indi2 = new Individuum(this->graph);

	int random = std::rand() % indi1->getPath().size()-1;
	indi1->recombine(p.muther, p.vather, random);
	indi2->recombine(p.vather, p.muther, random);
	this->pop.push_back(indi1);
	this->pop.push_back(indi2);
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

