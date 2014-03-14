#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  const int subtask = atoi(argv[1]);
  const int M = subtask == 1 ? 1000000 : 2000000;
  int A = rnd.next(M);
  int B = rnd.next(M);
  if(A + B >= M) {
    A = M - 1 - A;
    B = M - 1 - B;
  }
  cout << A << " " << B << endl;
  return 0;
}
