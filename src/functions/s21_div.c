#include <stdio.h>
#include <string.h>

#include "../s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int sign_val1 = get_bit(value_1.bits + 3, 31);
  int sign_val2 = get_bit(value_2.bits + 3, 31);
  int sign_res = 0;

  result->bits[0] = 0;
  result->bits[1] = 0;
  result->bits[2] = 0;
  result->bits[3] = 0;

  int exp = get_exp(value_1) - get_exp(value_2);

  int res = 0;

  s21_dec_buf val_buf_1 = {.bits[0] = 0,
                           .bits[1] = 0,
                           .bits[2] = 0,
                           .bits[3] = 0,
                           .bits[4] = 0,
                           .bits[5] = 0,
                           .exp = 0

  };

  s21_dec_buf val_buf_2 = {.bits[0] = 0,
                           .bits[1] = 0,
                           .bits[2] = 0,
                           .bits[3] = 0,
                           .bits[4] = 0,
                           .bits[5] = 0,
                           .exp = 0

  };

  s21_dec_buf sum = {.bits[0] = 0,
                     .bits[1] = 0,
                     .bits[2] = 0,
                     .bits[3] = 0,
                     .bits[4] = 0,
                     .bits[5] = 0,
                     .exp = 0};

  s21_dec_buf tmp = {.bits[0] = 0,
                     .bits[1] = 0,
                     .bits[2] = 0,
                     .bits[3] = 0,
                     .bits[4] = 0,
                     .bits[5] = 0,
                     .exp = 0};

  s21_dec_buf multipler = {.bits[0] = 10,
                           .bits[1] = 0,
                           .bits[2] = 0,
                           .bits[3] = 0,
                           .bits[4] = 0,
                           .bits[5] = 0,
                           .exp = 0};

  s21_dec_buf zero = {.bits[0] = 0,
                      .bits[1] = 0,
                      .bits[2] = 0,
                      .bits[3] = 0,
                      .bits[4] = 0,
                      .bits[5] = 0,
                      .exp = 0};

  if (equal_int_m(value_2.bits, zero.bits, 3)) {
    return 3;
  }

  val_buf_1 = dec_to_buf(&value_1);
  val_buf_2 = dec_to_buf(&value_2);

  while (1) {
    tmp = div_buf(&val_buf_1, &val_buf_2);

    sum_buf_buf(&sum, &tmp);

    if (equal_int_m(val_buf_1.bits, zero.bits, 6)) {
      break;
    }

    if (buf_length_meter(sum)) {
      break;
    }

    mul_buf(val_buf_1, multipler, &val_buf_1);
    mul_buf(sum, multipler, &sum);

    exp++;
  }

  if (buf_length_meter(sum) || (exp > 28) || (exp < 0)) {
    sum = bank_round_for_operations(sum, &exp);
    exp = sum.exp;
  }

  if (exp < 0) {
    exp *= -1;
  }

  *result = buf_to_dec(&sum);

  if (x_or(sign_val1, sign_val2)) {
    sign_res = 1;
  }

  set_exp(result, exp);

  if (exp > 28) {
    res = 1;
    if (sign_res == 1) res = 2;
  }

  if (sign_res == 1) {
    set_bit(result->bits + 3, 31);
  }

  return res;
}
