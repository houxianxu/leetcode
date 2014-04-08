#include <stdio.h>
#define M 8





void eightQueensRec(int col) {
	if (col >= M) {
		printPath(path);
	} else {
		int row = 0;
		for (row = 0; row < M; row++) {
			if (!isConflict(path, i, j)) {
				addToPath(path, i, j);
				eightQueensRec(col + 1);
				popFromPath(path, i, j);
			}
		}
	}
}

void eightQueens() {
	eightQueensRec(0);
}

