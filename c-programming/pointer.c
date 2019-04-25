#include <stdio.h>

int main() {

  // variable declarations
  int x = 1;
  int y = 2;
  int z[10];
  printf("%d\n", &x); // print the address of x
  printf("%d\n", &y); // print the address of y
  printf("%d\n", &z); // print the address of z
  printf("------\n");

  int *ip;             // decalre a pointer (int) called ip
  printf("%d\n", &ip); // print the address of pointer ip
  printf("------\n");

  ip = &x;             // points to the address of x
  printf("%d\n", ip);  // print the value of ip
  printf("%d\n", &x);  // print the address of x
  printf("%d\n", *ip); // print the value of pointer ip points
  printf("------\n");

  printf("%d\n", y);
  y = *ip; // assign the value of what ip points to y
  printf("%d\n", y);
  printf("------\n");

  *ip = 0;
  printf("%d\n", x);   // print the value of x
  printf("%d\n", *ip); // print the value of pointer ip points
  printf("------\n");

  ip = &z[0];
  printf("%d\n", ip);   // print the value of ip
  printf("%d\n", ++ip); // print the value of ip
  printf("%d\n", ++ip); // print the value of ip
  printf("%d\n", ++ip); // print the value of ip

  printf("%d\n", *ip);   // print the value of ip
  printf("%d\n", &z[0]); // print the address of z
  printf("%d\n", &z[1]); // print the address of z
  printf("%d\n", &z[2]); // print the address of z
  printf("%d\n", &z[3]); // print the address of z
}
