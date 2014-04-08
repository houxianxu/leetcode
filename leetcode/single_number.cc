// http://oj.leetcode.com/problems/single-number/
// implement this without using extra memory
#include <stdio.h>
int c_solution(int A[], int n) {
	int i = 0;
	int res = 0;
	for (i = 0; i < n; i++) {
		res ^=	 A[i];
	}
	return res;
}

class Solution {
public:
    int singleNumber(int A[], int n) {
      return c_solution(A, n);
    }
}; 

int main(int argc, char const *argv[])
{
	int A[] = {1, 0, 1};
	printf("%d\n", c_solution(A, 3));
	return 0;
}