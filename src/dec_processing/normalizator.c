#include <stdio.h>

#include "../s21_decimal.h"

int normalizator(s21_decimal num1, s21_decimal num2, s21_dec_buf* num_buf1,
                 s21_dec_buf* num_buf2) {
  num_buf1->exp = get_exp(num1);
  num_buf2->exp = get_exp(num2);

  *num_buf1 = dec_to_buf(&num1);
  *num_buf2 = dec_to_buf(&num2);

  s21_dec_buf multipler = {.bits[0] = 10,
                           .bits[1] = 0,
                           .bits[2] = 0,
                           .bits[3] = 0,
                           .bits[4] = 0,
                           .bits[5] = 0};

  if (num_buf1->exp != num_buf2->exp) {
    if (num_buf1->exp < num_buf2->exp) {
      while ((num_buf1->exp != num_buf2->exp) && (num_buf1->exp < 28)) {
        mul_buf(*num_buf1, multipler, num_buf1);
        num_buf1->exp++;
      }

    } else {
      while ((num_buf1->exp != num_buf2->exp) && (num_buf2->exp < 28)) {
        mul_buf(*num_buf2, multipler, num_buf2);
        num_buf2->exp++;
      }
    }
  }

  return 0;
}
