#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <stack>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
    	string res = "";
        for (int i = s.size() - 1; i >= 0; i--) {
        	while (s[i] == ' ' && i >= 0) {
        		i--;
        	}
        	string word;
        	while (s[i] != ' ' && i >= 0) {
        		word.push_back(s[i]);
        		i--;
        	}
        	if (word.size() > 0) {

	        	if (!res.empty()) {
	        		res.push_back(' ');
	        	}

	        	reverse(word.begin(), word.end());
	        	res += word;
     	   }
        }
        s = res;
    }

    // also we can us sstream
    void reverseWords1(string &s) {
    	stack<string> stackWord;
    	string word;
    	stringstream ss(s);
    	while(ss >> word) {
    		stackWord.push(word);
    	}
    	s = "";
    	while(!stackWord.empty()) {
    		s += stackWord.top();
    		stackWord.pop();
    		if (stackWord.empty()) {
    			break;
    		} else {
    			s += " ";
    		}
    	}
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	string s = " hou 23 kjf  ";
	solution.reverseWords1(s);
	cout << s << endl;
	return 0;
}