/* convert a prefix string to a posfix string */
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


string convertPreToPost(string s) {
	int n = s.length();
	if (n == 1) {
		return s; 
	} else {
		char op = s[0];
		int endOfFirst = findPreEnd(s, 1);
		string stringFirst = convertPreToPost(s.substr(1, endOfFirst));
		string stringSecond = convertPreToPost(s.substr(endOfFirst + 1));

		return stringFirst + stringSecond + op;
	}
}

int main(int argc, char const *argv[])
{
	string pre = "+*ab+34";
	cout << convertPreToPost(pre) << endl;
	return 0;
}