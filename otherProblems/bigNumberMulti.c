#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 大数乘法基本思想：将大数以字符串的形式存放，
// 根据乘法准则,把每次单个相乘的结果累加到对应位置上，最后对>＝9的数进行进位处理.

void bigNumberMulti(char *strNum1, char *strNum2) {
	int length1 = 0;
	int length2 = 0;
	int length = 0;
	int i = 0;
	int j = 0;
	int tempLength = 0;
	length1 = strlen(strNum1);
	length2 = strlen(strNum2);

	// the total number of digit should = length or (length - 1)
	length = length1 + length2; 

	int number[length]; 
	// initial all the value as 0
	for(i = 0; i < length; i++) {
		number[i] = 0;
	}
	// store every single computation (int) result in number[]
	for(i = length2 - 1; i >=0; i--) {
		tempLength = --length;
		for(j = length1 - 1; j >= 0; j--) {
			number[tempLength--] += (strNum2[i] - '0') * (strNum1[j] - '0');
		}
	}

	// printf("%d\n", number[1]);
	// printf("%d\n", number[2]);
	// printf("%d\n", number[3]);


	// change the number in number[length] if the number is >= 10, from right to left
	length = length1 + length2; // Remember length has changed, I spent about one hour to debug
	i = length;
	while (i >= 0) {
		if (number[i] >= 10) {
			number[i-1] += number[i] / 10;
			number[i] = number[i] % 10;
		}
		i--;
	}

	for(i = 0; i < length; i++){
		if(i == 0 && number[i] == 0){
			;
		} else {
			printf("%d", number[i]);
			if(i == length-1) {
				printf("\n");
			}
		}
	}
}


int main(int argc, char const *argv[])
{	
	char *strNum1 = "1234567890";
	char *strNum2 = "1234567890";
	bigNumberMulti(strNum1, strNum2);
	return 0;
}