#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include "parser.h"
#include <map>
#include "counter.h"
#include <vector>
#include "node.h"
#include <algorithm>

int main (){
	std::string file =parsefile("../src/file.txt");                      //Create a string of the file 
	std::map<char, int> tally = tallyFile(file);                         //Create a map of the contents of the file string

	std::vector<Node* > nodes;
	std::map<char, int>::iterator iterator;

	for(iterator = tally.begin(); iterator != tally.end(); iterator++){  //Create Node Vector out of the Map
		nodes.push_back(new Node(iterator->second, iterator->first));
	}
	
	std::sort(nodes.begin(), nodes.end(), [](Node* n1, Node* n2){        //Sort Node Vector based on Node Key count
			return (n1->getCount() > n2->getCount());
		}
	);

	for(Node* n : nodes){                                                //Print Node Vector Contents
		if(n->getLabel())
			std::cout<<n->getLabel()<< ":" << n->getCount()<< " ";
	}
	std::cout<<"\n";
}
