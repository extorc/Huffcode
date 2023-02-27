#pragma once

#include <string>
class Node{
	public:
		int count;
		std::string label;
		int getCount() { return count; }
		virtual std::string getLabel() { return label; }
};
