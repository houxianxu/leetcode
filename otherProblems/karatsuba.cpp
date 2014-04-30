#include <iostream>
#include <cmath>
using namespace std;



int digitsNumOfInt(int x) {
	if (x == 0) {
		return 1;
	} else {
		return ceil(log10(x));
	}
}

int karatsuba(int x, int y) {
	// get the smaller input's number of digits
	int digits = digitsNumOfInt(min(x, y));

	if (digits == 1) {
		return x * y; // naive multiply
	} else { // divide the inputs in to two parts using digits
		int dividePow = pow(10, digits / 2);

		// divide the x
		int a = x / dividePow;
		int b = x % dividePow;

		// digits the y
		int c = y / dividePow;
		int d = y % dividePow;

		int ac = karatsuba(a, c);
		int bd = karatsuba(b, d);
		int ab_cd = karatsuba(a+b, c+d);
		int ad_plus_bc = ab_cd - ac - bd;

		return pow(10, digits) * ac + pow(10, digits / 2) + bd;

	}


}

int main(int argc, char const *argv[])
{
	cout << karatsuba(234, 2343) << endl;
	cout << pow(2, 32) << endl;
	return 0;
}

/* More infor can be found https://github.com/morazow/Coursera-Algorithms/blob/c3071f1d74f99fc9c473451a3dd7d61d753a6265/Karatsuba/karatsuba.cpp
*/