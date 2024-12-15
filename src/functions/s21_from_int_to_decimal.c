#include <stdio.h>

#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  dst->bits[0] = 0;
  dst->bits[1] = 0;
  dst->bits[2] = 0;
  dst->bits[3] = 0;

  if (src < 0) {
    set_bit(dst->bits + 3, 31);
    src *= -1;
  }

  for (int i = 31; i >= 0; i--) {
    if (get_bit(&src, i) == 1) {
      set_bit(dst->bits, i);
    }
  }

  return 0;
}
