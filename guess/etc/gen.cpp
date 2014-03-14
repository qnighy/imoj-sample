#include "testlib.h"
#include <cstdio>

int main(int argc, char *argv[]) {
  registerGen(argc, argv);
  const int ub = atoi(argv[1]) == 1 ? 100 : 100000000;
  const int N = rnd.next(1, ub);
  const int K = rnd.next(0, N-1);
  printf("%d %d\n", N, K);
  return 0;
}
