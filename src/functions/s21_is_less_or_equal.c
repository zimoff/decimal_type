#include <stdio.h>
#include <string.h>

#include "../s21_decimal.h"
/*#include "../s21_dec_processing.h"*/

int s21_is_less_or_equal(s21_decimal num1, s21_decimal num2) {
  return s21_is_equal(num1, num2) || s21_is_less(num1, num2);
}
