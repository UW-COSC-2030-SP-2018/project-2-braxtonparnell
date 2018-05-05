// Proj2.cpp 
// Braxton Parnell

#include "stdafx.h"
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

void printvec(vector<int>);
void printarr(int[], int);

void quicksort(vector<int>&, int, int);
int binarysearch(vector<int>, int, int, int);
void mergesort(int [], int, int);
void merge(int [], int l, int m, int r);
//int hash(int);


int main()
{	
	vector<int> vector1;
	vector1.push_back(8);
	vector1.push_back(4);
	vector1.push_back(0);
	vector1.push_back(10);
	vector1.push_back(9);

	cout << "Vector: ";
	printvec(vector1);

	cout << "Using quicksort on vector. ";
	quicksort(vector1, 0, vector1.size() - 1);

	cout << "Sorted vector using quicksort: ";
	printvec(vector1);

	cout << "Location of 8 in vector: (-1 if not in vector)" << binarysearch(vector1, 0, vector1.size() - 1, 8) << endl;
	cout << "Location of 0 in vector: (-1 if not in vector)" << binarysearch(vector1, 0, vector1.size(), 0) << endl;
	cout << "Location of -5 in vector: (-1 if not in vector)" << binarysearch(vector1, 0, vector1.size(), -5) << endl;

	int arr[] = { 5, 29, 46, 12, 0, 7, 5 };

	cout << "Array: ";
	printarr(arr, 7);

	cout << "Using mergesort on array. ";
	mergesort(arr, 0, 7 - 1);

	cout << "Sorted array using mergesort: ";
	printarr(arr, 7);



    return 0;
}

void printarr(int arr[], int size) {
	cout << "[";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ", ";
	}
	cout << "]" << endl;
}


void printvec(vector<int> vec) {
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


void mergesort(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - 1) / 2;

		mergesort(arr, l, m);
		mergesort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
	
}

void merge(int arr[], int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[7], R[7];

	
	//populating temp arrays
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int i = 0; i < n2; i++)
		R[i] = arr[m + 1 + i];

	//merge temp arrays
	int i = 0, j = 0;
	int k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	//copying remaining elements
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}


/*
int hash(int s) {

	return 0;
}
*/

