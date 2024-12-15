#include <stdio.h>
#include <string.h>

#include "../s21_decimal.h"
/*#include "../s21_dec_processing.h"*/

int s21_negate(s21_decimal value, s21_decimal *result) {
  int sign_val = get_bit(value.bits + 3, 31);

  *result = value;

  if (sign_val)
    reset_bit(result->bits + 3, 31);
  else
    set_bit(result->bits + 3, 31);

  return 0;
}
