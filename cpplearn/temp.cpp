#include <vector>
#include <iostream>
using namespace std;

int main()
{
	string name("111Annadfdfd");
	size_type pos = name.find("Anna");

	if (pos == string::npos) {
		cout << "Anna not found" << endl;
	} else {
		cout << "Anna found at position " << pos << endl;
	}
}
