#include <stdio.h>

#include "../s21_decimal.h"

int buf_length_meter(s21_dec_buf buf) {
  int res = 0;

  for (int i = 191; i > 95; i--) {
    if (get_bit(buf.bits + (i / 32), i % 32) == 1) {
      res = 1;
      break;
    }
  }

  return res;
}
