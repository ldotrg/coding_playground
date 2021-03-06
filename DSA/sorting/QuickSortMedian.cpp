// QuickSortMedian.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void selectionSort(int input[], int n) {
	// n is length of our array
	for (int i = 0; i < n - 1; i++) {
		// i points at first number behind "wall"
		int indexOfSmallest = i;
		for (int j = i + 1; j < n; j++) {
			if (input[j] < input[indexOfSmallest]) {
				indexOfSmallest = j;
			}
		}
		// swap
		int temp = input[i];
		input[i] = input[indexOfSmallest];
		input[indexOfSmallest] = temp;
	}
}

int medianOfThree(int input[], int first, int middle, int last) {
	int array[] = { input[first], input[middle], input[last] };
	selectionSort(array, 3);
	if (array[1] == input[first]) {
		return first;
	}
	else if (array[1] == input[middle]) {
		return middle;
	}
	else {
		return last;
	}
}

int partitionMedian(int input[], int from, int to) {
	int indexOfPivot = medianOfThree(input, from, (from + to) / 2, to);
	int pivot = input[indexOfPivot];
	if (indexOfPivot != to) {
		input[indexOfPivot] = input[to];
	}
	int wall = from;
	for (int i = from; i < to; i++) {
		if (input[i] <= pivot) {
			int temp = input[wall];
			input[wall] = input[i];
			input[i] = temp;
			wall++;
		}
	}
	input[to] = input[wall];
	input[wall] = pivot;

	return wall;
}
void quickSortMedian(int input[], int from, int to) {
	if (from < to) {
		int indexOfPivot = partitionMedian(input, from, to);
		quickSortMedian(input, from, indexOfPivot - 1);
		quickSortMedian(input, indexOfPivot + 1, to);
	}
}

// this function can be used for "quickSortAverage call" where you only pass array
// it generates "from" and "to" parameters
void quickSortMedianExecutor(int input[], int n) {
	quickSortMedian(input, 0, n - 1);
}


int main()
{
    return 0;
}

