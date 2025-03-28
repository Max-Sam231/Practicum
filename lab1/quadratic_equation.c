#define NOT_QUADRIC_EQUATION -1
#define NO_REAL_ROOTS -2
#include "quadratic_equation.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int find_roots(double a, double b, double c, double *roots, int *roots_count,
               double epsil) {

  if (fabs(a - 0) < epsil) {
    return NOT_QUADRIC_EQUATION;
  }

  else {

    b /= a;
    c /= a;

    double D = b * b - 4 * c;

    if (D > 0) {
      if (fabs(D) < epsil) {
        D = 0;
        roots[0] = (-b) / 2;
        *roots_count = 1;

        return 0;
      }
      double D_sqrt = sqrt(D);
      if (fabs(D_sqrt) < epsil) {
        D_sqrt = 0;
      }

      roots[0] = (-b + D_sqrt) / 2;
      roots[1] = c / (roots[0]);

      if (roots[1] < roots[0]) {
        double temp = roots[0];
        roots[0] = roots[1];
        roots[1] = temp;
      }
      *roots_count = 2;

      return 0;
    } else if (fabs(D) < epsil) {
      roots[0] = (-b) / 2;
      *roots_count = 1;

      return 0;
    } else {
      return NO_REAL_ROOTS;
    }
  }
}
