#include "location.h"
#include <iostream>
using namespace std;
// using namespace location;

int main(int argc, char const *argv[])
{
	Location loc(10, 5); // allocate object on stack		
	loc.translate(9, -3);

	cout << loc.getX() << ", " << loc.getY() << endl;

	Location *lp = new Location(0, 0); // allocate object dynamically in the heap using pointers
	lp->translate(1, 2);
	cout << lp->getX() << ", " << lp->getY() << endl;
	delete lp;

	return 0;
}