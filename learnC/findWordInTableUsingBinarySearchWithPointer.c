// the code is from the book 
/* the c programming language 2rd*/

#include <stdio.h>
#include <string.h>

typedef struct key {
	char *word; // here is the pointer to the string which is mean the pointer to the first char in the string 
	int count;
} Key;

Key keytab[] = {
	"auto", 0,
	"break", 0,
	"case", 0,
	"char", 0,
	"const", 0,
	"continue", 0,
	"default", 0,
	"unsigned", 0,
	"void", 0,
	"volatile", 0,
	"while", 0
}; 

// initializing and allocate the storage

/* binsearch: find word in tab[0]...tab[n-1] */

Key *binsearch(char *word, Key keytab[], int n) { // Key *keytab
	int cond;
	Key *low = keytab; // &keytab[0]
	Key *high = keytab + n -1 ; //&keytab[n-1]
	Key *mid;

	while (low < high) {
		mid = low + (high - low) / 2; // can't not (low + hight) / 2
		cond = strcmp(word, mid->word);
		if (cond  < 0) {
			high = mid;
		} else if (cond > 0) {
			low = mid;
		} else {
			return mid;
		}
	}
	return NULL; // nothing found
}
