#pragma once

class Node{
private:
	int count;
	char label;
public:
	Node(int count, char label):count(count), label(label){}
	int getCount() { return count; }
	char getLabel() { return label; }
};
