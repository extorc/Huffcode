#include "parser.h"

std::string parsefile(const char* path){
	std::ifstream myfile;
	myfile.open(path);
	std::string file;
	if ( myfile.is_open() ) {
		while ( myfile ) {
			std::string myline;
			std::getline (myfile, myline);
			file.append(myline);
			file.append("\n");
		}
	}
	else {
		std::cout << "couldn't open file\n";
	}
	return file;
}
