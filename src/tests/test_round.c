#include <check.h>
#include <limits.h>
#include <stdio.h>

#include "../s21_decimal.h"

START_TEST(round_0) {
  s21_decimal val = {{7, 7, 7, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal res1 = {{7, 7, 7, 0}};
  s21_round(val, &res);
  ck_assert_int_eq(1, s21_is_equal(res, res1));
}
END_TEST

START_TEST(round_1) {
  s21_decimal val = {{3, 3, 3, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0, 0, 0, 0}};
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(round_2) {
  s21_decimal val = {{3, 3, 3, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  /*setPow(&val, 5);*/
  set_exp(&val, 5);
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(round_3) {
  s21_decimal val = {{7, 7, 7, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0, 0, 0, 0}};
  set_exp(&val, 5);
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(round_4) {
  s21_decimal val = {{25, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0, 0, 0, 0}};
  set_exp(&val, 1);
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(round_ad_0) {
  s21_decimal val = {{-1, -1, -1, 65536}};
  s21_decimal res_t = {{-1717986918, -1717986919, 429496729, 0}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_round(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(round_ad_1) {
  s21_decimal val = {{-1, -1, -1, -2147418112}};
  s21_decimal res_t = {{-1717986918, -1717986919, 429496729, -2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_round(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(round_ad_2) {
  s21_decimal val = {{1, 0, 0, -2147418112}};
  s21_decimal res_t = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_round(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(round_ad_3) {
  s21_decimal val = {{1, 0, 0, 65536}};
  s21_decimal res_t = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_round(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(round_ad_4) {
  s21_decimal val = {{0, 0, 0, 0}};
  s21_decimal res_t = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_round(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(round_ad_5) {
  s21_decimal val = {{0, 0, 0, 0}};
  s21_decimal res_t = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_round(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(round_ad_6) {
  s21_decimal val = {{5, 0, 0, -2147418112}};
  s21_decimal res_t = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_round(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(round_ad_7) {
  s21_decimal val = {{15, 0, 0, -2147418112}};
  s21_decimal res_t = {{2, 0, 0, -2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_round(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(round_ad_8) {
  s21_decimal val = {{5, 0, 0, 65536}};
  s21_decimal res_t = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_round(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(round_ad_9) {
  s21_decimal val = {{15, 0, 0, 65536}};
  s21_decimal res_t = {{2, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_round(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(round_ad_10) {
  s21_decimal val = {{12, 0, 0, 65536}};
  s21_decimal res_t = {{1, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_round(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(round_ad_11) {
  s21_decimal val = {{16, 0, 0, 65536}};
  s21_decimal res_t = {{2, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_round(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(round_ad_12) {
  s21_decimal val = {{12, 0, 0, -2147418112}};
  s21_decimal res_t = {{1, 0, 0, -2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_round(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(round_ad_13) {
  s21_decimal val = {{16, 0, 0, -2147418112}};
  s21_decimal res_t = {{2, 0, 0, -2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_round(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(round_ad_14) {
  s21_decimal val = {{2, 0, 0, -2147418112}};
  s21_decimal res_t = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_round(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(round_ad_15) {
  s21_decimal val = {{6, 0, 0, -2147418112}};
  s21_decimal res_t = {{1, 0, 0, -2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_round(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(round_ad_16) {
  s21_decimal val = {{2, 0, 0, 65536}};
  s21_decimal res_t = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_round(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(round_ad_17) {
  s21_decimal val = {{6, 0, 0, 65536}};
  s21_decimal res_t = {{1, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_round(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

Suite *test_round() {
  Suite *s = NULL;
  TCase *tc_round = NULL;

  s = suite_create("test_round_suite");
  tc_round = tcase_create("round_case");

  tcase_add_test(tc_round, round_0);
  tcase_add_test(tc_round, round_1);
  tcase_add_test(tc_round, round_2);
  tcase_add_test(tc_round, round_3);
  tcase_add_test(tc_round, round_4);
  tcase_add_test(tc_round, round_ad_0);
  tcase_add_test(tc_round, round_ad_1);
  tcase_add_test(tc_round, round_ad_2);
  tcase_add_test(tc_round, round_ad_3);
  tcase_add_test(tc_round, round_ad_4);
  tcase_add_test(tc_round, round_ad_5);
  tcase_add_test(tc_round, round_ad_6);
  tcase_add_test(tc_round, round_ad_7);
  tcase_add_test(tc_round, round_ad_8);
  tcase_add_test(tc_round, round_ad_9);
  tcase_add_test(tc_round, round_ad_10);
  tcase_add_test(tc_round, round_ad_11);
  tcase_add_test(tc_round, round_ad_12);
  tcase_add_test(tc_round, round_ad_13);
  tcase_add_test(tc_round, round_ad_14);
  tcase_add_test(tc_round, round_ad_15);
  tcase_add_test(tc_round, round_ad_16);
  tcase_add_test(tc_round, round_ad_17);

  suite_add_tcase(s, tc_round);

  return s;
}
