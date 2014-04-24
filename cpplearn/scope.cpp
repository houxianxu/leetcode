#include <iostream>
using namespace std;

void whileScopeCheck() {
	int outerWhile = 1;
	// int outerWhile =2;
	while (true) {
		int outerWhile1 = 2; // what's the difference here when using outerWhile = 2; 
		cout << "outerWhile-> " << outerWhile << endl;
		break;
	}

	cout << outerWhile1 << endl;
}

int main(int argc, char const *argv[])
{
	whileScopeCheck();
	return 0;
}