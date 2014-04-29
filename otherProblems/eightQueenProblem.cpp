#include <string>
#include <iostream>
#include <vector>
using namespace std;
const int NUM_QUEENS = 8;




void placeQueen(bool board[][NUM_QUEENS], int row, int col) {
	board[row][col] = true;
}

void removeQueen(bool board[][NUM_QUEENS], int row, int col) {
	board[row][col] = false;
}

bool isSafeRow(bool board[][NUM_QUEENS], int row, int col) {
	for (int tmpCol = 0; tmpCol < col; tmpCol++) {
		if (board[row][tmpCol] == true) {
			return false;
		}
	}
	return true;
}

bool isSafeLowerDiag(bool board[][NUM_QUEENS], int row, int col) { // Southwest direction
	for (int tmpRow = row, tmpCol = col; tmpRow < NUM_QUEENS && tmpCol >= 0; tmpRow++, tmpCol--) {
		if (board[tmpRow][tmpCol] == true) {
			return false;
		}
	}
	return true;
}

bool isSafeUpperDiag(bool board[][NUM_QUEENS], int row, int col) { // Northwest direction
	for (int tmpRow = row, tmpCol = col; tmpRow >=0 && tmpCol >=0; tmpRow--, tmpCol--) {
		if (board[tmpRow][tmpCol] == true) {
			return false;
		}
	}
	return true;
}
/* Function: isSafe
 * -----------------
 * indicate whether a new postion is safe or not */
 bool isSafe(bool board[][NUM_QUEENS], int row, int col) {
 	return isSafeRow(board, row, col) &&
 		   isSafeLowerDiag(board, row, col) &&
 		   isSafeUpperDiag(board, row, col);
 }



void displayBoard(bool board[][NUM_QUEENS]) {
	for (int row = 0; row < NUM_QUEENS; row++) {
		for (int col = 0; col < NUM_QUEENS; col++) {
			if (board[row][col] == true) {
				cout << 'Q';
			} else {
				cout << '*';
			}
		}
		cout << endl;
	}
}


/* Function: solve 
 * ----------------
 * @param: board -- partially filled board
 * 		   col -- the column trying to fill in
 * @return: true if the col is suit for placing a queen
 * starting call to solve has an empty board -- all set to false
 * and col == 0, solve(board, 0) */

int sum = 0;
bool solve(bool board[][NUM_QUEENS], int col) {
	if (col >= NUM_QUEENS) {
		sum += 1;
		cout << sum << endl;
		displayBoard(board);
		cout << endl;
		return true;
	}
	for (int row = 0; row < NUM_QUEENS; row++) {
		if (isSafe(board, row, col)) {
			placeQueen(board, row, col); // indicate placing queen at board[row][col]
			solve(board, col + 1);
			removeQueen(board, row, col);
		}
	}
	return false;
}





void clearBoard(bool board[][NUM_QUEENS]) {
	for (int i = 0; i < NUM_QUEENS; i++) {
		for (int j = 0; j < NUM_QUEENS; j++) {
			board[i][j] = false;
		}
	}
}

int main(int argc, char const *argv[])
{	
	bool board[NUM_QUEENS][NUM_QUEENS] = {false};
	// clear the board, every cell set to false means no queens
	clearBoard(board);
	solve(board, 0);
}