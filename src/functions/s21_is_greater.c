#include <stdio.h>
#include <string.h>

#include "../s21_decimal.h"

int s21_is_greater(s21_decimal num1, s21_decimal num2) {
  if (s21_is_equal(num1, num2)) return 0;

  int res = 0;

  int sign_val1 = get_bit(num1.bits + 3, 31);
  int sign_val2 = get_bit(num2.bits + 3, 31);

  s21_dec_buf num1_buf = {{0, 0, 0, 0, 0, 0}, 0};
  s21_dec_buf num2_buf = {{0, 0, 0, 0, 0, 0}, 0};

  if (sign_val1 == sign_val2) {
    /*printf("sign eq: \n");*/

    normalizator(num1, num2, &num1_buf, &num2_buf);

    if (sign_val1)
      res = !more_int_m(num1_buf.bits, num2_buf.bits, 6);
    else
      res = more_int_m(num1_buf.bits, num2_buf.bits, 6);

  } else {
    res = (!sign_val1) ? 1 : 0;
  }

  return res;
}
