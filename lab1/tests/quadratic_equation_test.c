#include "../quadratic_equation.h"
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void test_find_roots1() {

  double a = 0;
  double b = 0;
  double c = 0;
  double roots[2];
  int roots_count = 0;
  double epsil = 1e-14;

  int result = find_roots(a, b, c, roots, &roots_count, epsil);
  assert(result == NOT_QUADRIC_EQUATION);
  printf("test_find_roots1 passed \n");
}

void test_find_roots2() {

  double a = 1;
  double b = 0;
  double c = -1;
  double roots[2];
  int roots_count = 0;
  double epsil = 1e-14;

  int result = find_roots(a, b, c, roots, &roots_count, epsil);

  assert(result == 0);
  assert(roots_count == 2);
  assert(fabs(roots[0] - (-1)) < 1e-7);
  assert(fabs(roots[1] - 1) < 1e-7);
  printf("test_find_roots2 passed \n");
}

void test_find_roots3() {

  double a = 1;
  double b = 0;
  double c = 0;
  double roots[2];
  int roots_count = 0;
  double epsil = 1e-14;

  int result = find_roots(a, b, c, roots, &roots_count, epsil);

  assert(result == 0);
  assert(roots_count == 1);
  assert((fabs(roots[0] - 0) < 1e-7));
  printf("test_find_roots3 passed \n");
}

void test_find_roots4() {

  double a = 1;
  double b = 0;
  double c = 1;
  double roots[2];
  int roots_count = 0;
  double epsil = 1e-14;

  int result = find_roots(a, b, c, roots, &roots_count, epsil);
  assert(result == NO_REAL_ROOTS);
  printf("test_find_roots4 passed \n");
}

void test_find_roots5() {

  double a = 1;
  double b = 0;
  double c = -1e-7;
  double roots[2];
  int roots_count = 0;
  double epsil = 1e-14;

  int result = find_roots(a, b, c, roots, &roots_count, epsil);
  assert(result == 0);
  assert(roots_count == 2);
  assert(fabs(roots[0] - (-3e-4)) < 1e-4);
  assert(fabs(roots[1] - 3e-4) < 1e-4);
  printf("test_find_roots5 passed \n");
}

void test_find_roots6() {

  double a = 1;
  double b = -1e+10;
  double c = -1;
  double roots[2];
  int roots_count = 0;
  double epsil = 1e-11;

  int result = find_roots(a, b, c, roots, &roots_count, epsil);

  assert(result == 0);
  assert(roots_count == 2);
  assert(fabs(roots[0] - (-1e-10)) < epsil);
  assert(fabs(roots[1] - 1e10) < epsil);
  printf("test_find_roots6 passed \n");
}

void test_find_roots7() {

  double a = 1;
  double b = 0;
  double c = -1e-8;
  double roots[2];
  int roots_count = 0;
  double epsil = 1e-7;

  int result = find_roots(a, b, c, roots, &roots_count, epsil);

  assert(result == 0);
  assert(roots_count == 1);
  assert(fabs(roots[0] - 0) < epsil);
  printf("test_find_roots7 passed \n");
}

int main() {
  test_find_roots1();
  test_find_roots2();
  test_find_roots3();
  test_find_roots4();
  test_find_roots5();
  test_find_roots6();
  test_find_roots7();
  return 0;
}
