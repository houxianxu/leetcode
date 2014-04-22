#include <iostream>
#include <climits>
using namespace std;

struct StockInfo {
  int left, right, sum;
};

void initStock(StockInfo &stock) {
	stock.left = 0;
	stock.right = 0;
	stock.sum = INT_MIN;
}
void printStock(StockInfo &stock) {
	cout << stock.left << " -> " << stock.right << " = sum " << stock.sum << endl;
}

void transform(int A[], int transA[], int n) { // A, and transA has lenght n
	transA[0] = 0; // we don't use it 
	for (int i = 1; i < n; i++) {
		transA[i] = A[i] - A[i - 1];
	}
}


void findMaxSubArrDP(int arr[], int start, int right, StockInfo &stock) {
	int dpIncludeLast[right - start + 2]; // include the last index element
	int dpAll[right - start + 2]; // used to store the value of the sum
	// base case
	dpIncludeLast[start] = arr[start];
	int lastLeft = start;
	int lastRight = start;
	dpAll[start] = arr[start];
	int allLeft = start;
	int allRight = start;

	for (int i = start + 1; i <= right; i++) {
		// the situation that include the ith element
		int tmpDpIncludeLast = dpIncludeLast[i - 1] + arr[i];
		
		// compare tmpDpIncludeLast, arr[i] and dpAll[i - 1]
		if (tmpDpIncludeLast > arr[i] && tmpDpIncludeLast > dpAll[i - 1]) {
			dpAll[i] = tmpDpIncludeLast;
			dpIncludeLast[i] = tmpDpIncludeLast;
			allLeft = lastLeft;
			allRight = i;
			lastRight = i;
		} else if (arr[i] > tmpDpIncludeLast && arr[i] > dpAll[i - 1]) {
			dpAll[i] = arr[i];
			dpIncludeLast[i] = arr[i];
			allLeft = i;
			allRight = i;
			lastLeft = i;
			lastRight = i;
		} else {
			dpAll[i] = dpAll[i - 1];
			if (tmpDpIncludeLast > arr[i]) {
				dpIncludeLast[i] = tmpDpIncludeLast;
				lastRight = i;
			} else {
				dpIncludeLast[i] = arr[i];
				lastLeft = i;
				lastRight = i;
			}
		}
	}
	stock.left = allLeft;
	stock.right = allRight;
	stock.sum = dpAll[right];
}

void findMaxSubArr(int a[], int n, StockInfo &stock) {
	int arr[n];
	transform(a, arr, n);
	findMaxSubArrDP(arr, 1, n - 1, stock); // don't use the first one
}

int main(int argc, char const *argv[])
{
	StockInfo stock;
	initStock(stock);
	int c_A [] = {9, 1, 4, 5, 2, 11, 23, 3};
	int n = 8;

	findMaxSubArr(c_A, n, stock);
	printStock(stock);
	return 0;
}