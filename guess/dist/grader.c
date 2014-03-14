#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESS 100

static int N, K, count;

void game(int N);

int main() {
  scanf("%d%d", &N, &K);
  count = 0;
  game(N);
  return 0;
}

int guess(int value) {
  if(value < 0 || N <= value) {
    fprintf(stderr, "guess(N): invalid N\n");
    exit(1);
  }
  if(count >= MAX_GUESS) {
    fprintf(stderr, "guess(N): too many call\n");
    exit(1);
  }
  count++;
  if(value == K) {
    printf("OK\n");
    exit(0);
  } else if(value < K) {
    return -1;
  } else {
    return 1;
  }
}
