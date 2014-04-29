#include <iostream>
#include <string>
using namespace std;


/* print out all the strings, which soFar concatenate the permutation of rest*/
void permuteRec(string soFar, string rest) {
	if (rest == "") { // no letter to permute
		cout << soFar << endl;
	} else {
		for (int i = 0; i < rest.length(); i++) {
			string next = soFar + rest[i];
			string remaining = rest.substr(0, i) + rest.substr(i + 1);
			permuteRec(next, remaining);
			// cout << i<< " -> " << soFar << endl;
		}
	}
}

// wrapped function
/* print out all the permutation of a string
 * @param string s 
 * @return none */
void permutationString(string s) {
	permuteRec("", s);
}

int main(int argc, char const *argv[])
{
	string testString = "abcd";
	permutationString(testString);
	return 0;
}