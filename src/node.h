#pragma once

class Node{
	public:
		int count;
		char label;
		int getCount() { return count; }
		virtual char getLabel() { return label; }
};
