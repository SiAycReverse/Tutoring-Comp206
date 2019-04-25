#include <stdio.h>


#define LOWER 32
#define UPPER 90
#define STEP 5


int main() {

  int fahr;
  for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
      printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr -32));
  }
  putchar(EOF);
  return 0;
}
