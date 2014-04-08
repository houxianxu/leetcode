// TIME LIMIT ERROR

// http://oj.leetcode.com/problems/palindrome-partitioning-ii/
#include <stdio.h>
#include <string.h>
#include <string>
// #include <math.h>
using std::string;


int is_palindrome(const char *s, int start, int end) {
	if (s[start] == s[end]) {
		if (end - start < 2) {
			return 1;
		} else {
			return is_palindrome(s, start + 1, end - 1);
		}
	} else {
		return 0;
	}

}

int my_min(int a, int b) {
	return a < b ? a : b;
}

int minCutC(const char *s) {	
	int i = 0;
	int j = 0;
	int N = strlen(s);

	if (N == 0) {
		return 0;
	}

	int DP[N];
	for (i = 0; i < N; i++) {
		DP[i] = i;
	}



	for (i = 1; i < N; i++) {
		for (j = 0; j <= i; j++) {
			if (is_palindrome(s, j, i) == 1) {
				if (j == 0) {
					DP[i] = 0;
					break;
				} else {
					DP[i] = my_min(DP[i], DP[j-1] + 1);
				}
			}
		}
	}
	return DP[N - 1];
}


int c_solve(const char *s) {
	return minCutC(s);
}

class Solution {
public:
    int minCut(string s) {
      return c_solve(s.c_str());
    }
};

int main(int argc, const char *argv[])
{
  // const char *ss = "acdcba";
  // if (is_palindrome(ss, 0, strlen(ss) - 1)) {
  // 	printf("%s\n", "aa");
  // } else {
  // 	printf("%s\n", "bb");
  // }


  const char *s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  printf("%d\n", c_solve(s));
  return 0;
}
