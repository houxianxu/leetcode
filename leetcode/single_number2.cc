// http://oj.leetcode.com/problems/single-number-ii/
// implement this without using extra memory

// get bit on the m bit from int n

#include <stdio.h>
int get_bit(int n, int m) { // 0 <= m <= 31
	return (n >> m) & 1;
}

int set_bit_to_one(int n, int m) {
	return (1 << m) | n;
}

int c_solution(int A[], int n) {
	if (n == 1) {
		return A[0];
	} else {
		// store the sum of each bit (the number of one)of all the array
		int num_of_1[32] = {0};
		int i = 0;
		int j = 0;
		for (i = 0; i < n; i++) {
			for (j = 0; j < 32; j++){
				num_of_1[j] += get_bit(A[i], j);
			}
		}
		int res = 0;
		for (i = 0; i < 32; i++) {
			if (num_of_1[i] % 3 != 0) {
				res = set_bit_to_one(res, i);
			}
		}
		return res;
	}
	

}

class Solution {
public:
    int singleNumber(int A[], int n) {
      return c_solution(A, n);
    }
};

int main(int argc, char const *argv[])
{
	int A[] = {1, 2, 1, 1};
	printf("%d\n", c_solution(A, 4));
	return 0;
}