#include <stdio.h>

#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  if (src.bits[1] != 0 || src.bits[2] != 0) {
    return 1;
  }

  int res = 0;

  /*if(get_exp(src) > 0)*/
  /*s21_truncate(src, &src);*/

  res = src.bits[0];

  if (get_bit(src.bits + 3, 31) == 1) res *= -1;

  *dst = res;

  return 0;
}
