#include "../urav.h"
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

void TestFindRoots1() {
  bool inability_root = false;
  double a = 0;
  double b = 0;
  double c = 0;
  double roots[2];
  int roots_count = 0;
  double epsil = 1e-7;

  FindRoots(&inability_root, a, b, c, roots, &roots_count, epsil);
  assert(inability_root == true);
}

void TestFindRoots2() {
  bool inability_root = false;
  double a = 1;
  double b = 0;
  double c = -1;
  double roots[2];
  int roots_count = 0;
  double epsil = 1e-7;

  FindRoots(&inability_root, a, b, c, roots, &roots_count, epsil);
  assert(roots_count == 2);
  assert(fabsl(roots[0] - (-1)) < 1e-7);
  assert(fabsl(roots[1] - 1) < 1e-7);
}

void TestFindRoots3() {
  bool inability_root = false;
  double a = 1;
  double b = 0;
  double c = 0;
  double roots[2];
  int roots_count = 0;
  double epsil = 1e-7;

  FindRoots(&inability_root, a, b, c, roots, &roots_count, epsil);
  assert(roots_count == 1);
  assert((fabsl(roots[0] - 0) < 1e-7));
}

void TestFindRoots4() {
  bool inability_root = false;
  double a = 1;
  double b = 0;
  double c = 1;
  double roots[2];
  int roots_count = 0;
  double epsil = 1e-7;

  FindRoots(&inability_root, a, b, c, roots, &roots_count, epsil);
  assert(roots_count == 0);
}

void TestFindRoots5() {
  bool inability_root = false;
  double a = 1;
  double b = 0;
  double c = -1e-7;
  double roots[2];
  int roots_count = 0;
  double epsil = 1e-14;

  FindRoots(&inability_root, a, b, c, roots, &roots_count, epsil);
  assert(roots_count == 2);
  assert(fabsl(roots[0] - (-3e-4)) < 1e-4);
  assert(fabsl(roots[1] - 3e-4) < 1e-4);
}

void TestFindRoots6() {
  bool inability_root = false;
  double a = 1;
  double b = -1e10;
  double c = -1;
  double roots[2];
  int roots_count = 0;
  double epsil = 1e-11;

  FindRoots(&inability_root, a, b, c, roots, &roots_count, epsil);
  assert(roots_count == 2);

  assert(fabsl(roots[0] - (-1e-10)) < epsil);
  assert(fabsl(roots[1] - 1e10) < epsil);
}

void TestFindRoots7() {
  bool inability_root = false;
  double a = 1;
  double b = 0;
  double c = -1e-8;
  double roots[2];
  int roots_count = 0;
  double epsil = 1e-7;

  FindRoots(&inability_root, a, b, c, roots, &roots_count, epsil);
  assert(roots_count == 1);
  assert(fabsl(roots[0] - 0) < epsil);
}

int main() {
  TestFindRoots1();
  TestFindRoots2();
  TestFindRoots3();
  TestFindRoots4();
  TestFindRoots5();
  TestFindRoots6();
  TestFindRoots7();
  return 0;
}
