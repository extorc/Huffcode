#pragma once
#include "node.h"
#include <iostream>
#include <string>
#include <memory>

class TreeNode : public Node {
	public:
		int count;

		TreeNode(std::shared_ptr<Node> n1, std::shared_ptr<Node> n2): _n1(n1), _n2(n2) {
				std::cout << "N1 Count: " << _n1->count << "\t"<< "N2 Count: " << _n2->count << std::endl;
				count = _n1->count + _n2->count;
			}

		std::string getLabel() { return "TN"; }

	private:
		std::shared_ptr<Node> _n1;
		std::shared_ptr<Node> _n2;
};
