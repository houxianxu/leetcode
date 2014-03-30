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

void copyBignum(Bignum *pdest, Bignum *psrc) {
  pdest->len = psrc->len;
  int i = 0;
  for(i = 0; i < psrc->len; i++) {
    pdest->arr[i] = psrc->arr[i];
  }
}

// add two bignum, res store in pa
void add(Bignum *pa, Bignum *pb) {
  int i = 0;
  for(i = 0; i < pa->len && i < pb->len; i++) {
    pa->arr[i] += pb->arr[i];
  }
  if (pb->len > pa->len) {
    // copy rest of pb
    for(i = pa->len; i < pb->len; i++) {
      pa->arr[i] = pb->arr[i];
    }
    pa->len = pb->len;
  }
  for(i = 0; i < pa->len; i++) {
    if (pa->arr[i] >= 10) {
      int tmp = pa->arr[i] / 10; // carry number
      pa->arr[i] = pa->arr[i] % 10;
      if (i >= pa->len-1) {
        pa->arr[i+1] = tmp;
        pa->len += 1; // update length
      } else {
        pa->arr[i+1] += tmp;
      }
    }
  }
}

void mult10(Bignum *pa) {
  int i = 0;
  for(i = pa->len-1; i >= 0; i--) {
    pa->arr[i+1] = pa->arr[i];
  }
  pa->arr[0] = 0;
  pa->len += 1;
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
  Bignum tmp;
  initBignum(&tmp);
  int n = 1000;
  int i = 0 ;
  // 11^n
  for(i = 1; i <= n; i++) {
    resetBignum(&tmp);
    copyBignum(&tmp, &res);
    mult10(&res);
    add(&res, &tmp);
  }
  printf("%d\n", statDigit1Num(&res));
  freeBignum(&res);
  freeBignum(&tmp);
  return 0;
}
