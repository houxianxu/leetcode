/* using max sum subarray to solve the stock problem described in the Introduciton to Alogrithm Book */

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


void findMaxSubArrCross(int arr[], int left, int mid, int right, StockInfo &stock) {
	int tmpSum = 0;
	int leftMaxSum = INT_MIN;
	int maxLeft;
	for (int i = mid; i >= left; i--) {
		tmpSum += arr[i];
		if (tmpSum > leftMaxSum) {
			leftMaxSum = tmpSum;
			maxLeft = i;
		}
	}
	tmpSum = 0;
	int rightMaxSum = INT_MIN;
	int maxRight;
	for (int i = mid + 1; i <= right; i++) {
		tmpSum += arr[i];
		if (tmpSum > rightMaxSum) {
			rightMaxSum = tmpSum;
			maxRight = i;
		}
	}
	if (leftMaxSum + rightMaxSum > stock.sum) {
		stock.sum = leftMaxSum + rightMaxSum;
		stock.left = maxLeft - 1; // count from the maxLeft - 1
		stock.right = maxRight;
	}
}


// divide and conquer
void findMaxSubArrRec(int arr[], int left, int right, StockInfo &stock) {
	if (left == right) {
		stock.left = left;
		stock.right = right;
		stock.sum = arr[left];
	} else {
		int mid = (left + right) / 2;
		findMaxSubArrRec(arr, left, mid, stock);
		findMaxSubArrRec(arr, mid + 1, right, stock);
		findMaxSubArrCross(arr, left, mid, right, stock);
	}
}


void findMaxSubArr(int a[], int n, StockInfo &stock) {
	int arr[n];
	transform(a, arr, n);
	findMaxSubArrRec(arr, 1, n - 1, stock); // don't use the first one
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
