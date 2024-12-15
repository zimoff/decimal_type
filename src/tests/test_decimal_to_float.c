#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_decimal.h"

START_TEST(dec_fl_conv_0) {
  float num = 0;
  s21_decimal val1 = {{1, 0, 0, 0}};
  set_exp(&val1, 28);

  s21_from_decimal_to_float(val1, &num);

  ck_assert_float_eq(num, 1e-28f);
}
END_TEST

START_TEST(dec_fl_conv_1) {
  float num = 0;
  s21_decimal val1 = {{1, 0, 0, 0}};
  set_exp(&val1, 28);
  set_bit(val1.bits + 3, 31);

  s21_from_decimal_to_float(val1, &num);

  ck_assert_float_eq(num, -1e-28f);
}
END_TEST

START_TEST(dec_fl_conv_3) {
  float num = 0;
  s21_decimal val1 = {{123456, 0, 0, 0}};
  set_exp(&val1, 3);

  s21_from_decimal_to_float(val1, &num);

  ck_assert_float_eq(num, 123.456f);
}
END_TEST

START_TEST(dec_fl_conv_4) {
  float num = 0;
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};

  s21_from_decimal_to_float(val1, &num);

  ck_assert_float_eq(num, 7.9228163E+28f);
}
END_TEST

START_TEST(dec_fl_conv_5) {
  float num = 0;
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  set_bit(val1.bits + 3, 31);

  s21_from_decimal_to_float(val1, &num);

  ck_assert_float_eq(num, -7.9228163E+28f);
}
END_TEST

START_TEST(dec_fl_conv_6) {
  float num = 0;
  s21_decimal val1 = {{-1935933440, -885951191, 429496729, 0}};

  s21_from_decimal_to_float(val1, &num);

  ck_assert_float_eq(num, 7.9228164E+27);
}
END_TEST

START_TEST(dec_fl_conv_7) {
  float num = 0;
  s21_decimal val1 = {{-1935933440, -885951191, 429496729, -2147483648}};

  s21_from_decimal_to_float(val1, &num);

  ck_assert_float_eq(num, -7.9228164E+27);
}
END_TEST

START_TEST(dec_fl_conv_8) {
  float num = 0;

  s21_decimal val1 = {{5, 0, 0, 0}};
  set_bit(val1.bits + 3, 31);

  s21_from_decimal_to_float(val1, &num);

  ck_assert_float_eq(num, -5);
}
END_TEST

START_TEST(dec_fl_conv_9) {
  float num = 0;

  s21_decimal val1 = {{5, 0, 0, 0}};

  s21_from_decimal_to_float(val1, &num);

  ck_assert_float_eq(num, 5);
}
END_TEST

START_TEST(dec_fl_conv_10) {
  float num = 0;

  s21_decimal val1 = {{268435461, 1042612833, 542101086, 0}};

  s21_from_decimal_to_float(val1, &num);

  ck_assert_float_eq(num, 1E+28);
}
END_TEST

START_TEST(dec_fl_conv_11) {
  float num = 0;

  s21_decimal val1 = {{268435461, 1042612833, 542101086, -2147483648}};

  s21_from_decimal_to_float(val1, &num);

  ck_assert_float_eq(num, -1E+28);
}
END_TEST

START_TEST(dec_fl_conv_12) {
  float num = 0;

  s21_decimal val1 = {{-291504128, 1945022502, 542101140, 0}};

  s21_from_decimal_to_float(val1, &num);

  ck_assert_float_eq(num, 1.0000001E+28);
}
END_TEST

START_TEST(dec_fl_conv_13) {
  float num = 0;

  s21_decimal val1 = {{-291504123, 1945022502, 542101140, -2147483648}};

  s21_from_decimal_to_float(val1, &num);

  ck_assert_float_eq(num, -1.0000001E+28);
}
END_TEST

START_TEST(dec_fl_conv_14) {
  float num = 0;

  s21_decimal val1 = {{1930428416, -1444126578, 542101091, 0}};

  s21_from_decimal_to_float(val1, &num);

  ck_assert_float_eq(num, 1.0000001E+28);
}
END_TEST

START_TEST(dec_fl_conv_15) {
  float num = 0;

  s21_decimal val1 = {{1930428421, -1444126578, 542101091, -2147483648}};

  s21_from_decimal_to_float(val1, &num);

  ck_assert_float_eq(num, -1.0000001E+28);
}
END_TEST

START_TEST(dec_fl_conv_16) {
  float num = 0;

  s21_decimal val1 = {{-11534336, 1493817667, 542101113, 0}};

  s21_from_decimal_to_float(val1, &num);

  ck_assert_float_eq(num, 1.0000001E+28);
}
END_TEST

START_TEST(dec_fl_conv_17) {
  float num = 0;

  s21_decimal val1 = {{-11534331, 1493817667, 542101113, -2147483648}};

  s21_from_decimal_to_float(val1, &num);

  ck_assert_float_eq(num, -1.0000001E+28);
}
END_TEST

Suite *test_dec_fl() {
  Suite *s = NULL;
  TCase *tc_dec_fl = NULL;

  s = suite_create("dec_fl_test");
  tc_dec_fl = tcase_create("dec_fl_case");

  tcase_add_test(tc_dec_fl, dec_fl_conv_0);
  tcase_add_test(tc_dec_fl, dec_fl_conv_1);
  tcase_add_test(tc_dec_fl, dec_fl_conv_3);
  tcase_add_test(tc_dec_fl, dec_fl_conv_4);
  tcase_add_test(tc_dec_fl, dec_fl_conv_5);
  tcase_add_test(tc_dec_fl, dec_fl_conv_6);
  tcase_add_test(tc_dec_fl, dec_fl_conv_7);
  tcase_add_test(tc_dec_fl, dec_fl_conv_8);
  tcase_add_test(tc_dec_fl, dec_fl_conv_9);
  tcase_add_test(tc_dec_fl, dec_fl_conv_10);
  tcase_add_test(tc_dec_fl, dec_fl_conv_11);
  tcase_add_test(tc_dec_fl, dec_fl_conv_12);
  tcase_add_test(tc_dec_fl, dec_fl_conv_13);
  tcase_add_test(tc_dec_fl, dec_fl_conv_14);
  tcase_add_test(tc_dec_fl, dec_fl_conv_15);
  tcase_add_test(tc_dec_fl, dec_fl_conv_16);
  tcase_add_test(tc_dec_fl, dec_fl_conv_17);

  suite_add_tcase(s, tc_dec_fl);

  return s;
}
