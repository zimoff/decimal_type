#include <stdio.h>

#include "../s21_decimal.h"

int set_bit(int* num, size_t bit_num) {
  int res = 0;

  if (bit_num > 0 || bit_num < 32)
    *num = *num | (1 << bit_num);
  else
    res = 1;

  return res;
}

int get_bit(int* num, size_t bit_num) {
  int res = 0;

  if ((*num & (1 << bit_num)) == 0)
    res = 0;
  else
    res = 1;

  return res;
}

int set_bit_buf(s21_dec_buf* dec_buf, size_t bit_num) {
  int res = 0;
  if (bit_num < 192)
    set_bit(dec_buf->bits + (bit_num / 32), bit_num % 32);
  else
    res = -1;
  return res;
}

int get_bit_buf(s21_dec_buf* dec_buf, size_t bit_num) {
  int res = 0;
  if (bit_num < 192)
    res = get_bit(dec_buf->bits + (bit_num / 32), bit_num % 32);
  else
    res = -1;
  return res;
}

int set_dec(s21_decimal* dec, size_t bit_num) {
  int res = 0;
  if (bit_num < 96)
    set_bit(dec->bits + (bit_num / 32), bit_num % 32);
  else
    res = -1;
  return res;
}

int get_dec(s21_decimal dec, size_t bit_num) {
  int res = 0;
  if (bit_num < 96) {
    res = get_bit(dec.bits + (bit_num / 32), bit_num % 32);
    // printf("dec bits: %ld| bit num: %ld\n", bit_num / 32, bit_num % 32);
  } else
    res = -1;
  return res;
}

int reset_bit(int* num, int bit_num) {
  int res = 0;

  if (bit_num > 0 || bit_num < 32)
    *num = *num & (~(1 << bit_num));
  else
    res = 1;

  return res;
}

int reset_bit_buf(s21_dec_buf* dec_buf, size_t bit_num) {
  int res = 0;
  if (bit_num < 192)
    reset_bit(dec_buf->bits + (bit_num / 32), bit_num % 32);
  else
    res = -1;
  return res;
}

int get_exp(s21_decimal num) {
  int exp = 0;

  for (int i = 0; i < 8; i++) {
    //    printf("%d", get_bit(&num.bits[3], 16 + i));
    if (get_bit(&num.bits[3], 16 + i)) set_bit(&exp, i);
  }
  return exp;
}

void set_exp(s21_decimal* num, int exp) {
  int minus = get_bit(&num->bits[3], 31);

  num->bits[3] = exp << 16;
  if (minus) set_bit(&num->bits[3], 31);
}
