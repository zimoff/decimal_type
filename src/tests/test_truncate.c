#include <check.h>
#include <limits.h>
#include <stdio.h>

#include "../s21_decimal.h"

START_TEST(truncate_0) {
  s21_decimal val = {{7, 7, 7, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal res1 = {{7, 7, 7, 0}};
  ck_assert_int_eq(0, s21_truncate(val, &res));
  ck_assert_int_eq(1, s21_is_equal(res, res1));
}
END_TEST

START_TEST(truncate_1) {
  s21_decimal val = {{125, 0, 0, 0}};
  set_exp(&val, 1);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal res1 = {{12, 0, 0, 0}};
  ck_assert_int_eq(0, s21_truncate(val, &res));
  ck_assert_int_eq(1, s21_is_equal(res, res1));
}
END_TEST

START_TEST(truncate_2) {
  s21_decimal val = {{10001, 0, 0, 0}};
  set_exp(&val, 4);

  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal res1 = {{1, 0, 0, 0}};

  ck_assert_int_eq(0, s21_truncate(val, &res));
  ck_assert_int_eq(1, s21_is_equal(res, res1));
}
END_TEST

START_TEST(truncate_3) {
  s21_decimal val = {{123456789, 0, 0, 0}};
  set_exp(&val, 5);

  s21_decimal res = {{0, 0, 0, 0}};

  s21_decimal res1 = {{1234, 0, 0, 0}};
  ck_assert_int_eq(0, s21_truncate(val, &res));
  ck_assert_int_eq(1, s21_is_equal(res, res1));
}
END_TEST

START_TEST(truncate_4) {
  s21_decimal val = {{128, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal res1 = {{12, 0, 0, 0}};
  set_exp(&val, 1);
  ck_assert_int_eq(0, s21_truncate(val, &res));
  ck_assert_int_eq(1, s21_is_equal(res, res1));
}
END_TEST

Suite *test_truncate() {
  Suite *s = NULL;
  TCase *tc_truncate = NULL;

  s = suite_create("test_truncate_suite");
  tc_truncate = tcase_create("truncate_case");

  tcase_add_test(tc_truncate, truncate_0);
  tcase_add_test(tc_truncate, truncate_1);
  tcase_add_test(tc_truncate, truncate_2);
  tcase_add_test(tc_truncate, truncate_3);
  tcase_add_test(tc_truncate, truncate_4);

  suite_add_tcase(s, tc_truncate);

  return s;
}
