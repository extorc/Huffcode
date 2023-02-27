#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include "parser.h"
#include <map>
#include "counter.h"
#include <vector>
#include "node.h"
#include "treenode.h"
#include <algorithm>

void sortVector(std::vector<Node*>& nodes){
	std::sort(nodes.begin(), nodes.end(), [](Node* n1, Node* n2){        //Sort Node Vector based on Node Key count
			return (n1->getCount() < n2->getCount());
		}
	);
}
void printVector(std::vector<Node*> nodes){
	for(Node* n : nodes){                                                //Print Node Vector Contents
		if(n->getLabel() != "")
			std::cout<<n->getLabel()<< ":" << n->getCount()<< " ";
	}
}

int main (){
	std::string file =parsefile("../src/file.txt");                      //Create a string of the file 
	std::map<char, int> tally = tallyFile(file);                         //Create a map of the contents of the file string

	std::vector<Node* > nodes;
	std::map<char, int>::iterator iterator;

	for(iterator = tally.begin(); iterator != tally.end(); iterator++){  //Create Node Vector out of the Map
		Node* node = new Node();
		node->count = iterator->second;
		node->label = iterator->first;
		nodes.push_back(node);
	}
	
	sortVector(nodes);
	printVector(nodes);

	TreeNode* treenode = new TreeNode(nodes.at(0), nodes.at(1));
	std::cout<<treenode->count;
	std::cout<<"\n";

	nodes.erase(nodes.begin());
	nodes.erase(nodes.begin()+1);
	nodes.push_back(treenode);
	
	sortVector(nodes);
	printVector(nodes);

	TreeNode* treenode2 = new TreeNode(nodes.at(0), nodes.at(1));
	std::cout<<treenode2->count;
	std::cout<<"\n";

	nodes.erase(nodes.begin());
	nodes.erase(nodes.begin()+1);
	nodes.push_back(treenode2);

	//sortVector(nodes);
	printVector(nodes);
}
