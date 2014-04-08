// http://oj.leetcode.com/problems/palindrome-partitioning-ii/
#include <stdio.h>
#include <string.h>
#include <string>
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


void DFS(const char *s, int *res_min, int *count) {

	int i;
	int N = strlen(s);
	// printf("%s %d\n", "N", N);
	if (N == 0) { // the last loop
		if ((*count - 1) < *res_min) {
			*res_min = *count - 1;
		}
	} else {
		for (i = 0; i < N; i++)	{
			if (is_palindrome(s, 0, i) == 1) {
				// printf("%s %d\n", s, *count);
				*count += 1;
				
				DFS(s + i + 1, res_min, count);
				*count -= 1;
			}
		}
	}
}

int minCutC(const char *s) {	
	int res_min = strlen(s) - 1;
	int count = 0;
	DFS(s, &res_min, &count);
	return res_min;
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


  const char *s = "aaaaaaaaaabbbccbbbaaaaaaaaa";
  printf("%d\n", c_solve(s));
  return 0;
}
