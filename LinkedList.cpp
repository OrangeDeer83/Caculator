#include <iostream>
#include "LinkedList.h"

void LinkedList::add(char item) {
	Node* temp = new Node(item);
	if (IsEmpty()) {
		first = temp;
		size++;
	}
	else {
		temp->link = first;
		first = temp;
		size++;
	}
}

void LinkedList::add(double item) {
	Node* temp = new Node(item);
	if (IsEmpty()) {
		first = temp;
		size++;
	}
	else {
		temp->link = first;
		first = temp;
		size++;
	}
}

char LinkedList::get_op(int index) {
	if (IsEmpty()) {
		return NULL;
	}
	else {
		Node* temp = first;
		for (int i = size - 1; i > index; i--) {
			temp = temp->link;
		}
		return temp->data_op;
	}
}

double LinkedList::get_num(int index) {
	if (IsEmpty()) {
		return NULL;
	}
	else {
		Node* temp = first;
		for (int i = size - 1; i > index; i--) {
			temp = temp->link;
		}
		return temp->data_num;
	}
}

bool LinkedList::Debug() {
	int check_parent = 0;
	for (int i = 0; i < size; i++) {
		if (IsOp(i)) {
			if (get_op(i) == '(') {
				check_parent++;
			}
			if (get_op(i) == ')') {
				check_parent--;
			}
			if (check_parent < 0) {
				std::cout << "Don't put the \")\" before the \"(\".\nPlease enter again: ";
				return true;
			}
		}
	}

	return false;
}