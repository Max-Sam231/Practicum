#include "urav.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

void find_roots(bool *inability_root, double a, double b, double c,
                double roots[2], int *roots_count, double epsil) {
  if (a == 0) {
    *inability_root = true;
  } else {
    double D = b * b - 4 * a * c;

    if (D > 0) {
      if (D < epsil) {
        D = 0;
        roots[0] = (-b) / (2 * a);
        *roots_count = 1;

        return;
      }
      double D_sqrt = sqrt(D);

      if (b > 0) {
        roots[0] = (-b - D_sqrt) / (2 * a);
        roots[1] = (2 * c) / (-b - D_sqrt);
      } else {
        roots[0] = (2 * c) / (-b + D_sqrt);
        roots[1] = (-b + D_sqrt) / (2 * a);
      }

      if (roots[1] < roots[0]) {
        double temp = roots[0];
        roots[0] = roots[1];
        roots[1] = temp;
      }
      *roots_count = 2;
    } else if (D == 0) {
      roots[0] = (-b) / (2 * a);
      *roots_count = 1;
    } else {
      *roots_count = 0;
    }
  }
}
