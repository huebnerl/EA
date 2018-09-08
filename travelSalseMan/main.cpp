#include <memory>
#include "population.h"
#include "graph.h"
#include "individuum.h"

int main(int argc, char* argv[]){
	std::shared_ptr<Graph> graph1 = std::make_shared<Graph>();
	graph1->repr();

	std::shared_ptr<Population> pop1 = std::make_shared<Population>(10, graph1);
	pop1->repr();

	Parents p = pop1->selectParents();
	Individuum* indi = new Individuum(graph1);
	indi->recombine(p.muther, p.vather, 6);
	p.muther->repr();
	std::cout << "" << std::endl;
	p.vather->repr();
	std::cout << "" << std::endl;
	indi->repr();
	std::cout << "" << std::endl;


	// for (int i = 0; i < 30; ++i){
	// 	float eval = pop1->evaluate();
	// 	pop1->reduce();
	// 	pop1->repopulate(10);
	// 	std::cout << "Population Eval: "  << eval << std::endl;
	// }
	// pop1->repr();

	return 0;
}
