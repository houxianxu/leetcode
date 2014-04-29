/* @file inverseString.cpp 
 * Problem Description: inversely print out a string
 * using Recursion */

#include <iostream>
#include <string>
using namespace std;

/* inversely print out a string 
 * @param string s
 * return none */
void printInverseString(string s) {
	int length = s.size();

	if (length == 0) {
		// do nothing
	} else { // length > 0
		cout << s[length - 1];
		// smaller problem -- delete the last one
		printInverseString(s.substr(0, length - 1)); 
	} 
} // end of printInverseString

void printInverseString1(string s) {
	int length = s.size();

	if (length == 0) {
		// do nothing
	} else {
		// different smaller problem -- delete the first one
		printInverseString1(s.substr(1, length - 1));
		cout << s[0];
	}
}

int main(int argc, char const *argv[])
{
	printInverseString("houxianxu");
	cout << endl;
	printInverseString1("houxianxu");
	return 0;
}

