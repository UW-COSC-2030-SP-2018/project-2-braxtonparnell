// Proj2.cpp 
// Braxton Parnell

#include "stdafx.h"
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

void print(vector<int>);
void quicksort(vector<int>&, int, int);
int binarysearch(vector<int>, int, int, int);
//vector<int> mergesort(vector<int>);
//int hash(int);


int main()
{	
	vector<int> vector1;
	vector1.push_back(8);
	vector1.push_back(4);
	vector1.push_back(0);
	vector1.push_back(10);
	vector1.push_back(9);

	print(vector1);

	quicksort(vector1, 0, vector1.size() - 1);

	print(vector1);

	cout << "4 in vector1? " << binarysearch(vector1, 0, vector1.size() - 1, 10) << endl;
	//cout << "28 in vector1? " << binarysearch(vector1, 0, vector1.size(), 28) << endl;
	//cout << "9 in vector1? " << binarysearch(vector1, 0, vector1.size(), 2) << endl;


    return 0;
}

void print(vector<int> vec) {
	cout << "[";
	for (unsigned int i = 0; i < vec.size(); i++) {
		cout << vec.at(i) << ", ";
	}
	cout << "]" << endl;

}

void quicksort(vector<int> &vec, int l, int r) {
	if (l < r) {
		int pivot = vec.at(l), temp, leftItr = l + 1, rightItr = r;
		while (leftItr != rightItr) {
			if (vec.at(leftItr) <= pivot) {
				leftItr++;
			}
			else {
				while ((leftItr != rightItr) && (pivot < vec.at(rightItr))) {
					rightItr--;
				}
				temp = vec.at(rightItr);
				vec.at(rightItr) = vec.at(leftItr);
				vec.at(leftItr) = temp;
			}
		}

		if (vec.at(leftItr) > pivot)
			leftItr--;
		vec.at(l) = vec.at(leftItr);
		vec.at(leftItr) = pivot;

		quicksort(vec, l, leftItr - 1);
		quicksort(vec, leftItr + 1, r);
	}
	
}

int binarysearch(vector<int> vec,int l, int r, int s) {
	if (r >= 1) {
		int middle = l + (r - 1) / 2;
		if (vec.at(middle) == s) {
			return middle;
		}

		if (vec.at(middle) > s) {
			return binarysearch(vec, l, middle - 1, s);
		}
		return binarysearch(vec, middle + 1, r, s);
	}
	return -1;
}

/*
vector<int> mergesort(vector<int> vec) {
	//if (vec.size() > 1) {
	//	vector<int> l, r;


	//}

	return vector<int>;
}

int hash(int s) {

	return 0;
}
*/
