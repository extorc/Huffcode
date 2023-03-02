#include "counter.h"
#include "node.h"
#include "parser.h"
#include "treenode.h"
#include <iostream>
#include <map>
#include <vector>
#include "nodeVector.h"

int main() {
	std::string file = parsefile("../src/file.txt"); // Create a string of the file
	std::map<char, int> tally = tallyFile(file); // Create a map of the contents of the file string

	std::vector<std::shared_ptr<Node>> nodes;
	std::map<char, int>::iterator iter;

	for (iter = tally.begin(); iter != tally.end(); iter++) { // Create Node Vector out of the Map
		std::shared_ptr<Node> node = std::make_shared<Node>(Node());

		node->count = iter->second;
		node->label = iter->first;

		nodes.push_back(node);
	}

	sortVector(nodes);
	printVector(nodes);

	std::shared_ptr<Node> treenode = std::make_shared<TreeNode>(TreeNode(nodes.at(0), nodes.at(1)));

	nodes.erase(nodes.begin(), nodes.begin() + 2);
	nodes.push_back(treenode);

	sortVector(nodes);
	printVector(nodes);
	std::shared_ptr<Node> treenode2 = std::make_shared<TreeNode>(TreeNode(nodes.at(0), nodes.at(1)));

	nodes.erase(nodes.begin(), nodes.begin() + 2);
	nodes.push_back(treenode2);
	
	sortVector(nodes);
	printVector(nodes);
}
