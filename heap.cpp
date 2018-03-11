/* Heap
 * Author: Nour Yehia
 * Date: 2 - 26 - 18
 * This program sorts a list of numbers from largest to smallest by creating a max heap.*/

//Include.
#include "heap.h"

int main(){

	//Declare variables.
	heap heap;
	int element, num;
	char answer[80], fileName[80];

	//Prompt user to manually enter a list or to read a list from a file.
	while (strcmp(answer, "M") != 0 && strcmp(answer, "m") != 0 
		   && strcmp(answer, "F") != 0 && strcmp(answer, "f") != 0){
		cout << "\nThis program sorts a list of numbers from largest to smallest by creating a max heap." << endl
			 << "Enter 'M' to sort a manually entered list." << endl
			 << "Enter 'F' to sort a list from a file.\n\n";
		cin >> answer; 
	}
	//If user wants to manually enter a list...
	if (strcmp(answer, "M") == 0 || strcmp(answer, "m") == 0){

		//Prompt user to enter the number of elements in the list and to enter the list itself.
		cout << "\nHow many numbers are in the list you would like to sort?\n\n";
		cin >> num;
		cout << "\nEnter the list below. Make sure the numbers are separated by a space.\n\n";

		//Add elements of the list to the heap.
		for (int i = 0; i < num; i++){
			cin >> element;
			heap.add(element);
		}
	}

	//If user wants to read a list from a file...
	else if (strcmp(answer, "F") == 0 || strcmp(answer, "f") == 0){
		ifstream inFile;

		//Prompt user for the name of the file.
		cout << "\nWhat is the name of the file you would like to read?\n\n";
		cin >> fileName;
		inFile.open(fileName);
		while (!inFile){
			cout << "\nFile not found. Retype the name of the file you would like to read.\n\n";
			cin >> fileName;
			inFile.open(fileName);
		}

		//Add elements of the list to the heap.
		while (inFile >> element) heap.add(element);
		inFile.close();
	}

	//Display the heap.
	heap.printTree();

	//Display the sorted list.
	heap.printList();
}