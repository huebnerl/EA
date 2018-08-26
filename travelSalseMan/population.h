#ifndef POPULATION_H
#define POPULATION_H

#include <vector>
#include <algorithm>
#include <memory>
#include "individuum.h"
#include "graph.h"

struct Parents{
	Individuum* muther;
	Individuum* vather;
};

class Population{
	private:
		std::vector<Individuum*> pop;
		int size;
		std::shared_ptr<Graph> graph;
	public:
		Population(int size, std::shared_ptr<Graph> graph);
		void repr();
		float evaluate();
		void reduce(float ratio=0.3);
		void repopulate(int size);
		Parents selectParents();
		
};

#endif //POPULATION_H
