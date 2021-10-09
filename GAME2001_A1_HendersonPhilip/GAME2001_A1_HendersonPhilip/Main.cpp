//-------------------------------------------------------------------------------------------
//	GAME2001:	Assignment 1
//	By:			Philip Henderson
//	Stu #:		101137744
//	Date:		Oct-8-2021
//-------------------------------------------------------------------------------------------
#include <iostream>
#include <cassert>
using namespace std;

#include "Ordered.h"
#include "Unordered.h"



//create Base Array Class



//create ordered array class
//create unordered array class

int main()
{
	cout << "Reducing the total number of elements by 1. Ignoring the last element." << endl;

	UnorderedArray<int> array(5);

	array.push(80);
	array.push(45);
	array.push(23);
	array.push(12);
	array.push(89);


	cout << "Befor: ";
	for (int i = 0; i < array.GetSize(); i++)
	{
		cout << " " << array[i];
	}
	cout << endl;

	 /*call sort*/
	array.BubbleSort();

	cout << "After: ";
	for (int i = 0; i < array.GetSize(); i++)
	{
			cout << " " << array[i];
	}

	cout << endl << endl;



	return 0;
}