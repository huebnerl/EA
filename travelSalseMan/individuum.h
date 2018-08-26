#ifndef INDIVIDUUM_H
#define INDIVIDUUM_H

#include <iostream>
#include <memory>
#include "graph.h"

#define MUSCLE_MASS_AIM 100

class Individuum{
	private:
		std::vector<int> path;
		std::shared_ptr<Graph> graph_obj;
	public:
		int distance;

		Individuum(std::shared_ptr<Graph> graph);
		int getDist();
		void evaluate();
		void recombine(Individuum* i1, Individuum* i2);
		void repr();
};

#endif //INDIVIDUUM_H
