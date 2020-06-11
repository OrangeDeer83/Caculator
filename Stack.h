#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "Node.h"

class Stack {
public:
	Stack() : top(nullptr), size(0) {};
	void push(char item);
	void push(double item);
	char pop_op();
	double pop_num();
	char get_top_op();
	double get_top_num();
	bool IsEmpty() { return (size == 0); };
	int getSize() { return size; };
	bool IsOp() { return (top->data_op != NULL); };
	bool IsNum() { return (top->data_num != NULL); };

private:
	Node* top;
	int size;
};

#endif
