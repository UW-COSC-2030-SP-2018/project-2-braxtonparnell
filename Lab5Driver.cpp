// Lab5Driver.cpp : Defines the entry point for the console application.
// Braxton Parnell
// COSC 2030

#include "stdafx.h"
//Lab7Driver
#include "Lab5MyStack.h"//change this to .cpp if on mac/linux
//any other includes here
#include "iostream"
#include<string>

using std::cout;
using std::endl;

int main() {
	//TODO: implement and test your functions here

	//system("pause");

	std::string test ("stop");

	cout << "Reverse 'stop'using stringReversal1: " << stringReversal1(test) << endl;
	cout << "Reverse 'stop'using stringReversal2: " << stringReversal2(test) << endl;
	cout << "Reverse 'stop'using stringReversal3: " << stringReversal3(test) << endl;
	cout << "Reverse 'stop'using stringReversal4: " << stringReversal4(test) << endl;

	return 0;
}
