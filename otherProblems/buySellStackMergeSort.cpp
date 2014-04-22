

#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct StockInfo {
  int left, right, sum;
};

void initStock(StockInfo &stock) {
	stock.left = 0;
	stock.right = 0;
	stock.sum = 0;
}

void printStock(StockInfo &stock) {
	cout << stock.left << " -> " << stock.right << " = sum " << stock.sum << endl;
}

void maxSumCrossMerge(int A[], int left, int mid, int right, StockInfo &stock) { // assume left part and right part is sorted
	// compute the largest pair
	int tmpSum = A[right] - A[left];
	if (tmpSum > stock.sum) {
		stock.sum = tmpSum;
		stock.left = A[left]; /* can't use this because the the item has sorted*/
		stock.right = A[right];   /*can't use this because the the item has sorted*/
	}
	// sort
	int tmpArr[right - left + 1];
	int k = 0; // the index of tmpArr
	int i = left;
	int j = mid + 1;
	while (i <= mid && j <= right) {
		if (A[i] < A[j]) {
			tmpArr[k] = A[i];
			i += 1;
			k += 1;
		} else {
			tmpArr[k] = A[j];
			j += 1;
			k += 1;
		}
	}
	while (i <= mid) {
		tmpArr[k] = A[i];
		i += 1;
		k += 1;
	}
	while (j <= right) {
		tmpArr[k] = A[j];
		j += 1;
		k += 1;
	}
	i = left;
	for (k = 0; k < (right - left + 1); k++) {
		A[i] = tmpArr[k];
		i += 1;
	}
}

void maxSumByMergeSortRec(int A[], int left, int right, StockInfo &stock){
	if (left >= right) {
		; // do nothing
	} else {
		int mid = (left + right) / 2;
		maxSumByMergeSortRec(A, left, mid, stock);
		maxSumByMergeSortRec(A, mid + 1, right, stock);
		maxSumCrossMerge(A, left, mid, right, stock);
	}
}

void maxSumByMergeSort(int A[], int n, StockInfo &stock) {
	if (n == 1) {
		; // do nothing
	} else {
		maxSumByMergeSortRec(A, 0, n - 1, stock);
	}
}

// store the value in arr as key, and the index as value
void arrInverseToMap(int arr[], int n, map<int, vector<int> > &m) {
	for (int i = 0; i < n; i++) {
		m[arr[i]].push_back(i);
	}
}

void getIndexofLeftAndRight(map<int, vector<int> > &m, StockInfo &stock) {
	if (stock.sum > 0) {
		vector<int> leftIndex = m[stock.left];
		vector<int> rightIndex = m[stock.right];	
		for (int i = 0; i < leftIndex.size(); i++) {
			for (int j = 0; j < rightIndex.size(); j++) {
				if (leftIndex[i] < rightIndex[j]) {
					stock.left = leftIndex[i];
					stock.right = rightIndex[j];
					return;
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	StockInfo stock;
	initStock(stock);
	int c_A [] = {9, 1, 4, 5, 2, 11, 23, 3};
	int n = 8;
	map<int, vector<int> > m;
	arrInverseToMap(c_A, n, m);
	maxSumByMergeSort(c_A, 8, stock);
	getIndexofLeftAndRight(m, stock); // change the stock.left and stock.right
	printStock(stock);
	return 0;
}
