#include <cstdlib>
#include "individuum.h"

Individuum::Individuum(std::shared_ptr<Graph> graph){
	this->graph_obj = graph;
	std::vector<int> tmp_path(this->graph_obj->graph.size() + 1);

	std::vector<int> pool (this->graph_obj->graph.size()-1);
	for (int i = 0; i < pool.size(); ++i){
		pool[i] = i+1;
	}

	tmp_path[0] = 0;
	tmp_path[tmp_path.size()-1] = 0;
	for (int i = 1; i < tmp_path.size()-1; ++i){
		int random = std::rand() % pool.size();
		tmp_path[i] = pool[random];
		pool.erase(pool.begin()+random);
	}
	this->path = tmp_path;
}	

void Individuum::evaluate(){
	this->distance = 0;
}

void Individuum::recombine(Individuum* i1, Individuum* i2){

}

int Individuum::getDist(){
	return 0;
}

void Individuum::repr(){
	for (int i = 0; i < this->path.size(); ++i){
		std::cout << " , " << this->path[i];
	}
	std::cout << std::endl;
}
