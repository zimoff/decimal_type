#include <stdio.h>

#include "../../s21_decimal.h"

int sum_buf_buf(s21_dec_buf* dec_buf, s21_dec_buf* dec_num) {
  int len = 192;

  int mem = 0;
  int num = 0;
  int buf = 0;
  int x = 0;

  for (int i = 0; i < len; i++) {
    num = get_bit_buf(dec_num, i);
    buf = get_bit_buf(dec_buf, i);
    x = x_or(num, buf);

    if (x_or(x, mem)) {
      mem = ((num && buf) || (x && mem)) ? 1 : 0;
      set_bit_buf(dec_buf, i);
    } else {
      mem = ((num && buf) || (x && mem)) ? 1 : 0;
      reset_bit_buf(dec_buf, i);
    }
  }

  return 0;
}
