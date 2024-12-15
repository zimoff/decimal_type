#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int sign_src = get_bit(src.bits + 3, 31);

  int exp = get_exp(src);
  if (exp == 0) exp = -1;
  s21_dec_buf rem = dec_to_buf(&src);
  s21_dec_buf ten = {{10, 0, 0, 0}, 0};
  s21_dec_buf tmp = {{0, 0, 0, 0}, 0};

  char num_arr[31];

  for (int i = 0; i < 31; i++) {
    if (i == 30)
      num_arr[i] = '\0';
    else
      num_arr[i] = '$';
  }

  int index = 29;
  int rem_zero = 0;

  do {
    if ((unsigned int)rem.bits[0] > 0) {
      tmp = div_buf(&rem, &ten);

      if (exp == 0) {
        num_arr[index] = '.';
        index--;
        exp--;
      }

      num_arr[index] = (unsigned int)rem.bits[0] + 48;
      index--;

      rem = tmp;
    } else {
      num_arr[index] = '0';
      index--;
    }

    if (exp > 0) exp--;

    if ((rem.bits[0] == 0) && (exp > 0)) rem_zero = -1;

  } while (((unsigned int)rem.bits[0] > 0) || (exp > 0));

  if ((rem_zero == -1) || ((rem.bits[0] == 0) && (exp == 0))) {
    num_arr[index] = '.';
    index--;
    num_arr[index] = '0';
  } else if (rem.bits[0] == 0) {
    index++;
  }

  double dst_res = 0;

  dst_res = atof(num_arr + index);

  *dst = (float)dst_res;

  if (sign_src) *dst *= -1;

  return 0;
}
