// Braxton Parnell
// COSC 2030

#include "Lab5MyStack.h"


#include <string>	
#include "stdafx.h"


//TODO:
// reverses string using a stack
std::string stringReversal1(std::string input) {
	std::string ret;
	std::stack<char> temp;
	for (int i = 0; i < input.length; i++) {
		temp.push(input[i]);
	}
	while (!(temp.empty())) {
		ret.insert(ret.end(),temp.top());
		temp.pop();
	}
	return ret;
}
//TODO:
// reverses string using a vector
std::string stringReversal2(std::string input) {
	std::string ret;
	std::vector<char> temp;

	for (int i = 0; i < input.length; i++) {
		temp.push_back(input[i]);
	}
	while (temp.empty() == false) {
		ret.insert(ret.end(), temp.back());
		temp.pop_back();
	}
	return ret;

}
//TODO:
// reverses string using a list
std::string stringReversal3(std::string input) {
	std::string ret;
	std::list<char> temp;

	for (int i = 0; i < input.length; i++) {
		temp.push_back(input[i]);
	}
	while (temp.empty == false) {
		ret.insert(ret.end(), temp.back());
		temp.pop_back();
	}
	return ret;
}
//TODO:
// reverses string using MyStack
std::string stringReversal4(std::string input) {
	std::string ret;
	MyStack temp;
	for (int i = 0; i < input.length; i++) {
		temp.push(input[i]);
	}
	while (temp.isEmpty() == false) {
		ret.insert(ret.end(), temp.pull());
	}
	return ret;
}


//TODO:
// Returns true if "stack" is empty and true otherwise
bool MyStack::isEmpty() const {
	return myvec.empty();
}

//TODO:
// adds a char to the stack
void MyStack::push(char& c) {
	myvec.push_back(c);
}

//TODO:
// takes char from top of stack, deletes that element and returns it
char MyStack::pull() {
	char temp = myvec.back();
	myvec.pop_back();
	return temp;
}
