#include <iostream>
#include "Sphere.h"
using namespace std;

int main(int argc, char const *argv[])
{
	Sphere unitSphere;
	Sphere mySphere(3.3);
	unitSphere.displayStat();
	cout << endl;
	mySphere.displayStat();
	return 0;
} 