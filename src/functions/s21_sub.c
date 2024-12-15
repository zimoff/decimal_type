#include <stdio.h>
#include <string.h>

#include "../s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int sign_val1 = get_bit(value_1.bits + 3, 31);
  int sign_val2 = get_bit(value_2.bits + 3, 31);
  int sign_res = 0;

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

  s21_dec_buf tmp_res = {.bits[0] = 0,
                         .bits[1] = 0,
                         .bits[2] = 0,
                         .bits[3] = 0,
                         .bits[4] = 0,
                         .bits[5] = 0};

  normalizator(value_1, value_2, &val_buf_1, &val_buf_2);

  if (sign_val1 && sign_val2) {
    if (more_int_m(val_buf_1.bits, val_buf_2.bits, 6)) {
      tmp_res = diff_buf(val_buf_1, val_buf_2);
    } else {
      tmp_res = diff_buf(val_buf_2, val_buf_1);
    }

    if (buf_length_meter(tmp_res)) {
      tmp_res = bank_round_for_operations(tmp_res, &tmp_res.exp);
    }

    if (more_int_m(val_buf_1.bits, val_buf_2.bits, 6)) {
      sign_res = 1;
    } else {
      sign_res = 0;
    }
  }

  if (!sign_val1 && !sign_val2) {
    if (more_int_m(val_buf_1.bits, val_buf_2.bits, 6)) {
      tmp_res = diff_buf(val_buf_1, val_buf_2);
    } else {
      tmp_res = diff_buf(val_buf_2, val_buf_1);
    }

    if (buf_length_meter(tmp_res)) {
      tmp_res = bank_round_for_operations(tmp_res, &tmp_res.exp);
    }

    if (less_int_m(val_buf_1.bits, val_buf_2.bits, 6)) {
      sign_res = 1;
    } else {
      sign_res = 0;
    }
  }

  if (x_or(sign_val1, sign_val2)) {
    if (more_int_m(val_buf_1.bits, val_buf_2.bits, 6)) {
      sign_res = (sign_val1 == 1) ? 1 : 0;
    } else {
      sign_res = (sign_val1 == 1) ? 1 : 0;
    }

    sum_buf_buf(&val_buf_1, &val_buf_2);
    tmp_res = val_buf_1;

    if (buf_length_meter(tmp_res)) {
      tmp_res = bank_round_for_operations(tmp_res, &tmp_res.exp);
    }
  }

  if (buf_length_meter(tmp_res)) {
    res = (sign_res == 1) ? 2 : 1;
  }

  *result = buf_to_dec(&tmp_res);

  if (sign_res) set_bit(result->bits + 3, 31);

  return res;
}
