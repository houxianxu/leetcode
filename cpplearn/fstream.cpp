/*
 *  File: fstream.cpp
 *  ------------------
 * Snippets from the live coding part of Wed 1/16 lecture
 * showing some simple use of fstream.
 */

#include <iostream>
#include <fstream>
using namespace std;


int countlines(ifstream &in) {
	int count = 0;
	while (true) {
		string line;
		getline(in, line);
		if (in.fail()) break;
		count++;
	}	
	return count;
}

int main(int argc, char const *argv[])
{
	ifstream in;
	char s[100];
	cout << "Enter name: ";
	cin.getline(s, 100);
	in.open(s);
	if (in.fail()) {
		cout << "file didn't open";
	}
	cout << "Num lines: " << countlines(in);
	int count = 0;
	return 0;
}

