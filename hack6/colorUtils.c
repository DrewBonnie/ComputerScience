#include <stdlib.h>
#include <math.h>
#include "colorUtils.h"

double max(double a, double b, double c) {
  return (a > b) ? (a > c ? a : c) : (b > c ? b: c);
}

int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k) {
  if (c == NULL || m == NULL || y == NULL || k == NULL) {
    return 2;
  }
  if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0) {
    return 1;
  }

  double newR = 0, newG = 0, newB = 0;
  newR = (double) r / 255;
  newG = (double) g / 255;
  newB = (double) b / 255;

  *k = 1 - (max(newR, newG, newB));
  if (*k == 1) {
    *c = 0;
    *m = 0;
    *y = 0;
    return 0;
  }

  *c = (1 - newR - *k) / (1 - *k);
  *m = (1 - newG - *k) / (1 - *k);
  *y = (1 - newB - *k) / (1 - *k);
  return 0;
}

int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b) {
  if (r == NULL || g == NULL || b == NULL) {
    return 2;
  }
  if (c < 0 || m < 0 || y < 0 || k < 0 || c > 1 || m > 1 || y > 1 || k > 1) {
    return 1;
  }

  double newR = 0, newG = 0, newB = 0;
  newR = 255 * (1 - c) * (1 - k) + 0.5;
  newG = 255 * (1 - m) * (1 - k) + 0.5;
  newB = 255 * (1 - y) * (1 - k) + 0.5;

  *r = (int) newR;
  *g = (int) newG;
  *b = (int) newB;
  return 0;
}