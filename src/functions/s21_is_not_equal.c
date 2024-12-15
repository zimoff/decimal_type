#include <stdio.h>
#include <string.h>

#include "../s21_decimal.h"

int s21_is_not_equal(s21_decimal num1, s21_decimal num2) {
  return !s21_is_equal(num1, num2);
}
/*int res = 0;*/
/*int sign_val1 = get_bit(num1.bits + 3, 31);*/
/*int sign_val2 = get_bit(num2.bits + 3, 31);*/

/*s21_dec_buf num1_buf = {{0, 0, 0, 0, 0, 0}, 0};*/
/*s21_dec_buf num2_buf = {{0, 0, 0, 0, 0, 0}, 0};*/

/*if (sign_val1 != sign_val2)*/
/*res = 0;*/
/*else {*/
/*normalizator(num1, num2, &num1_buf, &num2_buf);*/

/*if (!equal_int_m(num1_buf.bits, num2_buf.bits, 6)) res = 1;*/
/*}*/

/*return res;*/
