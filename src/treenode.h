#pragma once

#include "node.h"
#include <cstdio>

class TreeNode : Node{
	public:
		int count;
		TreeNode(Node* n1, Node* n2):n1(n1), n2(n2){
			count = n1->count + n2->count;
		}
	private:
		Node* n1;
		Node* n2;
};
