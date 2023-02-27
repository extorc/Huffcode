#pragma once
#include <iostream>
#include "node.h"
#include <string>

class TreeNode : public Node{
	public:
		int count;
		TreeNode(Node* n1, Node* n2):n1(n1), n2(n2){
			//std::cout<<"Treenode count is"<<n1->getCount()<<"+"<<n2->getCount()<<std::endl;
			count = n1->count + n2->count;
		}
		std::string getLabel() { return "Treenode";}
		Node* n1;
		Node* n2;
};
