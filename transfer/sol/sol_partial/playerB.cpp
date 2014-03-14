#include "playerB.h"
#include "playerBlib.h"

void playerB(int N, int *data) {
  int A = 0, B = 0;
  for(int i = 0; i < 20; ++i) {
    A = A * 2 + data[i];
  }
  for(int i = 0; i < 20; ++i) {
    B = B * 2 + data[20+i];
  }
  answer(A, B);
}
