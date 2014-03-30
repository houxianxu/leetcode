#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Question: What's the difference between foo1 and foo2

// foo1
void foo1(char **pp) {
 *pp = (char*)malloc(10*sizeof(char));
 strcpy(*pp, "abcd");
}

// foo2
void foo2(char **pp) {
 char *p = *pp;
 p = (char*)malloc(10*sizeof(char));
 strcpy(p, "abcd");
}


// bar1 to bar2 is like foo1 to foo2
void bar1(int *pv) {
 *pv = 3;
}

void bar2(int *pv) {
 int v = *pv;
 v = 3;
}


// This is just another method to pass/return results.
void demo(int *pa, int *pb) {
 *pa = 3;
 *pb = 4;
}

int main(int argc, const char *argv[])
{
 return 0;
}