#ifndef NODE_H
#define NODE_H


class Node {
public:
	Node() : data_op(NULL), data_num(NULL), link(nullptr) {};
	Node(char op) : data_op(op), data_num(-1), link(nullptr) {};
	Node(double num) : data_op(' '), data_num(num), link(nullptr) {};

	friend class Stack;
	friend class LinkedList;

private:
	char data_op;
	double data_num;
	Node* link;
};

#endif