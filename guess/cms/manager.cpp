#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESS 100

int main(int argc, char **argv) {
  if(argc != 3) {
    fprintf(stderr, "usage: %s <in> <out> < input > output\n", argv[0]);
    exit(1);
  }
  FILE *inp, *outp;
  inp = fopen(argv[1], "w");
  if(!inp) {
    fprintf(stderr, "can't open %s\n", argv[1]);
    exit(1);
  }
  outp = fopen(argv[2], "r");
  if(!outp) {
    fprintf(stderr, "can't open %s\n", argv[2]);
    exit(1);
  }

  int N, K, count;
  scanf("%d%d", &N, &K);
  count = 0;

  fprintf(inp, "%d\n", N);
  fflush(inp);
  while(true) {
    int value, result;
    fscanf(outp, "%d", &value);
    if(value < 0 || N <= value) {
      // fprintf(stderr, "guess(N): invalid N\n");
      printf("0.0\n");
      fprintf(inp, "%d\n", 0);
      exit(0);
    }
    if(count >= MAX_GUESS) {
      // fprintf(stderr, "guess(N): too many call\n");
      printf("0.0\n");
      fprintf(inp, "%d\n", 0);
      exit(0);
    }
    count++;
    if(value == K) {
      fprintf(stderr, "OK\n");
      printf("1.0\n");
      // printf("OK\n");
      fprintf(inp, "%d\n", 0);
      exit(0);
    } else if(value < K) {
      result = -1;
    } else {
      result = 1;
    }
    fprintf(inp, "%d\n", result);
    fflush(inp);
  }
  return 0;
}
