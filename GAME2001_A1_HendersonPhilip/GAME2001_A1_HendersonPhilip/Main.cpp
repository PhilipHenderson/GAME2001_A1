//-------------------------------------------------------------------------------------------
//	GAME2001:	Assignment 1
//	By:			Philip Henderson
//	Stu #:		101137744
//	Date:		Oct-9-2021
//-------------------------------------------------------------------------------------------
#include <iostream>
#include <cassert>
using namespace std;

#include "Ordered.h"
#include "Unordered.h"

int main()
{
	cout << "Binary Search" << endl;

	BaseArray<int> array(5, 2);

	array.push(45);
	array.push(62);
	array.push(76);
	array.push(98);
	array.push(12);

	cout << "Befor: ";
	for (int i = 0; i < array.GetSize(); i++)
	{
		cout << " " << array[i];
	}
	cout << endl;

	 /*call sort*/


	cout << "After: ";
	for (int i = 0; i < array.GetSize(); i++)
	{
			cout << " " << array[i];
	}

	cout << endl << endl;



	return 0;
}