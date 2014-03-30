#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pointLength {
	int *pointer;
	int length;
};


struct pointLength bigNumberadd(struct pointLength strNum1, struct pointLength strNum2){ // e.g. strNum1[] = {1, 2, 3}
	int i = 0;
	int length1 = strNum1.length;
	int *s1 = strNum1.pointer;
	int length2 = strNum2.length;
	int *s2 = strNum2.pointer;
	

	struct pointLength res;
	int length = (int) malloc( sizeof(int));
	length = length1 + length2;
	int *pInt = (int *) malloc(length * sizeof(int)); // use to store the digit of result
	
	
	// initialize to 0
	for(i = 0; i < length; i++) {
		pInt[i] = 0;
	}

	// add all the digit at the relative position from right to left
	int temLen1 = length1;
	int temLen2 = length2;
	i = length - 1;
	while(temLen1 > 0 && temLen2 > 0) {
		pInt[i] = s1[temLen1-1] + s2[temLen2-1];
		temLen1--;
		temLen2--;
		i--;
	}

	while(temLen1 > 0) {
		pInt[i] = s1[temLen1-1];
		temLen1--;
		i--;
	}

	while(temLen2 > 0) {
		pInt[i] = s2[temLen2-1];
		temLen2--;
		i--;
	}

	for(i = length-1; i >= 0; i--){
		if (pInt[i] > 9) {
			pInt[i-1] += pInt[i] / 10;
			pInt[i] = pInt[i] % 10;
		}
	}

	res.pointer = pInt;
	res.length = length;

	return res;

}

struct pointLength(int n){
	struct pointLength res;
	if (n == 0) {
		int s1[] = {11};
		int s2[] = {1};
		struct pointLength points1;
		struct pointLength points2;
		points1.length = 1;
		points1.pointer = s1;
		points2.length = 11;
		points2.pointer = s2;
		res = bigNumberadd(points1, points2);
	} else {
		int numArr[2 * n];
		int i = 0;
		for (i = 0; i < 2 * n; i++) {
			numArr[i] = 0;
		}
		nu

		int temLen = 2 * n;
		for()
	}

}

int main(int argc, char const *argv[])
{
	int s1[] = {1, 2, 3};
	int s2[] = {1, 2, 3};
	int i = 0;

	struct pointLength strNum1;
	struct pointLength strNum2;
	strNum1.pointer = s1;
	strNum1.length = 3;
	strNum2.pointer = s2;
	strNum2.length = 3;

	struct pointLength res = bigNumberadd(strNum1, strNum2);
	free(res.pointer);

	return 0;
}