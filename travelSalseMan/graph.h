#ifndef GRAPH_H
#define GRAPH_H

#include <cstdlib>
#include <vector>
#include <iostream>

class Graph{
	public:
		int infinityValue;
		std::vector<std::vector<int>> graph;
		Graph();
		void repr();
};

#endif //GRAPH_H
