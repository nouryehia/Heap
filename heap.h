//Includes.
#include <iostream>
#include <fstream>
#include <cstring>
#include <math.h>

using namespace std;

//Define the max size of the heap.
#define SIZE 100

//If undefined.
#ifndef STACK_H
#define STACK_H

class heap{
protected:

	//Declare variables.
	int maxHeap[SIZE];
	int size;
public:

	//Declare functions.
	heap();
	void add(int);
	void heapify(int);
	void printTree();
	int rowNum();
	int extraDigits(int);
	void printList();
	int remove();
};
#endif

//Constructor.
heap::heap(){
	size = 0;
}

//Adds an element from a list to the heap.
void heap::add(int element){
	int child = size;
	int parent = (child - 1)/2;
	int temp;
	maxHeap[size] = element;
	size ++;
	while (child != 0 && maxHeap[parent] < maxHeap[child]){
		temp = maxHeap[child];
		maxHeap[child] = maxHeap[parent];
		maxHeap[parent] = temp;
		child = parent;
		parent = (child - 1)/2;
	}
}

//Provides a visual representation of the heap.
void heap::printTree(){
	int row = rowNum();
	int numPerRow = 1;
	int c = 0;
	cout << "\nVisual representation of max heap created:\n\n";
	for (int i = 0; i < rowNum(); i++){
		for (int i = 0; i < pow(2, row) -1; i++) cout << " ";
		for (int i = 0; i < numPerRow; i++) {
			if (maxHeap[c]){
				cout << maxHeap[c];
				c++;
				for (int n = 0; n < ((pow(2, (row+1))-1) - extraDigits(maxHeap[c-1])); n++) cout << " ";
			}
		}
		numPerRow = 2 * numPerRow;
		row--;
		cout << endl;
	}
}

//Returns the number of rows that the heap should have (used by printTree()).
int heap::rowNum() {
	if (size <= 1) return 1;
	if (size > 1 && size <= 3) return 2;
	if (size > 3 && size <= 7) return 3;
	if (size > 7 && size <= 15) return 4;
	if (size > 15 && size <= 31) return 5;
	if (size > 31 && size <= 63) return 6;
	if (size > 63) return 7;
	return 0;
}

/*Returns how many spaces should be removed between each number so that the 
  visual representation of the heap is readable (used by printTree()).*/
int heap::extraDigits(int num){
	if (num >= 10 && num < 100) return 1;
	if (num >=100 && num < 1000) return 2;
	if (num == 1000) return 3;
	return 0;
}

//Prints out the heap to sort out the list from largest to smallest. 
void heap::printList(){
	cout << "\n\nSorted list:\n\n";
	while (size !=0){
		int i = remove();
		if (size == 0) cout << i << ".";
		else cout << i << ", ";
	}
	cout << endl << endl;
}

//Removes a node from the heap (used by printList()). 
int heap::remove(){
	int toRemove = maxHeap[0];
	maxHeap[0] = maxHeap[size];
	size--;
	heapify(0);
	return toRemove;
}

//Sorts the heap so that every node is larger than its child (used by remove()).
void heap::heapify(int root){
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	int largest = root;
	int temp;
	if (left <= size && maxHeap[left] > maxHeap[largest]) largest = left;
	if (right <= size && maxHeap[right] > maxHeap[largest]) largest = right;
	if (largest != root){
		temp = maxHeap[root];
		maxHeap[root] = maxHeap[largest];
		maxHeap[largest] = temp; 
		heapify(largest);
	}
}