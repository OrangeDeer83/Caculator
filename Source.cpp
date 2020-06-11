#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include "Stack.h"
#include "LinkedList.h"
using namespace std;

enum State {space, digit, dot};
int Priority(char op);
void toPostfix(LinkedList* infix, LinkedList* postfix);
double eval(LinkedList* postfix);

int main(void) {
	string enter;
	LinkedList infix, postfix;
	double temp = 0;
	int state = space, dot_time = -1;
	bool bug = false;

	std::cout << "Enter the formula: ";
	do {
		if (bug) {
			cout << "\n";
		}
		getline(cin, enter);
		enter += ' ';
		/*put the fomula into the linkedlist of infix*/
		for (int i = 0; i < enter.length(); i++) {
			if (enter[i] != ' ') {
				if (enter[i] == '.') {
					state = dot;
				}
				else if (isdigit(enter[i])) {
					switch (state) {
					case space:
						temp = 0;
						temp += enter[i] - '0';
						state = digit;
						break;
					case digit:
						temp *= 10;
						temp += enter[i] - '0';
						break;
					case dot:
						temp += (enter[i] - '0') * pow(10, dot_time);
						dot_time -= 1;
						break;
					default:
						break;
					}
				}
				else {
					infix.add(enter[i]);
					continue;
				}
			}
			else if (enter[i] == ' ' && (state == digit || state == dot)) {
				infix.add(temp);
				temp = 0;
				dot_time = -1;
				state = space;
			}
		}
	} while (bug = infix.Debug());

	/*infix to postfix*/
	toPostfix(&infix, &postfix);
	
	

	/*print the result*/
	cout << " = " << eval(&postfix);

	system("PAUSE");
	return 0;
}

/*the priority of operator*/
int Priority(char op) {
	switch (op)
	{
	case'^':
		return 3;
	case'%':
	case'*':
	case'/':
		return 2;
	case'+':
	case'-':
		return 1;
	default:
		return 0;
	}
	exit(1);
}

void toPostfix(LinkedList* infix, LinkedList* postfix) {
	Stack stack;
	for (int i = 0; i < (*infix).getSize(); i++) {
		if (infix->IsOp(i)) {
			switch (infix->get_op(i)) {
			case'(':
				stack.push(infix->get_op(i));
				break;
			case'^':
			case'%':
			case'*':
			case'/':
			case'+':
			case'-':
				while (Priority(infix->get_op(i)) < Priority(stack.get_top_op())) {
					postfix->add(stack.pop_op());
				}
				stack.push(infix->get_op(i));
				break;
			case')':
				while (stack.get_top_op() != '(') {
					postfix->add(stack.pop_op());
				}
				stack.pop_op();
				break;
			default:
				break;
			}
		}
		else {
			postfix->add(infix->get_num(i));
		}
	}
	while (stack.get_top_op() != NULL) {
		postfix->add(stack.pop_op());
	}
}

double eval(LinkedList* postfix) {
	Stack stack;
	double temp;
	for (int i = 0; i < postfix->getSize(); i++) {
		if (postfix->IsOp(i)) {
			switch (postfix->get_op(i)) {
			case'+':
				stack.push((stack.pop_num() + stack.pop_num()));
				break;
			case'-':
				stack.push((stack.pop_num() - stack.pop_num()));
				break;
			case'*':
				stack.push((stack.pop_num() * stack.pop_num()));
				break;
			case'/':
				temp = stack.pop_num();
				stack.push(stack.pop_num() / temp);
				break;
			case'%':
				temp = stack.pop_num();
				stack.push((double)((int)stack.pop_num() % (int)temp));
				break;
			case'^':
				temp = stack.pop_num();
				stack.push(pow(stack.pop_num(), temp));
				break;
			default:
				break;
			}
		}
		else{
			stack.push(postfix->get_num(i));
		}
	}

	return stack.pop_num();
}