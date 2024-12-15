#include <stdio.h>

#include "../../s21_decimal.h"

int less_int_m(int* s1, int* s2, int size) {
  int less = 0;

  for (int i = (32 * size) - 1; i >= 0; i--) {
    if (get_bit(&s2[i / 32], i % 32) > get_bit(&s1[i / 32], i % 32)) {
      less = 1;
      break;
    }

    if (get_bit(&s2[i / 32], i % 32) < get_bit(&s1[i / 32], i % 32)) {
      less = 0;
      break;
    }
  }

  return less;
}

int more_int_m(int* s1, int* s2, int size) {
  int more = 0;

  for (int i = (32 * size) - 1; i >= 0; i--) {
    if (get_bit(&s1[i / 32], i % 32) > get_bit(&s2[i / 32], i % 32)) {
      more = 1;
      break;
    }
    if (get_bit(&s1[i / 32], i % 32) < get_bit(&s2[i / 32], i % 32)) {
      more = 0;
      break;
    }
  }

  return more;
}

int equal_int_m(int* s1, int* s2, int size) {
  int eq = 1;
  for (int i = (size * 32) - 1; i >= 0; i--) {
    if (get_bit(&s2[i / 32], i % 32) != get_bit(&s1[i / 32], i % 32)) {
      eq = 0;
      break;
    }
  }

  return eq;
}

int is_dec_zero(s21_decimal num1) {
  int res = 1;
  for (int i = 0; i < 3; i++) {
    if (num1.bits[i] != 0) {
      res = 0;
      break;
    }
  }

  return res;
}
