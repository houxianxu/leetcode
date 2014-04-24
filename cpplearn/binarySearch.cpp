#include <cstdio>

// int binarySearchRec(int arr[], int start, int end, int x) {
// 	printf("%s\n", "aa");
// 	if (start > end) {
// 		return -1;
// 	} else if(start == end && arr[start] != x) {
// 		return -1;
// 	} else {
// 		int mid;
// 		mid = (start + end) / 2;
// 		if (arr[mid] == x) {
// 			return mid;
// 		} else if(x < arr[mid]) {
// 			return binarySearchRec(arr, start, mid, x);
// 		} else {
// 			return binarySearchRec(arr, mid, end, x);
// 		}
// 	}
// }

// int binarySearch(int arr[], int n, int x) { // assume the arr[] is sorted, find whether x is in arr[]
// 	if (n == 0) {
// 		return -1;
// 	} else if (n == 1 && arr[0] == x) {
// 		return 1;
// 	} else {
// 		return binarySearchRec(arr, 0, n-1, x);
// 	}
// }



// void binarySearchReclowest(int arr[], int start, int end, int x, int *lowP) {
// 	// printf("%s %s %d %d \n", "start", "end", start, end);
// 	if (start == end) {
// 		if (arr[start] == x) {
// 			*lowP = start;
// 		}

// 	} else {
// 		int mid;
// 		mid = (start + end) / 2;
// 		if (x < arr[mid]) {
// 			binarySearchReclowest(arr, start, mid, x, lowP);
// 		} else if (x > arr[mid]) {
// 			binarySearchReclowest(arr, mid + 1, end, x, lowP);
// 		} else { // x == arr[mid];
// 			*lowP = mid;
// 			binarySearchReclowest(arr, start, mid, x, lowP);
// 		}
// 	}
// }

// void binarySearchRechighest(int arr[], int start, int end, int x, int *highP) {
// 	// printf("%s %s %d %d \n", "start", "end", start, end);
// 	if (start == end) {
// 		if (arr[end] == x) {
// 			*highP = end;
// 		}
// 	} else {
// 		int mid;
// 		mid = (start + end) / 2;
// 		if (x < arr[mid]) {
// 			binarySearchRechighest(arr, start, mid, x, highP);
// 		} else if (x > arr[mid]) {
// 			binarySearchRechighest(arr, mid + 1, end, x, highP);
// 		} else {
// 			*highP = mid;
// 			binarySearchRechighest(arr, mid + 1, end, x, highP);
// 		}
// 	}
// }

// int binarySearchNum(int arr[], int n, int x) {
// 	if (n == 0) {
// 		return 0;
// 	} else if (n == 1) {
// 		if (arr[0] == x) {
// 			return 1;
// 		} else {
// 			return 0;
// 		}
// 	} else {
// 		int low = -1;
// 		int high = -1;
// 		binarySearchReclowest(arr, 0, n - 1, x, &low);
// 		binarySearchRechighest(arr, 0, n - 1, x, &high);
// 		// printf("%s %s %d %d \n", "low", "high", low, high);
// 		if (low >= 0 && high >= 0) {
// 			return high - low + 1;
// 		} else {
// 			return 0;
// 		}
		
// 	}

// }

int binarySearchReclowest(int arr[], int start, int end, int x) {
	// printf("%s %s %d %d \n", "start", "end", start, end);
	if (start == end) {
		if (arr[start] == x) {
			return start;
		}

	} else {
		int mid;
		mid = (start + end) / 2;
		if (x < arr[mid]) {
			return binarySearchReclowest(arr, start, mid, x);
		} else if (x > arr[mid]) {
			return binarySearchReclowest(arr, mid + 1, end, x);
		} else { // x == arr[mid];
			return binarySearchReclowest(arr, start, mid, x);
		}
	}

	return -1;
}

int binarySearchRechighest(int arr[], int start, int end, int x) {
	// printf("%s %s %d %d \n", "start", "end", start, end);
	if (start == end) {
		if (arr[end] == x) {
			return end;
		}
	} else {
		int mid;
		mid = (start + end) / 2;
		if (x < arr[mid]) {
			return binarySearchRechighest(arr, start, mid, x);
		} else if (x > arr[mid]) {
			return binarySearchRechighest(arr, mid + 1, end, x);
		} else {
			if (arr[mid + 1] == x) {
				return binarySearchRechighest(arr, mid + 1, end, x);
			} else {
				return mid;
			}
		}
	}

	return -1;
}

int binarySearchNum(int arr[], int n, int x) {
	if (n == 0) {
		return 0;
	} else if (n == 1) {
		if (arr[0] == x) {
			return 1;
		} else {
			return 0;
		}
	} else {
		int low = -1;
		int high = -1;
		low = binarySearchReclowest(arr, 0, n - 1, x);
		high = binarySearchRechighest(arr, 0, n - 1, x);
		// printf("%s %s %d %d \n", "low", "high", low, high);
		if (low >= 0 && high >= 0) {
			return high - low + 1;
		} else {
			return 0;
		}
		
	}

}



int main(int argc, char const *argv[])
{
	// int arr[2] = {1,2};

	int arr[2] = {2, 2};
	printf("%d\n", binarySearchNum(arr, 2, 2));
	printf("%d\n", binarySearchNum(arr, 2, 0));
	printf("%d\n", binarySearchNum(arr, 2, 4));
	printf("%d\n", binarySearchNum(arr, 2, 1));

	return 0;
}