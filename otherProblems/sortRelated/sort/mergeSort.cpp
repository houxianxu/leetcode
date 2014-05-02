/* Merge sort implementation, sort an array of int
 * @file mergeSort.cpp */
#include <iostream>
using namespace std;


void merge(int arr[], int left, int mid, int right) { // left part and right part are sorted
	int i =  left;
	int j = mid + 1;
	int res[right - left + 1]; // store the result
	int k = 0; // index of res
	while (i <= mid && j <= right) {
		if (arr[i] < arr[j]) {
			res[k] = arr[i];
			k++;
			i++;
		} else {
			res[k] = arr[j];
			k++;
			j++;
		}
	}

	while (i <= mid) {
		res[k] =arr[i];
		i++;
		k++;
	}

	while (j <= right) {
		res[k] =arr[j];
		j++;
		k++;
	}

	// copy the res to arr to complete sort
	k = 0;
	for (i = left; i <= right; i++) {
		arr[i] = res[k];
		k++;
	}
}

void mergeSortRec(int arr[], int left, int right) {
	if (left >= right) {
		// do nothing
	} else {
		int mid = (left + right) / 2;
		mergeSortRec(arr, left, mid);
		mergeSortRec(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}


void mergeSort(int arr[], int n) {
	mergeSortRec(arr, 0, n - 1);
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i];
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	int arr[] = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int n = 10;

	printArray(arr, n);
	mergeSort(arr, n);
	printArray(arr, n);
	return 0;
}