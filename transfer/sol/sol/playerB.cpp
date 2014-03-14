#include "playerB.h"
#include "playerBlib.h"

void synth(long long C, int *A, int *B) {
  int S_lo = 0, S_hi = 2000000;
  while(S_hi - S_lo > 1) {
    long long S_mid = (S_lo + S_hi) / 2;
    if(S_mid * (S_mid + 1) / 2 <= C) {
      S_lo = S_mid;
    } else {
      S_hi = S_mid;
    }
  }
  *A = C - (long long)S_lo * (S_lo + 1) / 2;
  *B = S_lo - *A;
}

void playerB(int N, int *data) {
  long long C = 1;
  for(int i = N - 1; i >= 0; --i) {
    C = C * 2 + data[i];
  }
  int A, B;
  synth(C - 1, &A, &B);
  answer(A, B);
}
