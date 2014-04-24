#include <iostream>
using namespace std;


int myRaise(int base, int exp) {
	if (exp == 0) {
		return 1;
	} else {
		return base * myRaise(base, exp - 1);
	}
}

int myRaiseImprove(int base, int exp) {
	if (exp == 0) {
		return 1;
	} else {
		int half = myRaiseImprove(base, exp / 2);
		if (exp % 2 == 0) {
			return half * half;
		} else {
			return base * half * half;
		}
	}
}

bool isPalindrome(string s) {
	if (s.length() <= 1) {
		return true;
	} else {
		return (s[0] == s[s.length() - 1] && isPalindrome(s.substr(1, s.length() - 2)));
	}
}

// Given N things, how many different ways can you choose K of them
// N choose K, written as C(n, k)
int C(int n, int k) { // assume k > 0
	if (n < k) {
		return -1;
	}
	if (n == k) {
		return 1;
	}

	if (k == 1) {
		return n;
	}
	return C(n - 1, k) + C(n - 1, k - 1);
}

int main(int argc, char const *argv[])
{
	cout << myRaise(2, 5) << endl;
	cout << myRaiseImprove(2, 5) << endl;

	cout << isPalindrome("abcba") << endl;

	cout << "C(5, 1)" << C(5, 1) << endl;
	cout << "C(5, 2)" << C(5, 2) << endl;
	cout << "C(5, 3)" << C(5, 3) << endl;
	return 0;
}