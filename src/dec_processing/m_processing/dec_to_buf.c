#include <stdio.h>

#include "../../s21_decimal.h"

s21_dec_buf dec_to_buf(s21_decimal* dec_num) {
  s21_dec_buf buf_num = {.bits[0] = dec_num->bits[0],
                         .bits[1] = dec_num->bits[1],
                         .bits[2] = dec_num->bits[2],
                         .bits[3] = 0,
                         .bits[4] = 0,
                         .bits[5] = 0,
                         .exp = get_exp(*dec_num)};

  return buf_num;
}
