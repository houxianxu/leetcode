using namespace std;
#include <iostream>

struct StockInfo {
  int left, right, sum;
};

void printStock(StockInfo stock) {
	cout << stock.left << " -> " << stock.right << " = sum " << stock.sum << endl;
}

// using brute force -> O(n^2)
void bruteForce(int A[], int n, StockInfo &stock) {
		if (n <= 1) {
			return;
		} else if (n == 2) {
			int tmpSum = A[1] - A[0];
			if (tmpSum > 0){
				stock.left = 0;
				stock.right = 1;
				stock.sum = tmpSum;
			}
		} else {
			int left = 0;
			int right = 0;
			int sum = 0;

			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					int tmpSum = A[j] - A[i];          
					if (tmpSum > sum) {
						sum = tmpSum;
						left = i;
						right = j;
					}
				}
			}
			cout << sum << endl;
			if (sum > 0 ) {
				stock.left = left;
				stock.right = right;
				stock.sum = sum;
			}
		}
	}

void testBruteForce() {

	int c_A [] = {9, 3, 4, 5, 2, 11, 23, 3};
	int n = 8;
	StockInfo stock;
	bruteForce(c_A, 8, stock);
	printStock(stock);
}

int main(int argc, char const *argv[])
{	
	testBruteForce();	
	return 0;
}