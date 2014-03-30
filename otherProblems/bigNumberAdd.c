#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct pointerLen {
	int *p;
	int length; // the length of the pointer p
};

struct pointerLen bigNumberAdd(char *strNum1, char *strNum2) {
	int length1 = strlen(strNum1);
	int length2 = strlen(strNum2);
	// if(length1 == 0) {
	// 	return 
	// }
	int length = length1 + length2;

	int i = 0;

	int *pInt = (int *) malloc(length * sizeof(int)); // use to store the digit of result
	// int pInt[length];
	// initialize to 0
	for(i = 0; i < length; i++) {
		pInt[i] = 0;
	}

	// add the correspond digit from right to left
	int tempLen1 = length1;
	int tempLen2 = length2;
	i = length - 1;
	while(tempLen1 > 0 && tempLen2 > 0) {
		pInt[i] = (strNum1[tempLen1-1] - '0') + (strNum2[tempLen2-1] - '0');
		i--;
		tempLen1--;
		tempLen2--;
	}

	while(tempLen1 > 0) {
		pInt[i] = strNum1[tempLen1-1] - '0';
		tempLen1--;
		i--;
	}

	while(tempLen2 > 0) {
		pInt[i] = strNum2[tempLen2-1] - '0';
		tempLen2--;
		i--;
	}

	// deal with the pInt[i] > 10
	for (i = length -1; i >= 0; i--){
		if(pInt[i] > 9) {
			pInt[i-1] += pInt[i] / 10;
			pInt[i] = pInt[i] % 10;
		}
	}

	struct pointerLen res;
	res.p = pInt;
	res.length = length;
	// for(i = 0; i < res.length; i++){
	// 	printf("%d\n", res.p[i]);
	// }
	return res;
}


int main(int argc, char const *argv[])
{
	char *strNum1 = "1234";
	char *strNum2 = "1234";
	int i = 0;
	struct pointerLen res = bigNumberAdd(strNum1, strNum2);
	for(i = 0; i < res.length; i++){
		printf("%d%s", res.p[i], i == res.length - 1? "\n": " ");
	}
	// printf("%d\n", res.length);
	free(res.p);
	return 0;
}

/* should discuss more about the return pointer which is in the struct */