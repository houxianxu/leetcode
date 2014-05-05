#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> &arrV, int i, int j) {
	int temp = arrV[i];
	arrV[i] = arrV[j];
	arrV[j] = temp;
}

void selectionSort(vector<int> &arrV) {
	for (int i = 0; i < arrV.size() - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < arrV.size(); j++) {
			if (arrV[j] < arrV[i]) {
				minIndex = j;
			}
		}
		swap(arrV, i, minIndex);
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
	selectionSort(arrV);
	printVector(arrV);
	return 0;
}