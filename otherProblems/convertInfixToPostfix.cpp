/* convert infix to postfix 
 * @file: convertInfixToPostfix.cpp */

#include <iostream>
#include <string>
#include <stack>
using namespace std;

const string NUMBERS = "1234567890";
const string OPERATORS = "+-*/";


bool isNum(char ch) {
	for (int i = 0; i < NUMBERS.length(); i++) {
		if (NUMBERS[i] == ch) {
			return true;
		}
	}
	return false;
}

bool isOperator(char ch) {
	for (int i = 0; i < OPERATORS.length(); i++) {
		if (OPERATORS[i] == ch) {
			return true;
		}
	}
	return false;
}

/*determine the precedance of a and b
 *return true if the precedance of a >= b */
bool precedance(char a, char b) { // only consider "+ - * /"
	if (a == '*' || a == '/') {
		return true;
	} else { // a == '+' || '-'
		if (b == '+' || b == '-') {
			return true;
		} else {
			return false;
		}
	}
}

string convertInfixToPostfix(string postStr) {
	stack<char> aStack;
	string res;

	for (int i = 0; i < postStr.length(); i++) {
		char ch = postStr[i];
	
		if (isNum(ch)) {
			res += ch;
		} else if(isOperator(ch)) {
			if (aStack.empty()) {
				aStack.push(ch);
			} else {
				while (!aStack.empty() && (aStack.top() != '(') && precedance(aStack.top(), ch)) {
					cout << aStack.top() << " -> " << ch << endl;
					res += aStack.top();
					aStack.pop();
				}
				// add new operator to stack
				aStack.push(ch);
			} // end of if
		} else if (ch == '(') {
			aStack.push(ch);
		} else { // if ch == ')'
			while(!aStack.empty() && aStack.top() != '(') {
				res += aStack.top();
				aStack.pop();
			}
			aStack.pop(); // remove '('
		}
	}

	// append the remaining operators in the stack
	while (!aStack.empty()) {
		res += aStack.top();
		aStack.pop();
	}
	return res;
}

int main(int argc, char const *argv[])
{
	string infixStr = "(1+2)*3";
	string postStr = convertInfixToPostfix(infixStr);
	cout << postStr << endl;
	return 0;
}