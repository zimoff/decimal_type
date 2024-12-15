#include <stdio.h>

#include "../../s21_decimal.h"

int mul_buf(s21_dec_buf num1, s21_dec_buf num2, s21_dec_buf* buf) {
  buf->bits[0] = 0;
  buf->bits[1] = 0;
  buf->bits[2] = 0;
  buf->bits[3] = 0;
  buf->bits[4] = 0;
  buf->bits[5] = 0;

  s21_dec_buf for_mult;
  s21_dec_buf for_shift;
  s21_dec_buf tmp;

  if (less_int_m(num1.bits, num2.bits, 6)) {
    for_mult = num2;
    for_shift = num1;
  } else {
    for_mult = num1;
    for_shift = num2;
  }

  for (int i = 0; i < 192; i++) {
    if (get_bit_buf(&for_mult, i) == 1) {
      tmp = shift(for_shift.bits, i, 6);
      sum_buf_buf(buf, &tmp);
    }
  }

  buf->exp = num1.exp + num2.exp;

  return 0;
}
