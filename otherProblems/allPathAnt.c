#include <stdio.h>
#define M 4 /* the width of */
typedef struct Point {
	int row;
	int col;
} Point;

typedef struct Path {
	Point arr[2 * M - 1];
	int size;
} Path;

void initPath(Path *pathP) {
	Point initPoint;
	initPoint.row = M - 1;
	initPoint.col = 0;
	pathP->arr[0] = initPoint;
	pathP->size = 1;
}

Path path;


void printBoard(char **board) {
	int row, col;
	for (row = 0; row < M; row++) {
		for (col = 0; col < M; col++) {
			printf("%c", board[row][col]);
		}
		printf("\n");
	}

}

void printPath() {
	int i;
	for (i = 0; i < path.size; i++) {
		printf("(%d, %d)", path.arr[i].row, path.arr[i].col);
	}
	printf("\n\n");
}

int canGoUp(char **board, int row, int col, int start_row, int start_col) {
	if (start_row >= 1 && board[start_row - 1][start_col] != 'X') {
		return 1;
	} else {
		return 0;
	}
}

int canGoRight(char **board, int row, int col, int start_row, int start_col) {
	if (start_col <= col - 2 && board[start_row][start_col + 1] != 'X') {
		return 1;
	} else {
		return 0;
	}
}

void findPathAntRec(char **board, int row, int col, int start_row, int start_col) {
	if (path.size == 2 * M - 1) {
		printPath();
	} else {
		if (canGoUp(board, row, col, start_row, start_col)) {
			path.arr[path.size].row = start_row - 1;
			path.arr[path.size].col = start_col;
			path.size += 1;
			// board[start_row - 1][start_col] = '*';
			findPathAntRec(board, row, col, start_row - 1, start_col);
			// board[start_row - 1][start_col] = ' ';
			path.size -= 1;
		}

		if (canGoRight(board, row, col, start_row, start_col)) {
			path.arr[path.size].row = start_row;
			path.arr[path.size].col = start_col + 1;
			path.size += 1;
			// board[start_row][start_col + 1] = '*';
			findPathAntRec(board, row, col, start_row, start_col + 1);
			// board[start_row][start_col + 1] = ' ';
			path.size -= 1;
		}
	}
}

void findPathAnt(char **board, int row, int col) {
	findPathAntRec(board, row, col, row - 1, 0);
}

int main(int argc, char const *argv[])
{	
	initPath(&path);
	char *board[] = {"OXOO", "OXXX", "OXOO", "OOOO"};
	findPathAnt(board, M, M);
	return 0;
}