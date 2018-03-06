//MyStack function declarations
// Braxton Parnell
// COSC 2030

#pragma once
#include<string>
#include <stack>
#include <vector>
#include <list>

std::string stringReversal1(std::string input);
std::string stringReversal2(std::string input);
std::string stringReversal3(std::string input);
std::string stringReversal4(std::string input);

class MyStack {
	public:
	bool isEmpty() const;
	void push(char& c);
	char pull();

private:
	std::vector<char> myvec;
};
