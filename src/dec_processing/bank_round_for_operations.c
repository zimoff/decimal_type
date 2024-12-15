#include <stdio.h>

#include "../s21_decimal.h"

s21_dec_buf bank_round_for_operations(s21_dec_buf num, int* exp) {
  int res_exp = *exp;
  s21_dec_buf divider = {.bits[0] = 10,
                         .bits[1] = 0,
                         .bits[2] = 0,
                         .bits[3] = 0,
                         .bits[4] = 0,
                         .bits[5] = 0};

  s21_dec_buf res = num;

  s21_dec_buf one = {.bits[0] = 1,
                     .bits[1] = 0,
                     .bits[2] = 0,
                     .bits[3] = 0,
                     .bits[4] = 0,
                     .bits[5] = 0};

  s21_dec_buf rem = {.bits[0] = 0,
                     .bits[1] = 0,
                     .bits[2] = 0,
                     .bits[3] = 0,
                     .bits[4] = 0,
                     .bits[5] = 0};

  /*int count = 0;*/

  /*printf("res exp before: %d\n", res_exp);*/

  if (res_exp < 0) {
    /*printf("round less zero \n");*/
    /*while (buf_length_meter(num) && (res_exp < 0) ) {*/
    while (res_exp < 0) {
      mul_buf(num, divider, &res);

      /*rem = num;*/
      num = res;
      /*count++;*/
      res_exp++;
    }
  }

  if (res_exp > 0) {
    /*printf("round more zero \n");*/
    while ((buf_length_meter(num) && (res_exp > 0)) || (res_exp > 28)) {
      res = div_buf(&num, &divider);

      rem = num;
      num = res;
      /*count++;*/
      res_exp--;
    }
  }

  /*printf("res exp after: %d\n", res_exp);*/

  if (rem.bits[0] == 5) {
    if (get_bit_buf(&res, 0)) {
      sum_buf_buf(&res, &one);
    }
  }

  if (rem.bits[0] > 5) {
    sum_buf_buf(&res, &one);
  }

  res.exp = res_exp;

  return res;
}
