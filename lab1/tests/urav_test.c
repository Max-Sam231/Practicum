#include "../rvnn.h"
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

void test_find_roots1() {
  bool inability_root = false;
  double a = 0;
  double b = 0;
  double c = 0;
  double roots[2];
  int roots_count = 0;
  double epsil = 1e-7;

  find_roots(&inability_root, a, b, c, roots, &roots_count, epsil);
  assert(inability_root == true);
}

void test_find_roots2() {
  bool inability_root = false;
  double a = 1;
  double b = 0;
  double c = -1;
  double roots[2];
  int roots_count = 0;
  double epsil = 1e-7;

  find_roots(&inability_root, a, b, c, roots, &roots_count, epsil);
  assert(roots_count == 2);
  assert(fabsl(roots[0] - (-1)) < 1e-7);
  assert(fabsl(roots[1] - 1) < 1e-7);
}

void test_find_roots3() {
  bool inability_root = false;
  double a = 1;
  double b = 0;
  double c = 0;
  double roots[2];
  int roots_count = 0;
  double epsil = 1e-7;

  find_roots(&inability_root, a, b, c, roots, &roots_count, epsil);
  assert(roots_count == 1);
  assert((fabsl(roots[0] - 0) < 1e-7));
}

void test_find_roots4() {
  bool inability_root = false;
  double a = 1;
  double b = 0;
  double c = 1;
  double roots[2];
  int roots_count = 0;
  double epsil = 1e-7;

  find_roots(&inability_root, a, b, c, roots, &roots_count, epsil);
  assert(roots_count == 0);
}

void test_find_roots5() {
  bool inability_root = false;
  double a = 1;
  double b = 0;
  double c = -1e-7;
  double roots[2];
  int roots_count = 0;
  double epsil = 1e-14;

  find_roots(&inability_root, a, b, c, roots, &roots_count, epsil);
  assert(roots_count == 2);
  assert(fabsl(roots[0] - (-3.162e-4)) < 1e-7);
  assert(fabsl(roots[1] - 3.162e-4) < 1e-7);
}

void test_find_roots6() {
  bool inability_root = false;
  double a = 1;
  double b = -1e10;
  double c = -1;
  double roots[2];
  int roots_count = 0;
  double epsil = 1e-11;

  find_roots(&inability_root, a, b, c, roots, &roots_count, epsil);
  assert(roots_count == 2);

  assert(fabsl(roots[0] - (-1e-10)) < epsil);
  assert(fabsl(roots[1] - 1e10) < epsil);
}

void test_find_roots7() {
  bool inability_root = false;
  double a = 1;
  double b = 0;
  double c = -1e-8;
  double roots[2];
  int roots_count = 0;
  double epsil = 1e-7;

  find_roots(&inability_root, a, b, c, roots, &roots_count, epsil);
  assert(roots_count == 1);

  assert(fabsl(roots[0] - (-1e-10)) < epsil);
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