#include <stdio.h>

#include "../../s21_decimal.h"
/*#include "../../s21_dec_processing.h"*/

/*s21_decimal shift(s21_decimal num, int shift_num){*/
s21_dec_buf shift(int *num, int shift_num, int size) {
  s21_dec_buf res;

  /*printf("---copy----\n");*/
  for (int i = 0; i < size; i++) {
    /*show_num(num + i);*/
    res.bits[i] = num[i];
  }
  /*printf("-------\n");*/

  size -= 1;

  /*printf("start res in: \n");*/
  /*show_dec_buf(res);*/

  int b_shift = (shift_num / 32);

  /*printf("start shift: \n");*/
  /*printf("size: %d \n", size);*/
  /*printf("in shift: %d\n", shift_num);*/
  /*printf("b_shift: %d\n", b_shift);*/

  /*for(int i = 0; i < b_shift; i++){*/
  /*printf("i: %d\n", i);*/
  for (int j = size; j >= 0; j--) {
    if ((j - b_shift) < 0) {
      /*printf("j: %d | b_shift: %d | diff: %d minus \n", j, b_shift, (j -
       * b_shift));*/
      res.bits[j] = 0;
    } else {
      /*printf("j: %d | b_shift: %d | diff: %d positive \n", j, b_shift, (j -
       * b_shift));*/
      res.bits[j] = res.bits[j - b_shift];
    }
  }
  //}

  /*printf("-------------\n");*/
  /*printf("half set:\n");*/
  /*show_num(num);*/
  /*show_num(num + 1);*/
  /*show_num(num + 2);*/
  /*show_num(num + 3);*/
  /*show_num(num + 4);*/
  /*show_num(num + 5);*/
  /*printf("-------------\n");*/

  int bit_ind = size;
  size -= b_shift;
  /*printf("bit_ind: %d\n", bit_ind);*/
  /*printf("size: %d\n", size);*/
  /*printf("local shift: %d\n", shift_num % 32);*/
  while (size >= 0) {
    /*printf("inner bit iteration:\n");*/

    /*printf("before num[%d]: %d\n", bit_ind, num[bit_ind]);*/
    /*show_num(num + bit_ind);*/
    res.bits[bit_ind] = res.bits[bit_ind] << shift_num % 32;
    /*printf("after num[%d]: %d\n", bit_ind, num[bit_ind]);*/
    /*show_num(num + bit_ind);*/
    /*printf("-------------\n");*/
    // printf("bit ind: %d\n", bit_ind);
    // printf("!!!!!!!-----------\n");
    // show_dec(*num);
    // printf("------------\n");
    // printf("in shift div: %d\n", shift_num % 32);

    for (int i = 0; i < (shift_num % 32) && bit_ind > 0; i++) {
      /*printf("get bit: %d | i: %d | bit_ind: %d\n", get_bit(num + (bit_ind -
       * 1), 31 -i), i, bit_ind);*/
      if (get_bit(res.bits + (bit_ind - 1), 31 - i)) {
        set_bit(res.bits + bit_ind, ((shift_num % 32) - 1) - i);
        // printf("copy bit shift: %d\n", i);
      }
    }

    size--;
    bit_ind--;
  }
  // printf("in shift div: %d\n", shift_num % 32);
  // show_dec(num);
  // printf("------------\n");

  // return num;
  return res;
}
