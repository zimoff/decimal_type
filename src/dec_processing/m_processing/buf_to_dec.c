#include <stdio.h>

#include "../../s21_decimal.h"

s21_decimal buf_to_dec(s21_dec_buf* buf) {
  s21_decimal tmp = {.bits[0] = 0, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};

  for (int i = 0; i < 96; i++) {
    if (get_bit_buf(buf, i)) set_dec(&tmp, i);
  }

  set_exp(&tmp, buf->exp);

  return tmp;
}
