#include "../integral.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>

double linear_func(double x) { return x; }

double quadratic_func(double x) { return x * x; }

double inverse_func(double x) { return 1.0 / x; }

void test_integral_linear() {
  double a = 0.0;
  double b = 1.0;
  int n = 1000;
  double result = integral(&linear_func, a, b, n);
  assert(fabs(result - 0.5) < 1e-6);
  printf("test_integral_linear passed \n");
}

void test_integral_quadratic() {
  double a = 0.0;
  double b = 1.0;
  int n = 1000;
  double result = integral(&quadratic_func, a, b, n);
  assert(fabs(result - 1.0 / 3.0) < 1e-6);
  printf("test_integral_quadratic passed \n");
}

void test_integral_sin() {
  double a = 0.0;
  double b = M_PI;
  int n = 10000;
  double result = integral(&sin, a, b, n);
  assert(fabs(result - 2.0) < 1e-6);
  printf("test_integral_sin passed \n");
}

void test_integral_exp() {
  double a = 0.0;
  double b = 1.0;
  int n = 1000;
  double result = integral(&exp, a, b, n);
  assert(fabs(result - (exp(1.0) - 1.0)) < 1e-6);
  printf("test_integral_exp passed \n");
}

void test_integral_zero_interval() {
  double a = 1.0;
  double b = 1.0;
  int n = 1000;
  double result = integral(&linear_func, a, b, n);
  assert(result == 0.0);
  printf("test_integral_zero_interval passed \n");
}

void test_integral_large_n() {
  double a = 0.0;
  double b = 1.0;
  int n = 1000000;
  double result = integral(&linear_func, a, b, n);
  assert(fabs(result - 0.5) < 1e-6);
  printf("test_integral_large_n passed \n");
}

void test_integral_inverse() {
  double a = 1.0;
  double b = 2.0;
  int n = 1000;
  double result = integral(&inverse_func, a, b, n);
  assert(fabs(result - log(2.0)) < 1e-6);
  printf("test_integral_inverse passed \n");
}

void test_integral_cos() {
  double a = 0.0;
  double b = M_PI / 2;
  int n = 1000;
  double result = integral(&cos, a, b, n);
  assert(fabs(result - 1.0) < 1e-6);
  printf("test_integral_cos passed \n");
}

int main() {
  test_integral_linear();
  test_integral_quadratic();
  test_integral_sin();
  test_integral_exp();
  test_integral_zero_interval();
  test_integral_large_n();
  test_integral_inverse();
  test_integral_cos();
  return 0;
}
