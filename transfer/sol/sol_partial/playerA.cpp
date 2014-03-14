#include "playerA.h"
#include "playerAlib.h"

void playerA(int A, int B) {
  for(int i = 19; i >= 0; --i) {
    send((A >> i) & 1);
  }
  for(int i = 19; i >= 0; --i) {
    send((B >> i) & 1);
  }
}
