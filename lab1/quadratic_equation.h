#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define NOT_QUADRIC_EQUATION -1
#define NO_REAL_ROOTS -2

int find_roots(double a, double b, double c, double *roots, int *roots_count,
               double epsil);
