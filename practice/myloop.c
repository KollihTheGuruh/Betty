#include <stdio.h>

void myLoop(int i, int j) {
  for(j=1; j<6; j++) {
    printf("%d x %d = %d\n", i, j, i*j);
  }
}

int main() {
  int i = 5, j = 0;
  myLoop(i, j);
  return 0;
}
