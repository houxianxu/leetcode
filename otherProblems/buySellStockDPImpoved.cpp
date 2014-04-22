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
	// init
	int sumLast = start; // the max sum include last item;
	int allLeft = start;
	int allRight = start;
	int maxIncludeLast = arr[start];
	int leftIncludeLast = start;
	int maxAll = arr[start];

	for (int i = start + 1; i <= right; i++) {
		// deal with include the i item
		if (sumLast < 0) {
			sumLast = arr[i];
			leftIncludeLast = i;
		} else {
			sumLast += arr[i];
		}

		if (sumLast > maxAll) {
			maxAll = sumLast;
			allLeft = leftIncludeLast;
			allRight = i;
		}
	}
	stock.left = allLeft;
	stock.right = allRight;
	stock.sum = maxAll;
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