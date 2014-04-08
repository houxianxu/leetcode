#include <stdio.h>
// #include <stdlib.h>
#include <math.h>
#include <string.h>
#define M 1000000




int is_same (const char *s, int start, int end) {
	int res = 1;
	while (start < end) {
		if (s[start] == s[start + 1]){
			start += 1;
		} else {
			res = 0;
			return res;
		}
	}
	return res;
}


int main(int argc, char const *argv[])
{   
	/* in short, initializing the array copies a string from static storage to the array, 
	whereas initializing the pointer merely copies the address of the string. */

	char heart[] = "houxianxu"; // can be changed 
	char *head = "houxianxu"; // can not be changed

	/* The chief difference is that the array name heart is a constant, 
	but the pointer head is a variable. */

	heart[1] = 'x';
	// b[1] = 'x'; // 段错误 (核心已转储)
	printf("%c\n", heart[1]);
	printf("%p\n", "houxianxu");
	printf("%p\n", heart);
	printf("%p\n", head);
}