#include <cstdlib>
#include "individuum.h"

Individuum::Individuum(std::shared_ptr<Graph> graph){
	this->distance = 0;
	this->graph_obj = graph;
	std::vector<int> tmp_path(this->graph_obj->graph.size() + 1);

	std::vector<int> pool (this->graph_obj->graph.size()-1);
	for (int i = 0; i < pool.size(); ++i){
		pool[i] = i+2;
	}

	tmp_path[0] = 1;
	tmp_path[tmp_path.size()-1] = 1;
	for (int i = 1; i < tmp_path.size()-1; ++i){
		int random = std::rand() % pool.size();
		tmp_path[i] = pool[random];
		pool.erase(pool.begin()+random);
	}
	this->path = tmp_path;
}	

void Individuum::evaluate(){
	int tmp_dist = 0;
    for (int i = 0; i < this->path.size()-1; ++i){
    	int step_dist = this->graph_obj->graph[this->path[i]-1][this->path[i+1]-1];	
		tmp_dist += (step_dist == 0) ? this->graph_obj->infinityValue : step_dist;
    }
	this->distance = tmp_dist;
}

void Individuum::recombine(Individuum* i1, Individuum* i2){

}

int Individuum::getDist(){
	return this->distance;
}

float Individuum::getFitness(){
	return 1.0/this->distance;
}

std::vector<int> Individuum::getPath(){
	return this->path;
}

void Individuum::repr(){
	for (int i = 0; i < this->path.size(); ++i){
		std::cout << " , " << this->path[i];
	}
}
