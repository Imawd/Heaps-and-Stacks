#include <vector>
#include <iostream>
#include "stack.h"

using namespace std;

int main () {
	Stack<int> stack;
	for (int i = 0; i < 20; i++) {
		stack.push(i);
		cout << stack.top() << " ";
	}
	cout << endl << "Stack size: " << stack.size() << endl;
	while (!stack.empty()) {
		stack.pop();
		cout << stack.top() << " ";
	}

	cout << endl;

	stack.pop();
	
}

