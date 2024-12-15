#include <check.h>
#include <limits.h>
#include <stdio.h>

#include "../s21_decimal.h"

START_TEST(negate_0) {
  s21_decimal val = {{2, 0, 0, 0}};
  s21_decimal res = {0};

  int sign_before = get_bit(val.bits + 3, 31);
  s21_negate(val, &res);
  int sign_after = get_bit(res.bits + 3, 31);

  ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

START_TEST(negate_1) {
  s21_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {0};
  int sign_before = get_bit(val.bits + 3, 31);
  s21_negate(val, &res);
  int sign_after = get_bit(res.bits + 3, 31);
  ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

START_TEST(negate_2) {
  s21_decimal val = {{0, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {0};
  int sign_before = get_bit(val.bits + 3, 31);
  s21_negate(val, &res);
  int sign_after = get_bit(res.bits + 3, 31);
  ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

START_TEST(negate_3) {
  s21_decimal val = {0};
  s21_decimal res = {0};
  int sign_before = get_bit(val.bits + 3, 31);
  s21_negate(val, &res);
  int sign_after = get_bit(res.bits + 3, 31);
  ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

Suite *test_nagete() {
  Suite *s = NULL;
  TCase *tc_negate = NULL;

  s = suite_create("negate_test");
  tc_negate = tcase_create("negate_case");

  tcase_add_test(tc_negate, negate_0);
  tcase_add_test(tc_negate, negate_1);
  tcase_add_test(tc_negate, negate_2);
  tcase_add_test(tc_negate, negate_3);

  suite_add_tcase(s, tc_negate);

  return s;
}
