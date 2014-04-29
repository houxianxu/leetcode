/* @file solveHanoiTowers*/
#include <iostream>
using namespace std;

/* slove the classic Hanoi Tower problem 
 * using char to represent the the place to hold the disk */
void solveHanoiTowers(int count , char source, char destination, char spare) {
	if (count == 1) {
		cout << "Move disk from place " << source << " to place " << destination << endl;
	} else {
		solveHanoiTowers(count - 1, source, spare, destination);
		solveHanoiTowers(1, source, destination, spare);
		solveHanoiTowers(count - 1, spare, destination, source);
	} // end of if
} // end of solveHanoiTowers

int main(int argc, char const *argv[])
{
	solveHanoiTowers(3, 'A', 'B', 'C');
	return 0;
}