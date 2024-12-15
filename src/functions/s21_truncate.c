#include <stdio.h>
#include <string.h>

#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int res_ret = 0;

  int sign_val = get_bit(value.bits + 3, 31);

  int res_exp = get_exp(value);

  s21_dec_buf divider = {.bits[0] = 10,
                         .bits[1] = 0,
                         .bits[2] = 0,
                         .bits[3] = 0,
                         .bits[4] = 0,
                         .bits[5] = 0};

  s21_dec_buf res = dec_to_buf(&value);

  s21_dec_buf num = res;

  s21_dec_buf zero = {{0, 0, 0, 0, 0, 0}, 0};

  int count = 0;
  if (is_dec_zero(value)) {
    result->bits[0] = 0;
    result->bits[1] = 0;
    result->bits[2] = 0;
    result->bits[3] = 0;

  } else {
    while ((res_exp > 0) && more_int_m(num.bits, zero.bits, 6)) {
      res = div_buf(&num, &divider);

      num = res;
      count++;
      res_exp--;
    }

    res.exp = res_exp;

    *result = buf_to_dec(&res);

    if (is_dec_zero(*result)) {
      result->bits[3] = 0;
    }

    if (sign_val) set_bit(result->bits + 3, 31);
  }

  return res_ret;
}
