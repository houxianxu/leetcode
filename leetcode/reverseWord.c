// http://oj.leetcode.com/problems/reverse-words-in-a-string/
#include <stdio.h>
#include <string.h>

void reverseWorld(char *s){
	char *pch;
	char res[1000];
	char *wordP[1000];
	int i = 0;
	int j = 0;
	pch = strtok(s, " ");

	while(pch != NULL) {
		wordP[i++] = pch;
		pch = strtok(NULL, " ");
	}

	/* copy word from wordP inversly to res */
	strcpy(res, "");
	i--;
	while(i >= 0) {
		// printf("%s\n", wordP[i]);
		strcat(res, wordP[i--]);
		// printf("%s\n", "d");
		if (i >= 0) {
			strcat(res, " ");
		}
	}
	printf("%s\n", res);	
}


int main ()
{
  char s[] = "the sky is blue";
  reverseWorld(s);
  return 0;
}