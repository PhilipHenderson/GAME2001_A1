#pragma once
#include "BaseArray.h"
#include <cassert>

template<class T>
class UnorderedArray : public BaseArray<T>
{
public:
	// Constructor
	UnorderedArray(int size, int growBy = 1) {}
	// Destructor
	~UnorderedArray() {}
	// Insertion
	// Fast insertion for UnorderedArray -- Big-O is O(1)
	void push(T val)
	{
		assert(m_array != nullptr); // Debugging purposes

		if (m_numElements >= m_maxSize)	// Check if the array has to expand to accommodate the new data.
		{
			BaseArray<T>::Expand();
		}

		// My array has space for a new value. Let's add it!
		m_array[m_numElements] = val;
		m_numElements++;
	}
	// Searching
	// Linear Search
	int search(T val)
	{
		assert(m_array != nullptr);

		// Brute-force Search
		for (int i = 0; i < m_numElements; i++)
		{
			if (m_array[i] == val)
			{
				return i;	// Return the index of where the item is located in the array
			}
		}

		return -1;
	}
	//----------------------------------------Sorting Algorythms----------------------------------------------------------
	// Bubble Sort -- Big O = O(N^2)
	void BubbleSort()
	{
		assert(m_array != nullptr);

		T temp;

		for (int k = m_numElements - 1; k > 0; k--) // Start at the end of the array and moe backwards
		{
			for (int i = 0; i < k; i++) // Compair elements until k is reached
			{
				// Compair 2 adjacent elements
				if (m_array[i] > m_array[i + 1])
				{
					//Swap The Elements
					temp = m_array[i];
					m_array[i] = m_array[i + 1];
					m_array[i + 1] = temp;
				}
			}
		}
	}
	// Selection Sort -- Big O = O(N^2)
	void SelectionSort()
	{
		assert(m_array != nullptr);

		T temp; // For Swapping
		int min = 0; // Hold the index of the current sallest value

		// Lowest position to swap elements into
		for (int k = 0; k < m_numElements; k++)
		{
			min = k; // set the value at index k as a "defualt" minimum value

			// Iterate through the array to find smallest value, 
			for (int i = k + 1; i < m_numElements; i++)
			{
				// Compair the value at the current index vs the current "min" index
				if (m_array[i] < m_array[min])
				{
					// Store the index to the smallest element
					min = i;
				}

			}
			// swap the lower element with the lowest available index
			if (m_array[k] > m_array[min])
			{
				// Swap
				temp = m_array[k];
				m_array[k] = m_array[min];
				m_array[min] = temp;
			}
		}
	}
	// Insertion Sort -- Big O = O(N^2)
	void InsertionSort()
	{
		assert(m_array != nullptr);
		T temp;
		int i = 0;

		for (int k = 1; k < m_numElements; k++) // Iterate through all elements to be sorted
		{
			temp = m_array[k];
			i = k;

			// Shifting of elements if necessayry. Create a space for an element
			// to be inserted in the correct location
			while (i > 0 && m_array[i - 1] >= temp)
			{
				// push elements to the right
				m_array[i] = m_array[i - 1];
				i--;
			}

			// Place the item in temp, into the right location
			m_array[i] = temp;
		}
	}
	// Merge Sort -- Big O = O(N logN)
	void MergeSort()
	{
		assert(m_array != nullptr);

		T* tempArray = new T[m_numElements];
		assert(tempArray != nullptr);

		MergeSort(tempArray, 0, m_numElements - 1);
		delete[] tempArray;
	}
private:
	// Private functions
	// Recursive Merge Sort
	void MergeSort(T* tempArray, int lowerBound, int upperBound)
	{
		// base case
		if (lowerBound == upperBound)
		{
			return;
		}

		// determine the middle of the array
		int mid = (lowerBound + upperBound) >> 1;

		MergeSort(tempArray, lowerBound, mid); // MergeSort the lowerhalf of the array
		MergeSort(tempArray, mid + 1, upperBound); // Merge Sort the Upper Half of the Array

		// Merge
		Merge(tempArray, lowerBound, mid + 1, upperBound);
	}
	void Merge(T* tempArray, int low, int mid, int upper)
	{
		// LowerBound, Mid+1, UpperBound
		int tempLow = low, tempMid = mid - 1;
		int index = 0;

		while (low <= tempMid && mid <= upper)
		{
			// which fo the 2 values are smaller, them move it into the temp array
			if (m_array[low] < m_array[mid])
			{
				tempArray[index++] = m_array[low++]; // Left path loewr value is the lowest
			}
			else
			{
				tempArray[index++] = m_array[mid++]; // Right half lower vlaue is the lowest
			}
		}

		while (low <= tempMid) // clean up lower half
		{
			tempArray[index++] = m_array[low++];
		}
		while (mid <= upper) // Clean up upper half
		{
			tempArray[index++] = m_array[mid++];
		}
		// Place the stroed tempArray into the main array in the correct loctaions
		for (int i = 0; i < upper - tempLow + 1; i++)
		{
			m_array[tempLow + i] = tempArray[i];
		}
	}
private:
	// Private Variables
	T* m_array;			// Pointer to the beginning of the array

	int m_maxSize;		// Maximum size of the array
	int m_growSize;		// Amount the array can grow through expansion
	int m_numElements;	// Number of items currently in my array
};