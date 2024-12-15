#include <math.h>
#include <stdio.h>
#include <string.h>

#include "../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  if (fabs(src) < 2e-28) {
    dst->bits[0] = 0;
    dst->bits[1] = 0;
    dst->bits[2] = 0;
    dst->bits[3] = 0;
    return 1;
  }
  if (fabs(src) > 2e96 - 1) {
    return 1;
  }
  int res = 0;

  int length = 0;
  char f_tmp[28];
  memset(f_tmp, '\0', 28);
  int sign = (src < 0) ? 1 : 0;

  if (src < 0) src *= -1;

  s21_decimal dec_tmp = {{0, 0, 0, 0}};
  /*s21_decimal dec_res = {{0,0,0,0}};*/
  s21_decimal dec_ten = {{10, 0, 0, 0}};

  dst->bits[0] = 0;
  dst->bits[1] = 0;
  dst->bits[2] = 0;
  dst->bits[3] = 0;

  int exp = 0;

  snprintf(f_tmp, 28, "%.7f", src);

  for (int i = 27; i >= 0; i--) {
    if ((f_tmp[i] < 58) && (f_tmp[i] > 48)) {
      exp++;
    } else if (exp > 0) {
      exp++;
    }

    if (f_tmp[i] == '.') break;
  }

  if (exp > 0) exp--;

  for (int i = 27; i >= 0; i--) {
    if ((f_tmp[i] < 58) && (f_tmp[i] > 48)) {
      f_tmp[i + 1] = '\0';
      break;
    }
  }

  length = strlen(f_tmp);
  int num_counter = 0;

  for (int i = length - 1; i >= 0; i--) {
    if ((f_tmp[i] < 58) && (f_tmp[i] > 47)) {
      dec_tmp.bits[0] = f_tmp[i] - 48;

      for (int j = num_counter; j > 0; j--) {
        s21_mul(dec_tmp, dec_ten, &dec_tmp);
      }
      s21_add(dec_tmp, *dst, dst);

      dec_tmp.bits[0] = 0;
      dec_tmp.bits[1] = 0;
      dec_tmp.bits[2] = 0;
      dec_tmp.bits[3] = 0;
      num_counter++;
    }
  }

  set_exp(dst, exp);
  if (sign == 1) set_bit(dst->bits + 3, 31);

  return res;
}
