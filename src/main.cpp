#include "counter.h"
#include "node.h"
#include "parser.h"
#include "treenode.h"
#include <iostream>
#include <map>
#include <vector>

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

int main() {
	std::string file = parsefile("../src/file.txt"); // Create a string of the file
	std::map<char, int> tally = tallyFile(file); // Create a map of the contents of the file string

	std::vector<std::shared_ptr<Node>> nodes;
	std::map<char, int>::iterator iterator;

	for (iterator = tally.begin(); iterator != tally.end(); iterator++) { // Create Node Vector out of the Map
		std::shared_ptr<Node> node = std::make_shared<Node>(Node());

		node->count = iterator->second;
		node->label = iterator->first;

		nodes.push_back(node);
	}

	sortVector(nodes);
	printVector(nodes);

	std::shared_ptr<Node> treenode = std::make_shared<TreeNode>(TreeNode(nodes.at(0), nodes.at(1)));

	nodes.erase(nodes.begin());
	nodes.erase(nodes.begin() + 1);
	nodes.push_back(treenode);

	sortVector(nodes);
	printVector(nodes);
	std::shared_ptr<Node> treenode2 = std::make_shared<TreeNode>(TreeNode(nodes.at(0), nodes.at(1)));

	nodes.erase(nodes.begin());
	nodes.erase(nodes.begin() + 1);
	nodes.push_back(treenode2);

	sortVector(nodes);
	printVector(nodes);
	std::shared_ptr<Node> treenode3 = std::make_shared<TreeNode>(TreeNode(nodes.at(0), nodes.at(1)));

	nodes.erase(nodes.begin());
	nodes.erase(nodes.begin() + 1);
	nodes.push_back(treenode3);

	sortVector(nodes);
	printVector(nodes);
}
