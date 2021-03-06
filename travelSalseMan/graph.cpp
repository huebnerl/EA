#include "graph.h"

Graph::Graph(){
	this->infinityValue = 100;
	std::vector<std::vector<int>> vect {
		{0,2,0,4,0,4,0,0,0,0},
		{2,0,3,7,2,0,0,0,0,0},
		{0,3,0,0,7,0,0,6,0,0},
		{4,7,0,0,0,1,2,0,0,0},
		{0,2,7,0,0,0,8,1,0,0},
		{4,0,0,1,0,0,0,0,5,0},
		{0,0,0,2,8,0,0,0,1,2},
		{0,0,6,0,1,0,0,0,0,5},
		{0,0,0,0,0,5,1,0,0,4},
		{0,0,0,0,0,0,2,5,4,0}};
	this->graph = vect;
}

void Graph::repr(){
	for (int i = 0; i < this->graph.size(); ++i){
		for (int j = 0; j < this->graph[i].size(); ++j){
			std::cout << " | " << this->graph[i][j];
		}
		std::cout << std::endl;
	}
}
