#include "grader.h"

void game(int N) {
  int lb=-1, ub=N;
  while(true) {
    int mid=(lb+ub)/2;
    if(guess(mid) < 0) {
      lb = mid;
    } else {
      ub = mid;
    }
  }
}
