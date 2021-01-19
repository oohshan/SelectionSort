/* Selection Sort
* Sorts an array by repeatedly finding the minimum (or max depending on direction) element from the unsorted section and placing it a the beginning.
* Time Complexity: O(n^2) - this is because there are two nested loops 
*/

#include <iostream>
#include <time.h>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int* xp, int* yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

vector<int> selectionSort(vector<int> arr, int n) {
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray  
	for (i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array  
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr.at(j) < arr.at(min_idx))
				min_idx = j;
		// Swap the found minimum element with the first element
		// iter_swap(arr.begin() + min_idx, arr.begin() + i);
		swap(&arr.at(min_idx), &arr.at(i));
		
	}

	return arr;
}

/* Function to print an array */
void printDynArray(vector<int> arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr.at(i) << " ";
	cout << endl;
}

int main()
{
	vector<int> dynArr;

	srand((unsigned)time(NULL));

	int numElements = 0;
	cout << "Please enter the number of elements: ";
	cin >> numElements;
	cout << endl;

	cout << "Unsorted Array \n";
	// Build array with random values
	for (int i = 0; i < numElements; ++i) {
		dynArr.push_back(rand() % 100 + 1);
		cout << dynArr.at(i) << " ";
	}

	int n = dynArr.size();

	vector<int> sortedDynArr = selectionSort(dynArr, n);
	cout << endl << "Sorted array: \n";
	printDynArray(sortedDynArr, n);
}
