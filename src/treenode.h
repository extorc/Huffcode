#pragma once
#include "node.h"
#include <iostream>
#include <string>
#include <memory>

class TreeNode : public Node {
	public:
		int count;
		std::string label = "TN";
		TreeNode(std::shared_ptr<Node> n1, std::shared_ptr<Node> n2): _n1(n1), _n2(n2) {
				count = _n1->count + _n2->count;
				std::cout << "N1 Count: " << _n1->count << " Label: "<<  _n1->getLabel() << "\t"<< "N2 Count: " << _n2->count<< " Label: "<<  _n2->label << " Total count : " << count << std::endl;
			}

		std::string getLabel() { return label; }

	private:
		std::shared_ptr<Node> _n1;
		std::shared_ptr<Node> _n2;
};
