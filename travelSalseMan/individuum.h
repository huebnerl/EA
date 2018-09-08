#ifndef INDIVIDUUM_H
#define INDIVIDUUM_H

#include <iostream>
#include <memory>
#include <algorithm>
#include "graph.h"

#define MUSCLE_MASS_AIM 100

class Individuum{
	private:
		std::vector<int> path;
		std::shared_ptr<Graph> graph_obj;
	public:
		float distance;

		Individuum(std::shared_ptr<Graph> graph);
		int getDist();
		std::vector<int> getPath();
		float getFitness();
		void evaluate();
		void recombine(Individuum* i1, Individuum* i2,
			       	int crossOverPoint);
		void repr();
};

#endif //INDIVIDUUM_H
