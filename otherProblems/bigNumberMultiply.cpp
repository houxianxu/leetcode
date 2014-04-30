/* Big number multiplication 
 * @file bigNumberMultiply */

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/* 大数乘法基本思想：将大数以字符串的形式存放，
 * 根据乘法准则,把每次单个相乘的结果累加到对应位置上，最后对>=9的数进行进位处理.
 * Function: bigNumMulti(string &s1, string &s2)
 * Return: string */
 string bigNumMulti(string &s1, string &s2) {
 	int n1 = s1.length();
 	int n2 = s2.length();
 	int n = n1 + n2;

 	// restore the result and the total number of digit should be n or n - 1
 	int res[n];
 	for (int i = 0; i < n; i++) {
 		res[i] = 0;
 	}

 	int k = n; // index of res
 	int tmpK = k;

 	for (int i = n2 - 1; i >= 0; i--) {
 		k -= 1;
 		tmpK = k;

 		for (int j = n1 - 1; j >= 0; j--) {
 			int tmpMulti = (s2[i] - '0') * (s1[j] - '0');
 			res[tmpK] += tmpMulti;
 			tmpK -= 1;
 		}
 	}

 	// change the res[i], if the res[i] >= 10 i.e. 进位
 	for (int i = n - 1; i >= 0; i--) {
 		if (res[i] >= 10) {
 			res[i - 1] += res[i] / 10;
 			res[i] = res[i] % 10;
 		}
 	}


 	// store the result in a string
 	stringstream ss;
 	for (int i = 0; i < n; i++) {
 		ss << res[i];
 	}

 	string resultStr = ss.str();
 	return resultStr;
 }

 int main(int argc, char const *argv[])
 {
 	string s1 = "19";
 	string s2 = "19";

 	cout << bigNumMulti(s1, s2) << endl;
 	return 0;
 }

