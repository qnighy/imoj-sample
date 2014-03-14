#include <stdio.h>
#include <stdlib.h>

static FILE *in, *out;

void game(int N);

int main(int argc, char **argv) {
  int scan_result, N;
  if(argc != 3) {
    fprintf(stderr, "usage: %s <output> <input>\n", argv[0]);
    exit(1);
  }
  in = fopen(argv[2], "r");
  if(!in) {
    fprintf(stderr, "can't open %s\n", argv[2]);
    exit(1);
  }
  out = fopen(argv[1], "w");
  if(!out) {
    fprintf(stderr, "can't open %s\n", argv[1]);
    exit(1);
  }
  scan_result = fscanf(in, "%d", &N);
  if(scan_result < 1) {
    fprintf(stderr, "read error from parent process\n");
    exit(1);
  }
  game(N);
  return 0;
}

int guess(int value) {
  int scan_result, guess_result;
  fprintf(out, "%d\n", value);
  fflush(out);
  scan_result = fscanf(in, "%d", &guess_result);
  if(scan_result < 1) {
    fprintf(stderr, "read error from parent process\n");
    exit(1);
  }
  if(guess_result == 0) {
    exit(0);
  }
  return guess_result;
}
