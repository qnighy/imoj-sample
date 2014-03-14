#include "testlib.h"
#include <cstdio>

int main(int argc, char *argv[]) {
  registerGen(argc, argv);
  const long long ub = atoi(argv[1]) == 0 ? 100000000 : 1000000000000000LL;
  const long long a = rnd.next(1LL, ub);
  const long long b = rnd.next(1LL, ub);
  printf("%lld %lld\n", a, b);
  return 0;
}
