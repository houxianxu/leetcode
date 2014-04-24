#include <vector>
#include <iostream>
using namespace std;

std:: vector<int> ivec(5);

int ia[5] = {1, 2, 3, 4, 5};

void simpleExample() {
	const int elemSize = 5;
	for (int ix = 0; ix < elemSize; ix++) {
		ivec[ix] = ia[ix];
	}
}

int main(int argc, char const *argv[])
{
	simpleExample();
	for (int i = 0; i < ivec.size(); i++) {
		cout << ivec[i];
	}
	cout << endl;
	return 0;
}