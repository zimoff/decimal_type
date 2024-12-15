#include <stdio.h>

#include "../../s21_decimal.h"

s21_dec_buf div_buf(s21_dec_buf* num1, s21_dec_buf* num2) {
  s21_dec_buf tmp1 = *num2;

  s21_dec_buf tmp2 = *num2;

  s21_dec_buf sum_b = {.bits[0] = 1,
                       .bits[1] = 0,
                       .bits[2] = 0,
                       .bits[3] = 0,
                       .bits[4] = 0,
                       .bits[5] = 0};

  s21_dec_buf sum = {.bits[0] = 0,
                     .bits[1] = 0,
                     .bits[2] = 0,
                     .bits[3] = 0,
                     .bits[4] = 0,
                     .bits[5] = 0};

  int shift_ind = 0;
  int iterator = 1;

  while (more_int_m(num1->bits, num2->bits, 6) ||
         equal_int_m(num1->bits, num2->bits, 6)) {
    iterator++;

    sum_b.bits[0] = 1;
    sum_b.bits[1] = 0;
    sum_b.bits[2] = 0;
    sum_b.bits[3] = 0;
    sum_b.bits[4] = 0;
    sum_b.bits[5] = 0;

    while (1) {
      tmp1 = shift(num2->bits, shift_ind, 6);

      if (equal_int_m(num1->bits, num2->bits, 6)) {
        tmp2 = *num1;
        break;
      }

      if (!less_int_m(tmp1.bits, num1->bits, 6)) {
        if (shift_ind == 0) {
        }
        sum_b = shift(sum_b.bits, shift_ind - 1, 6);
        break;
      }

      tmp2 = shift(num2->bits, shift_ind, 6);

      shift_ind++;
    }
    shift_ind = 0;

    sum_buf_buf(&sum, &sum_b);

    if (less_int_m(tmp2.bits, num1->bits, 6) ||
        equal_int_m(tmp2.bits, num1->bits, 6)) {
      *num1 = diff_buf(*num1, tmp2);
    } else {
      break;
    }
  }

  return sum;
}
