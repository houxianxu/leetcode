/* 括号匹配问题 {}
 * @file matchBracket.cpp */

#include <iostream>
#include <string>
#include <stack>
using namespace std;

/* Function: isMatch(string s) 
 * @param: a string 
 * @return: true if the bracket matches, other false */
bool isMatch(string s) {
	bool soFar = true;
	stack<char> astack;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '{') {
			astack.push(s[i]);
		} else if (s[i] == '}') {
			if (!astack.empty()) {
				astack.pop();
			} else {
				return false;
			}
		} // else do nothing 
	}
	return astack.empty() ?  true : false;
}

int main(int argc, char const *argv[])
{
	string s = "{{{{{}}}}}}";
	if (isMatch(s)) {
		cout << "match" << endl;
	} else {
		cout << "does not match" << endl;
	}
	return 0;
}

