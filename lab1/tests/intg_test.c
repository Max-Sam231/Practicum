#include "../intg.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>

double LinearFunc(double x) { return x; }

double QuadraticFunc(double x) { return x * x; }

double InverseFunc(double x) { return 1.0 / x; }

void TestIntegralLinear() {
  double a = 0.0;
  double b = 1.0;
  int n = 1000;
  double result = integral(&LinearFunc, a, b, n);
  assert(fabs(result - 0.5) < 1e-6);
  printf("TestIntegralLinear passed \n");
}

void TestIntegralQuadratic() {
  double a = 0.0;
  double b = 1.0;
  int n = 1000;
  double result = integral(&QuadraticFunc, a, b, n);
  assert(fabs(result - 1.0 / 3.0) < 1e-6);
  printf("TestIntegralQuadratic passed \n");
}

void TestIntegralSin() {
  double a = 0.0;
  double b = M_PI;
  int n = 10000;
  double result = integral(&sin, a, b, n);
  assert(fabs(result - 2.0) < 1e-6);
  printf("TestIntegralSin passed \n");
}

void TestIntegralExp() {
  double a = 0.0;
  double b = 1.0;
  int n = 1000;
  double result = integral(&exp, a, b, n);
  assert(fabs(result - (exp(1.0) - 1.0)) < 1e-6);
  printf("TestIntegralExp passed \n");
}

void TestIntegralZeroInterval() {
  double a = 1.0;
  double b = 1.0;
  int n = 1000;
  double result = integral(&LinearFunc, a, b, n);
  assert(result == 0.0);
  printf("TestIntegralZeroInterval passed \n");
}

void TestIntegralLargeN() {
  double a = 0.0;
  double b = 1.0;
  int n = 1000000;
  double result = integral(&LinearFunc, a, b, n);
  assert(fabs(result - 0.5) < 1e-6);
  printf("TestIntegralLargeN passed \n");
}

void TestIntegralInverse() {
  double a = 1.0;
  double b = 2.0;
  int n = 1000;
  double result = integral(&InverseFunc, a, b, n);
  assert(fabs(result - log(2.0)) < 1e-6);
  printf("TestIntegralInverse passed \n");
}

void TestIntegralCos() {
  double a = 0.0;
  double b = M_PI / 2;
  int n = 1000;
  double result = integral(&cos, a, b, n);
  assert(fabs(result - 1.0) < 1e-6);
  printf("TestIntegralCos passed \n");
}

int main() {
  TestIntegralLinear();
  TestIntegralQuadratic();
  TestIntegralSin();
  TestIntegralExp();
  TestIntegralZeroInterval();
  TestIntegralLargeN();
  TestIntegralInverse();
  TestIntegralCos();
  return 0;
}
