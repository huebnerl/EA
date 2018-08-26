#include <memory>
#include "population.h"
#include "graph.h"

int main(int argc, char* argv[]){
	std::shared_ptr<Graph> graph1 = std::make_shared<Graph>();
	graph1->repr();

	std::shared_ptr<Population> pop1 = std::make_shared<Population>(10, graph1);
	pop1->repr();

	// for (int i = 0; i < 30; ++i){
	// 	float eval = pop1->evaluate();
	// 	pop1->reduce();
	// 	pop1->repopulate(10);
	// 	std::cout << "Population Eval: "  << eval << std::endl;
	// }
	// pop1->repr();

	return 0;
}
