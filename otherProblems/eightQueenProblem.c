#include <stdio.h>
#define N 8 // N represents the colomns

int queen[N] = {-1}; // 第n列皇后存放的位置 -- 对应的行
int sum = 0;

void print_result() {
	int row = 0;
	int col = 0;
	printf("%d\n", sum	);
	for (row = 0; row < N; row++) {
		for(col = 0; col < N; col++) {
			if (queen[col] == row) {// 放皇后
				printf("%s", " *");
			} else {
				printf("%s", " .");
			}
		}
		printf("\n");
	}
}

int check(int col, int row) { // 判断是否可以把第col对应的皇后放在第row行
	int i = 0;
	// printf("%d %d \n", col, row);
	for (i = 0; i < col; i++) {
		if (queen[i] == row) { // 前面列对应的皇后是否有在row行的
			return 0;
		} 

		// printf("%d %d %d %d\n", row, queen[i], col, i);
		if ((row - queen[i]) + (col - i) == 0 || (row - queen[i]) - (col - i) == 0 ) { // 判断是否在同一条斜线上 两点的斜率是否为 1 or -1
			// printf("%s\n", "Dfdfdf");
			return 0;
		}
	}
	// printf("%s\n", "aaa");
	return 1;
}



void search_and_place(int col) {
	if (col >= N) { // 超过所有列
		sum += 1; // 一个完整的结果
		print_result();
		return;
	}

	int row = 0;
	for (row = 0; row < N; row++) {
		if (check(col, row) == 1) { // 判断是否可以把第col对应的皇后放在第row行
			queen[col] = row; // 把第col对应的皇后放在第row行
			// printf("%s %d %s %d\n", "queen[col]",  queen[col], "row", row);
			search_and_place(col + 1); // 解决下一个小问题
		}
	}

}

int main(int argc, char const *argv[])
{
	int i = 0;
	search_and_place(0);
	return 0;
}