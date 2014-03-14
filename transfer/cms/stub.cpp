#include <stdio.h>
#include <stdlib.h>

static int state;
static FILE *inp, *outp;

void playerA(int, int);
void playerB(int, int[]);

int main(int argc, char **argv) {
  if(argc != 4) {
    fprintf(stderr, "usage: %s (0|1) <output> <input>\n", argv[0]);
    exit(1);
  }
  inp = fopen(argv[3], "r");
  if(!inp) {
    fprintf(stderr, "can't open %s\n", argv[3]);
    exit(1);
  }
  outp = fopen(argv[2], "w");
  if(!outp) {
    fprintf(stderr, "can't open %s\n", argv[2]);
    exit(1);
  }
  if(sscanf(argv[1], "%d", &state) < 1) {
    fprintf(stderr, "invalid argv[1]\n");
    exit(1);
  }
  if(state == 0) {
    int A, B;
    if(fscanf(inp, "%d%d", &A, &B) < 2) {
      fprintf(stderr, "read error from parent process\n");
      exit(1);
    }
    playerA(A, B);
    fprintf(outp, "%d\n", -1);
  } else if(state == 1) {
    int N, data[40], i;
    if(fscanf(inp, "%d", &N) < 1) {
      fprintf(stderr, "read error from parent process\n");
      exit(1);
    }
    if(N == -1) exit(0);
    for(i = 0; i < N; ++i) {
      if(fscanf(inp, "%d", &data[i]) < 1) {
        fprintf(stderr, "read error from parent process\n");
        exit(1);
      }
    }
    playerB(N, data);
  } else {
    fprintf(stderr, "invalid argv[1]\n");
    exit(1);
  }
  return 0;
}

void send(int b) {
  if(state == 0) {
    if(b == -1) b = -2;
    fprintf(outp, "%d\n", b);
  }
}

void answer(int X, int Y) {
  if(state == 1) {
    fprintf(outp, "%d %d\n", X, Y);
    exit(0);
  }
}
