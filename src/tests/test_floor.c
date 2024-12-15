#include <check.h>
#include <limits.h>
#include <stdio.h>

#include "../s21_decimal.h"

START_TEST(floor_0) {
  s21_decimal val = {{2, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  ck_assert_int_eq(0, s21_floor(val, &res));
}
END_TEST

START_TEST(floor_ad_0) {
  s21_decimal val = {{-1, -1, -1, 65536}};
  s21_decimal res_t = {{-1717986919, -1717986919, 429496729, 0}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_floor(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(floor_ad_1) {
  s21_decimal val = {{-1, -1, -1, -2147418112}};
  s21_decimal res_t = {{-1717986918, -1717986919, 429496729, -2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_floor(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(floor_ad_2) {
  s21_decimal val = {{1, 0, 0, -2147418112}};
  s21_decimal res_t = {{1, 0, 0, -2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_floor(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(floor_ad_3) {
  s21_decimal val = {{1, 0, 0, 65536}};
  s21_decimal res_t = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_floor(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(floor_ad_4) {
  s21_decimal val = {{0, 0, 0, 0}};
  s21_decimal res_t = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_floor(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(floor_ad_5) {
  s21_decimal val = {{0, 0, 0, 0}};
  s21_decimal res_t = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_floor(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(floor_ad_6) {
  s21_decimal val = {{5, 0, 0, -2147418112}};
  s21_decimal res_t = {{1, 0, 0, -2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_floor(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(floor_ad_7) {
  s21_decimal val = {{15, 0, 0, -2147418112}};
  s21_decimal res_t = {{2, 0, 0, -2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_floor(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(floor_ad_8) {
  s21_decimal val = {{5, 0, 0, 65536}};
  s21_decimal res_t = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_floor(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(floor_ad_9) {
  s21_decimal val = {{15, 0, 0, 65536}};
  s21_decimal res_t = {{1, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_floor(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(floor_ad_10) {
  s21_decimal val = {{12, 0, 0, 65536}};
  s21_decimal res_t = {{1, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_floor(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(floor_ad_11) {
  s21_decimal val = {{16, 0, 0, 65536}};
  s21_decimal res_t = {{1, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_floor(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(floor_ad_12) {
  s21_decimal val = {{12, 0, 0, -2147418112}};
  s21_decimal res_t = {{2, 0, 0, -2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_floor(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(floor_ad_13) {
  s21_decimal val = {{16, 0, 0, -2147418112}};
  s21_decimal res_t = {{2, 0, 0, -2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_floor(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(floor_ad_14) {
  s21_decimal val = {{2, 0, 0, -2147418112}};
  s21_decimal res_t = {{1, 0, 0, -2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_floor(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(floor_ad_15) {
  s21_decimal val = {{6, 0, 0, -2147418112}};
  s21_decimal res_t = {{1, 0, 0, -2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_floor(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(floor_ad_16) {
  s21_decimal val = {{2, 0, 0, 65536}};
  s21_decimal res_t = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_floor(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

START_TEST(floor_ad_17) {
  s21_decimal val = {{6, 0, 0, 65536}};
  s21_decimal res_t = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};

  s21_floor(val, &res);

  ck_assert_int_eq(1, s21_is_equal(res, res_t));
}
END_TEST

Suite *test_floor() {
  Suite *s = NULL;
  TCase *tc_floor = NULL;

  s = suite_create("test_floor_suite");
  tc_floor = tcase_create("floor_case");

  tcase_add_test(tc_floor, floor_0);
  tcase_add_test(tc_floor, floor_ad_0);
  tcase_add_test(tc_floor, floor_ad_1);
  tcase_add_test(tc_floor, floor_ad_2);
  tcase_add_test(tc_floor, floor_ad_3);
  tcase_add_test(tc_floor, floor_ad_4);
  tcase_add_test(tc_floor, floor_ad_5);
  tcase_add_test(tc_floor, floor_ad_6);
  tcase_add_test(tc_floor, floor_ad_7);
  tcase_add_test(tc_floor, floor_ad_8);
  tcase_add_test(tc_floor, floor_ad_9);
  tcase_add_test(tc_floor, floor_ad_10);
  tcase_add_test(tc_floor, floor_ad_11);
  tcase_add_test(tc_floor, floor_ad_12);
  tcase_add_test(tc_floor, floor_ad_13);
  tcase_add_test(tc_floor, floor_ad_14);
  tcase_add_test(tc_floor, floor_ad_15);
  tcase_add_test(tc_floor, floor_ad_16);
  tcase_add_test(tc_floor, floor_ad_17);

  suite_add_tcase(s, tc_floor);

  return s;
}
