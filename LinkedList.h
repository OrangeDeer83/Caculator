#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"

class LinkedList{
public:
	LinkedList() : first(nullptr), size(0) {};
	void add(char item);
	void add(double item);
	char get_op(int index);
	double get_num(int index);
	bool IsEmpty() { return (size == 0); };
	int getSize() { return size; };
	bool IsOp(int index) { return (get_op(index) != ' '); };
	bool IsNum(int index) { return (get_num(index) != -1); };
	bool Debug();

private:
	Node* first;
	int size;
};

#endif
