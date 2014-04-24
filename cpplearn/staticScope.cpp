#include <iostream>
using namespace std;
int traceGcd(int v1, int v2) {
	static int depth = 1;
	cout << "depth " << depth++ << endl;
	if (v2 == 0) {
		depth = 1;
		return v1;
	}

	return traceGcd(v2, v1 % v2);
}

int main(int argc, char const *argv[])
{
	traceGcd(100, 50);
	return 0;
}