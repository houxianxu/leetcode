#include <iostream>
#include <string>
using namespace std;

void subSetsRec(string soFar, string rest) {
	if (rest == "") {
		cout << soFar << endl;
	} else {
		// smaller problem -- include the first item in the rest
		subSetsRec(soFar + rest[0], rest.substr(1));
		// another samller problem -- do noti include the first item in the rest
		subSetsRec(soFar, rest.substr(1));
	}
}

// wraper function
/* print out all the subset of string s
 * @param s type stirng
 * @return none */
void subSets(string s) {
	subSetsRec("", s);
}

int main(int argc, char const *argv[])
{	
	string s ="hou";
	subSets(s);
	return 0;
}