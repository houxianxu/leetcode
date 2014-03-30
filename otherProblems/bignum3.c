#include <stdio.h>
#include <stdlib.h>


#define M 2000

typedef struct Bignum {
  int len;
  char *arr;
} Bignum;

void resetBignum(Bignum *pa) {
  pa->len = 1;
  pa->arr[0] = 1;
}

// init a bignum to be 1
void initBignum(Bignum *pa) {
  pa->arr = (char*)malloc(M*sizeof(char));
  resetBignum(pa);
}

void freeBignum(Bignum *pa) {
  free(pa->arr);
}


Bignum *copyBignum(Bignum *psrc) {
  Bignum *pdest = (Bignum *)malloc(sizeof(Bignum));
  initBignum(pdest);
  pdest->len = psrc->len;
  int i = 0;
  for(i = 0; i < psrc->len; i++) {
    pdest->arr[i] = psrc->arr[i];
  }
  return pdest;
}

Bignum *add(Bignum *pa, Bignum *pb) {
  Bignum *pres = (Bignum *)malloc(sizeof(Bignum));
  initBignum(pres);
  int i = 0;
  for(i = 0; i < pa->len && i < pb->len; i++) {
    pres->arr[i] = pa->arr[i] + pb->arr[i];
  }
  if (pb->len > pa->len) {
    pres->len = pb->len;
    for(i = pa->len; i < pb->len; i++) {
      pres->arr[i] = pb->arr[i];
    }
  } else {
    pres->len = pa->len;
    for(i = pb->len; i < pa->len; i++) {
      pres->arr[i] = pa->arr[i];
    }
  }
  for(i = 0; i < pres->len; i++) {
    if (pres->arr[i] >= 10) {
      char tmp = pres->arr[i] / 10; // carry number
      pres->arr[i] = pres->arr[i] % 10;
      if (i >= pres->len-1) {
        pres->arr[i+1] = tmp;
        pres->len += 1;
      } else {
        pres->arr[i+1] += tmp;
      }
    }
  }
  return pres;
}


Bignum *mult10(Bignum *pa) {
  Bignum *pres = (Bignum*)malloc(sizeof(Bignum));
  initBignum(pres);
  int i = 0;
  for(i = pa->len - 1; i>=0; i--) {
    pres->arr[i+1] = pa->arr[i];
  }
  pres->arr[0] = 0;
  pres->len  = pa->len + 1;
  return pres;
}

int statDigit1Num(Bignum *pa) {
  int ret = 0;
  int i = 0;
  for(i = 0; i < pa->len; i++) {
    if (pa->arr[i] == 1) {
      ret += 1;
    }
  }
  return ret;
}

int main() {
  Bignum res;
  initBignum(&res);
  int n = 1000;
  int i = 0;
  for(i = 1; i <= 1000; i++) {
    Bignum *tmp = mult10(&res);
    Bignum *new_res = add(tmp, &res);
    freeBignum(&res); // free storeage in res
    res = *new_res; // reassign the new result to res. ***QUESTION***: Why use `=` instead of copyBignum?????????????
    freeBignum(tmp); // free tmp
    free(tmp); // ***QUESTION***: Why we need to free tmp and new_res???????
    free(new_res);
  }
  printf("%d\n", statDigit1Num(&res));
  freeBignum(&res); // free storage in res
}
