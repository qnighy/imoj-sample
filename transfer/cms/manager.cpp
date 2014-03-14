#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESS 100

int main(int argc, char **argv) {
  if(argc != 5) {
    fprintf(stderr, "usage: %s <in1> <out1> <in2> <out2> < input > output\n", argv[0]);
    exit(1);
  }
  FILE *inp1, *outp1, *inp2, *outp2;
  inp1 = fopen(argv[1], "w");
  if(!inp1) {
    fprintf(stderr, "can't open %s\n", argv[1]);
    exit(1);
  }
  outp1 = fopen(argv[2], "r");
  if(!outp1) {
    fprintf(stderr, "can't open %s\n", argv[2]);
    exit(1);
  }
  inp2 = fopen(argv[3], "w");
  if(!inp2) {
    fprintf(stderr, "can't open %s\n", argv[3]);
    exit(1);
  }
  outp2 = fopen(argv[4], "r");
  if(!outp2) {
    fprintf(stderr, "can't open %s\n", argv[4]);
    exit(1);
  }

  int A, B, N, data[40];
  scanf("%d%d", &A, &B);
  N = 0;

  fprintf(inp1, "%d %d\n", A, B);
  fflush(inp1);
  while(true) {
    int b;
    fscanf(outp1, "%d", &b);
    if(b == 0 || b == 1) {
      if(N >= 40) {
        // fprintf(stderr, "send(b): too many call\n");
        fprintf(inp2, "%d\n", -1);
        printf("0.0\n");
        exit(0);
      }
      data[N++] = b;
    } else if(b == -1) {
      break;
    } else {
      // fprintf(stderr, "send(b): invalid B\n");
      fprintf(inp2, "%d\n", -1);
      printf("0.0\n");
      exit(0);
    }
  }

  fprintf(inp2, "%d\n", N);
  for(int i = 0; i < N; ++i) {
    fprintf(inp2, "%d\n", data[i]);
  }
  fflush(inp2);

  int X, Y;
  fscanf(outp2, "%d%d", &X, &Y);
  if(X == A && Y == B) {
    fprintf(stderr, "OK\n");
    printf("1.0\n");
  } else {
    // fprintf(stderr, "Wrong answer\n");
    printf("0.0\n");
  }
  return 0;
}
