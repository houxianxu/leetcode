#include <stdio.h>

#define M 2000

typedef struct Bignum {
	int len;
	int arr[M]; // store the digit inversely. i.e from left to right
} Bignum;

void printBignum(Bignum *pa){
	int i = 0;
	for(i = 0; i < pa->len; i++) {
		printf("%d", pa->arr[i]);
	}
	printf("\n");
}

void intiBignum(Bignum *pa) {
	pa->len = 1;
	int i;
	for(i = 0; i < M; i++){
		pa->arr[i] = 0;
	}
	pa->arr[0] = 1;
}

void add(Bignum *pa, Bignum *pb) {// restore the result in pa
	int templen1 = pa->len;
	int templen2 = pb->len;
	int i = 0;
	while (templen1 > 0 && templen2 > 0) {
		pa->arr[i] += pb->arr[i];
		i++;
		templen1--;
		templen2--;
	}

	while (templen2 > 0){
		pa->arr[i] = pb->arr[i];
		templen2--;
		i++;
	}

	if (pa->len < pb->len) {
		pa->len = pb->len;
	}
	// printf("%d\n", pa->len);
	// deal with when digit > 9
	for(i = 0; i < pa->len; i++) {
		if (pa->arr[i] > 9) {
			pa->arr[i+1] += pa->arr[i] / 10;
			pa->arr[i] = pa->arr[i] % 10;
			if (i == pa->len - 1) {
				pa->len += 1;
			}
		}
	}
	// printBignum(pa);
}

void multi10(Bignum *pa) {
	int i = 0;
	for(i = pa->len; i > 0; i--){
		pa->arr[i] = pa->arr[i-1];
	}
	pa->arr[0] = 0;
	pa->len += 1;
}

// void copyBignum(Bignum *pdes, Bignum *psrc){
// 	pdes->len = psrc->len;
// 	int i = 0;
// 	for(i = 0; i < pdes->len; i++) {
// 		pdes->arr[i] = psrc->arr[i];
// 	}
// }

/* don't need this, just use des = src */

int staticsNumOfOne(Bignum *pa){
	int i = 0;
	int res = 0;
	for(i = 0; i < pa->len; i++) {
		if (pa->arr[i] == 1) {
			res += 1;
		}
	}
	return res;
}

void main() {
	int n = 1000;
	int i = 0;
	Bignum res;
	intiBignum(&res);
	Bignum temp;
	printBignum(&res);


	// Bignum a, b;
	// a.len = 1;
	// a.arr[0] = 9;
	// b.len = 1;
	// b.arr[0] = 9;
	// add(&a, &b);
	// printBignum(&a);

	for(i = 1; i <= n; i++) {
		temp = res;
		multi10(&temp);
		add(&res, &temp);
	}
	printBignum(&res);
	printf("%d\n", staticsNumOfOne(&res));
}	