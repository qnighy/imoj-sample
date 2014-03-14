#include "playerA.h"
#include "playerAlib.h"

long long synth(int A, int B) {
  return (long long)(A + B) * (A + B + 1) / 2 + A;
}

void playerA(int A, int B) {
  long long C = synth(A, B)+1;
  while(C > 1) {
    send(C&1);
    C = C / 2;
  }
}
