#include <stdio.h>

void TestFunc();
static void StaticFunc();

void TestFunc() {
  int i = 0;

  printf("In TestFunc\n");

  for (i = 0; i < 10; i++)
    StaticFunc();
}

static void StaticFunc() {
  int i = 0;

  printf("In StaticFunc\n");

  for (i = 0; i < 100000000; i++)
    ;
}

int main(void) {
  printf("In main\n");

  TestFunc();

  return 0;
}
