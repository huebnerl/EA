#include <memory>
#include "population.h"

int main(int argc, char* argv[]){
	std::shared_ptr<Population> pop1 = std::make_shared<Population>(10);

	for (int i = 0; i < 20; ++i){
		float eval = pop1->evaluate();
		pop1->reduce();
		pop1->repopulate(10);
		std::cout << "Population Eval: "  << eval << std::endl;
	}
	pop1->repr();

	return 0;
}
