/* determine whether a string is a prefix string
 * @file isPrefix.cpp */

#include <iostream>
#include <string>
using namespace std;


bool isOperator(char ch) {
	string operators = "+-*/";
	for (int i = 0; i < 4; i++) {
		if (ch == operators[i]) {
			return true;
		}
	}
	return false;
}

bool isOperand(char ch) {
	string operands = "abcdefghijklmnopqrstuvwxyz1234567890";
	for (int i = 0; i < operands.length(); i++) {
		if (ch == operands[i]) {
			return true;
		}
	}
	return false;
}


bool isPrefixRec(string s, int start, int end) {
	if (start == end) {
		if (isOperand(s[start])) {
			return true;
		} else {
			return false;
		}
	} else { // start < end
		if ((end - start >= 2) && isOperator(s[start])) {
			for (int i = start + 1; i < end; i++)  {
				return isPrefixRec(s, start + 1, i) && isPrefixRec(s, i + 1, end);
			}
		} else {
			return false;
		}
	}
}


/* determine whether a string is prefix string 
 * @param s, type string 
 * @return: if it is a prefix return true, else false */
bool isPrefixBruteForce(string s) {
	int n = s.length();
	return isPrefixRec(s, 0, n - 1);
}



/* Smarter and quicker algorithm 
 * if a prefix expression followed by a string(operands) , not a operators
 * then the prefix expression can be a prefix expression anymore */

/* @findPreEnd: Find the last index of a string which makes a prefix expression, otherwise return -1
 * @param: string s; int start -- the start index of a new prefix
 * @return: int 
 * e.g. give a string "+123", return the index of 2, which is 2 */
int findPreEnd(string s, int start) {
	int n = s.length();
	if (n == 0 || start == n) {
		return -1;
	} else {
		if (isOperand(s[start])) {
			return start;
		}
		if (isOperator(s[start])) {
			int endOfFirst = findPreEnd(s, start + 1);
			if (endOfFirst > -1) { // scan the second prefix expression
				return findPreEnd(s, endOfFirst + 1);
			} else {
				return -1;
			}
		} else {
			return -1;
		}
	}
}

bool isPrefixSmarter(string s) {
	int endOfPre = findPreEnd(s, 0);
	if (endOfPre == s.length() - 1) {
		return true;
	} else {
		return false;
	}
}


int opCompute(char op, int x, int y) {
	if (op == '+') { return x + y; }
	if (op == '-') { return x - y; }
	if (op == '*') { return x * y; }
	if (op == '/') { return x / y; }
	
}

/* Calculate the prefix expression */
int computePrefix(string s) { // s is a prefix
	int n = s.length();
	if (n == 1) {
		return s[0] - '0'; // convert from char to int 
	} else {
		char op = s[0];
		int endOfFirst = findPreEnd(s, 1);
		int operandFirst = computePrefix(s.substr(1, endOfFirst));
		int operandSecond = computePrefix(s.substr(endOfFirst + 1));

		return opCompute(op, operandFirst, operandSecond);
	}
}


int main(int argc, char const *argv[])
{
	string testStr = "+a+b*ad";

	// cout << isPrefixBruteForce(testStr) << endl;

	// cout << findPreEnd("+2343", 0) << endl;

	// cout << isPrefixSmarter(testStr) << endl;

	cout << computePrefix("++89*12") << endl;

	return 0;
}