#include <iostream>
#include "Stack.h"

void Stack::push(char item) {
	Node* temp = new Node(item);
	if (IsEmpty()) {
		top = temp;
		size++;
	}
	else {
		temp->link = top;
		top = temp;
		size++;
	}
}

void Stack::push(double item) {
	Node* temp = new Node(item);
	if (IsEmpty()) {
		top = temp;
		size++;
	} 
	else {
		temp->link = top;
		top = temp;
		size++;
	}
}

char Stack::pop_op() {
	if (IsEmpty()){
		return NULL;
	}
	else {
		Node* temp = top;
		char item = top->data_op;
		top = top->link;
		delete temp;
		size--;
		return item;
	}
}

double Stack::pop_num() {
	if (IsEmpty()) {
		return NULL;
	}
	else {
		Node* temp = top;
		double item = top->data_num;
		top = top->link;
		delete temp;
		size--;
		return item;
	}
}

char Stack::get_top_op() {
	if (IsEmpty()) {
		return NULL;
	}
	else {
		return top->data_op;
	}
}

double Stack::get_top_num() {
	if (IsEmpty()) {
		return NULL;
	}
	else {
		return top->data_num;
	}
}