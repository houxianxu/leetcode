#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &v) {
	for (int i = 1; i < v.size(); i++) {
		int cur = v[i]; // item to insert
		int j = i - 1; // j - 1 is the place to insert
		for (j = i - 1; j >= 0; j--) {
			if (v[j] > cur) {
				v[j + 1] = v[j];
			} else {
				break;
			}
		}
		v[j + 1] = cur;
	}
}

void printVector(vector<int> &arrV) {
	for (int i = 0; i < arrV.size(); i++) {
		cout << arrV[i] << " ";
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	int tmpArr[] = {2, 3, 1, 6, 34, 12};
	vector<int> arrV(tmpArr, tmpArr + 6);
	printVector(arrV);
	insertionSort(arrV);
	printVector(arrV);
	return 0;
}