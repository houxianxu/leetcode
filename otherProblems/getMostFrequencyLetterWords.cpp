/*
 * Problem description: Given a  dictionary which contains all English words.  
 * Try to find the max number of words which have the same letters
 * 
 * e.g. the word "bat", "tab" has the same letter
 */

 #include <string>
 #include <fstream>
 #include <iostream>
 #include <map>
 #include <set>
 using namespace std;

void swap(string &s, int i, int j) {
	char tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
}

string signature(string s) { // sort the stirng
 	for (int i = 0; i < s.length(); i++) {
 		int minIndex = i;
 		for (int j = i + 1; j < s.length(); j++) {
 			if (s[j] < s[minIndex]) {
 				minIndex = j;
 			}
 		}
 		swap(s, i, minIndex);
 	}
 	return s;
 }


// read the words file, and store them in a map, 
// whose key is the signature of string, and value is a set of string
 void readFile(ifstream &inFile, map<string, set<string> > &m) {
 	string word;
 	while(true) {

 		inFile >> word; // or using: getline(inFile, word);
 		if (inFile.fail()) {
 			break;
 		} else {
 			m[signature(word)].insert(word);
 		}
 	}
 	cout << "num words " << m.size() << endl;;
 }

int countFrequency(map<string, set<string> > &m) {
	map<string, set<string> >::iterator iter = m.begin();
	map<string, set<string> >::iterator iterEnd = m.end();

	string maxKey;
	string tmpKey;
	int maxSize = 0;
	int tmpSize = 0;
	for (; iter != iterEnd; iter++) {
		tmpKey = iter->first;
		tmpSize = (iter->second).size();
		if (tmpSize > maxSize) {
			maxSize = tmpSize;
			maxKey = tmpKey;
		}
	}
	cout << "max key is " << maxKey << endl;

	// get the words related to maxkey
	set<string>::iterator iterSet = m[maxKey].begin(),
						  iterSetEnd = m[maxKey].end();
	for (; iterSet != iterSetEnd; iterSet++) {
		cout << "word is " << *iterSet << endl;
	}

	return maxSize;
}


 int main(int argc, char const *argv[])
 {	
 	ifstream inFile("words.txt");
 	map<string, set<string> > m;	

 	readFile(inFile, m);

 	cout << "the result is " << countFrequency(m) << endl;

 	return 0;
 	
 }