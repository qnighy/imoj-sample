#include <stdio.h>
#include <stdlib.h>
#include "playerA.h"
#include "playerB.h"

static int state;
static int A, B;
static int N, data[40];

int main() {
  scanf("%d%d", &A, &B);
  N = 0;
  state = 0;
  playerA(A, B);
  state = 1;
  playerB(N, data);
  return 1;
}

void send(int b) {
  if(N >= 40) {
    fprintf(stderr, "send(b): too many call.\n");
    exit(1);
  }
  if(b < 0 || 2 <= b) {
    fprintf(stderr, "send(b): invalid b.\n");
    exit(1);
  }
  if(state != 0) {
    fprintf(stderr, "send(b): invalid state.\n");
    exit(1);
  }
  data[N++] = b;
}

void answer(int X, int Y) {
  if(state != 1) {
    fprintf(stderr, "answer(X, Y): invalid state.\n");
    exit(1);
  }
  if(X == A && Y == B) {
    printf("Correct\n");
    exit(0);
  }
  printf("Incorrect\n");
  exit(1);
}
