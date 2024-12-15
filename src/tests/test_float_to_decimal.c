#include <check.h>
#include <limits.h>
#include <stdio.h>

#include "../s21_decimal.h"

START_TEST(fl_dec_conv_0) {
  s21_decimal val = {{13, 0, 0, 0}};
  set_exp(&val, 1);

  s21_decimal res = {{0, 0, 0, 0}};
  float result = 1.3;

  s21_from_float_to_decimal(result, &res);
  ck_assert_int_eq(1, s21_is_equal(val, res));
}
END_TEST

START_TEST(fl_dec_conv_1) {
  s21_decimal val = {{123, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};

  float result = 123;

  s21_from_float_to_decimal(result, &res);
  ck_assert_int_eq(1, s21_is_equal(val, res));
}
END_TEST

START_TEST(fl_dec_conv_2) {
  s21_decimal val = {{1, 0, 0, 458752}};
  s21_decimal res = {{0, 0, 0, 0}};

  float result = 0.0000001f;

  s21_from_float_to_decimal(result, &res);

  ck_assert_int_eq(1, s21_is_equal(val, res));
}
END_TEST

START_TEST(fl_dec_conv_3) {
  s21_decimal val = {{1, 0, 0, 458752}};
  set_bit(val.bits + 3, 31);
  s21_decimal res = {{0, 0, 0, 0}};

  float result = -0.0000001f;

  s21_from_float_to_decimal(result, &res);
  /*printf("val:\n");*/
  /*show_dec(val);*/
  /*printf("res:\n");*/
  /*show_dec(res);*/

  ck_assert_int_eq(1, s21_is_equal(val, res));
}
END_TEST

START_TEST(fl_dec_conv_4) {
  s21_decimal val = {{5, 0, 0, 0}};

  s21_decimal res = {{0, 0, 0, 0}};

  float result = 5;

  s21_from_float_to_decimal(result, &res);
  /*printf("val:\n");*/
  /*show_dec(val);*/
  /*printf("res:\n");*/
  /*show_dec(res);*/

  ck_assert_int_eq(1, s21_is_equal(val, res));
}
END_TEST

START_TEST(fl_dec_conv_5) {
  s21_decimal val = {{5, 0, 0, 0}};
  set_bit(val.bits + 3, 31);

  s21_decimal res = {{0, 0, 0, 0}};

  float result = -5;

  s21_from_float_to_decimal(result, &res);
  /*printf("val:\n");*/
  /*show_dec(val);*/
  /*printf("res:\n");*/
  /*show_dec(res);*/

  ck_assert_int_eq(1, s21_is_equal(val, res));
}
END_TEST

Suite *test_fl_dec() {
  Suite *s = NULL;
  TCase *tc_fl_dec = NULL;

  s = suite_create("fl_dec_test");
  tc_fl_dec = tcase_create("fl_dec_case");

  tcase_add_test(tc_fl_dec, fl_dec_conv_0);
  tcase_add_test(tc_fl_dec, fl_dec_conv_1);
  tcase_add_test(tc_fl_dec, fl_dec_conv_2);
  tcase_add_test(tc_fl_dec, fl_dec_conv_3);
  tcase_add_test(tc_fl_dec, fl_dec_conv_4);
  tcase_add_test(tc_fl_dec, fl_dec_conv_5);
  /*tcase_add_test(tc_div, div_1);*/

  suite_add_tcase(s, tc_fl_dec);

  return s;
}
