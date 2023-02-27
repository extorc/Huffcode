#include <iostream>
#include <fstream>
#include <string>
#include "parser.h"
#include <map>
#include "counter.h"

int main (){
	std::string file =parsefile("../src/file.txt"); 
	std::map<char, int> tally = tallyFile(file);
	printTally(tally);

	std::cout<<"\n";
}
