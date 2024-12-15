#include <check.h>
#include <limits.h>

#include "../s21_decimal.h"

START_TEST(test_int_dec_loop) {
  int int_num = _i;
  s21_decimal dec_num;

  s21_from_int_to_decimal(int_num, &dec_num);
  s21_from_decimal_to_int(dec_num, &int_num);

  ck_assert_int_eq(int_num, _i);
}
END_TEST

START_TEST(test_int_dec_MAX) {
  int int_num = 0;
  s21_decimal dec_num;

  s21_from_int_to_decimal(INT_MAX, &dec_num);
  s21_from_decimal_to_int(dec_num, &int_num);

  ck_assert_int_eq(int_num, INT_MAX);
}
END_TEST

START_TEST(test_int_dec_MIN) {
  int int_num = 0;
  s21_decimal dec_num;

  s21_from_int_to_decimal(INT_MIN, &dec_num);
  s21_from_decimal_to_int(dec_num, &int_num);

  ck_assert_int_eq(int_num, INT_MIN);
}
END_TEST

START_TEST(test_int_dec_zero) {
  int int_num = 21;
  s21_decimal dec_num;

  s21_from_int_to_decimal(0, &dec_num);
  s21_from_decimal_to_int(dec_num, &int_num);

  ck_assert_int_eq(int_num, 0);
}
END_TEST

Suite *test_int_dec_convertation() {
  Suite *s = NULL;
  TCase *tc_int_dec_conv = NULL;

  s = suite_create("int_to_dec_suite");
  tc_int_dec_conv = tcase_create("int_to_dec_case");

  tcase_add_loop_test(tc_int_dec_conv, test_int_dec_loop, -1000, 1000);
  tcase_add_test(tc_int_dec_conv, test_int_dec_MAX);
  tcase_add_test(tc_int_dec_conv, test_int_dec_MIN);
  tcase_add_test(tc_int_dec_conv, test_int_dec_zero);

  suite_add_tcase(s, tc_int_dec_conv);

  return s;
}
