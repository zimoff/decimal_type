#include <stdio.h>

#include "../../s21_decimal.h"

int x_or(int a, int b) {
  int res = 0;
  if ((a || b) && (!(a && b))) res = 1;
  return res;
}
