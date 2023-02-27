#include "counter.h"

char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

std::map<char, int> tallyFile(std::string file){
	std::map<char, int> tally;
	for (char c : alphabet) {
		tally[c] = 0;
	}

	for(auto c : file){
		tally[c]++;
	}
	return tally;
}

void printTally(std::map<char, int> tally){
	for(char c : alphabet){
		if(c != '\0')
			std::cout<<c<<":"<<tally[c]<<" ";
	}
}
