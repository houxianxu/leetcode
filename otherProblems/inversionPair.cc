#include <iostream>
using namespace std;

// the arr form left to mid, and from mid+1 to right are sorted
int countAndMerge(int arr[], int left, int mid, int right) {  
	int tmpArr[right - left + 1];
	int i = left; // index for the left half
	int j = mid + 1;
	int k = 0; // index of tmpArr
	int sum = 0; // the sum of inversion count

	while (i <= mid && j <= right) {
		if (arr[i] > arr[j]) {
			tmpArr[k] = arr[j];
			sum += mid - left + 1; // if the smallest in the left is bigger,
			k += 1;               //  then all the item in the left is bigger then the smallest in the right half
			j += 1;
		} else {
			tmpArr[k] = arr[i];
			k += 1;
			i += 1;
		}
	}

	// complete the inversion count, go on sorting
	while (i <= mid) {
		tmpArr[k] = arr[i];
		k += 1;
		i += 1;
	}

	while (j <= right) {
		tmpArr[k] = arr[j];
		k += 1;
		j += 1;
	}

	// change the arr, make it sorted
	i = left;
	for (k = 0; k < right - left + 1; k++) {
		arr[i] = tmpArr[k];
		i++;
	}

	return sum;

}


int countInversionSortRec(int arr[], int left, int right) {
	if (left >= right) {
		return 0;
	} else {
		int mid = (left + right) / 2;
		int leftCount = countInversionSortRec(arr, left, mid);
		int rightCount = countInversionSortRec(arr, mid + 1, right);
		int midCount = countAndMerge(arr, left, mid, right); 
		return leftCount + rightCount + midCount;
	}


}

int countInversionSort(int arr[], int n) { // count the inversion pairs and sort the arr[]
	if (n == 1 || n == 0) {
		return 0;
	}

	return countInversionSortRec(arr, 0, n - 1);
}

void copyArr(int desArr[], const int originArr[], int n) {
	int i = 0;
	for (i = 0; i < n; i++) {
		desArr[i] = originArr[i];
	}
}

int main()
{	
	// test
	const int arr[]={5,4,3,2,1};

	// don't allow to change the intput, so copy it to another array
	int tmpArr[5];
	copyArr(tmpArr, arr, 5);

	cout << countInversionSort(tmpArr, 5) << endl;
	cout << "arr[0] " << arr[0] << endl;
	cout << "tmpArr[0] " << tmpArr[0] << endl;
}