#include "testlib.h"
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
  registerValidation();

  const int subtask = atoi(argv[1]);
  const int M = subtask == 1 ? 1000000 : 2000000;
  const int A = inf.readInt(0, M-1, "A");
  inf.readSpace();
  const int B = inf.readInt(0, M-1, "B");
  inf.readEoln();
  inf.readEof();

  ensuref(A + B < M, "A + B should be less than M");
  return 0;
}
