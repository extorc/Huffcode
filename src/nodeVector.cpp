#include "nodeVector.h"


void sortVector(std::vector<std::shared_ptr<Node>> &nodes) {
	std::sort(nodes.begin(), nodes.end(),[](std::shared_ptr<Node> n1,std::shared_ptr<Node> n2) { // Sort Node Vector based on Node Key count
			return (n1->getCount() < n2->getCount());
			});
}

void printVector(std::vector<std::shared_ptr<Node>> &nodes) {
	for (auto node : nodes) { // Print Node Vector Contents
		if (!node->getLabel().empty())
			std::cout << node->getLabel() << ": " << node->getCount() << "; ";
	}
	std::cout << "\n\n";
}
