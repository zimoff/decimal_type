#include <stdio.h>

#include "../../s21_decimal.h"

s21_dec_buf diff_buf(s21_dec_buf s1, s21_dec_buf s2) {
  int mem = 0;
  int diff_bit;
  for (int i = 0; i < 192; i++) {
    diff_bit = get_bit(&s1.bits[i / 32], i % 32) -
               get_bit(&s2.bits[i / 32], i % 32) - mem;
    if (diff_bit < 0) {
      mem = 1;  // в уме
    } else
      mem = 0;
    if (diff_bit % 2) {
      set_bit(&s1.bits[i / 32], i % 32);
    } else {
      reset_bit(&s1.bits[i / 32], i % 32);
    }
  }
  /*if (mem == 1) {*/
  /*[>printf("minus\n");<]*/
  /*[>set_bit(&s1.bits[3], 31);<]*/
  /*}*/

  return s1;
}
