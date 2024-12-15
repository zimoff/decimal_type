#include <check.h>
#include <limits.h>
#include <stdio.h>

#include "../s21_decimal.h"
#include "../s21_test.h"

START_TEST(div_array) {
  int div_res = 0;
  int eq_res = 0;
  s21_decimal res_zero = {{0, 0, 0, 0}};

  s21_decimal num_arr_1[50];
  s21_decimal num_arr_2[50];
  s21_decimal div_test_arr[50];

  s21_decimal div_check_arr[50];

  dec_reader("./bin/test_nums_1.bin", num_arr_1);

  dec_reader("./bin/test_nums_2.bin", num_arr_2);

  dec_reader("./bin/div_test_res.bin", div_test_arr);

  for (int i = 0; i < 50; i++) {
    div_res = s21_div(num_arr_1[i], num_arr_2[i], div_check_arr + i);
    if (div_res) div_check_arr[i] = res_zero;

    eq_res = s21_is_equal(div_test_arr[i], div_check_arr[i]);
  }

  ck_assert_int_eq(eq_res, 1);
}
END_TEST

START_TEST(div_0) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_1) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_2) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_3) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(3, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_4) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  s21_decimal res = {0};
  ck_assert_int_eq(3, s21_div(val1, val2, &res));
}
END_TEST

START_TEST(div_ad_0) {
  s21_decimal val1 = {{12344355, 0, 0, 262144}};
  s21_decimal val2 = {{22224444, 0, 0, 262144}};
  s21_decimal res1 = {{0, 0, 0, 0}};

  s21_decimal res = {{-2043313604, -58517076, 301104866, 1835008}};
  s21_div(val1, val2, &res1);
  ck_assert_int_eq(1, s21_is_equal(res1, res));
}
END_TEST

START_TEST(div_ad_1) {
  s21_decimal val1 = {{12344355, 0, 0, 262144}};
  s21_decimal val2 = {{22224444, 0, 0, -2147221504}};
  s21_decimal res1 = {{0, 0, 0, 0}};

  s21_decimal res = {{-2043313604, -58517076, 301104866, -2145648640}};
  s21_div(val1, val2, &res1);
  ck_assert_int_eq(1, s21_is_equal(res1, res));
}
END_TEST

START_TEST(div_ad_2) {
  s21_decimal val1 = {{12344355, 0, 0, 262144}};
  s21_decimal val2 = {{22224444, 0, 0, 524288}};
  s21_decimal res1 = {{0, 0, 0, 0}};

  s21_decimal res = {{1041700446, -585170755, -1283918627, 1638400}};
  s21_div(val1, val2, &res1);
  ck_assert_int_eq(1, s21_is_equal(res1, res));
}
END_TEST

START_TEST(div_ad_3) {
  s21_decimal val1 = {{12344355, 0, 0, 262144}};
  s21_decimal val2 = {{22224444, 0, 0, -2146959360}};
  s21_decimal res1 = {{0, 0, 0, 0}};

  s21_decimal res = {{1041700446, -585170755, -1283918627, -2145845248}};
  s21_div(val1, val2, &res1);
  ck_assert_int_eq(1, s21_is_equal(res1, res));
}
END_TEST

START_TEST(div_ad_4) {
  s21_decimal val1 = {{22224444, 0, 0, 524288}};
  s21_decimal val2 = {{1, 0, 0, 458752}};
  s21_decimal res1 = {{0, 0, 0, 0}};

  s21_decimal res = {{22224444, 0, 0, 65536}};
  s21_div(val1, val2, &res1);
  ck_assert_int_eq(1, s21_is_equal(res1, res));
}
END_TEST

Suite *test_div() {
  Suite *s = NULL;
  TCase *tc_div = NULL;

  s = suite_create("test_div_suite");
  tc_div = tcase_create("div_case");

  tcase_add_test(tc_div, div_array);
  tcase_add_test(tc_div, div_0);
  tcase_add_test(tc_div, div_1);
  tcase_add_test(tc_div, div_2);
  tcase_add_test(tc_div, div_3);
  tcase_add_test(tc_div, div_4);
  tcase_add_test(tc_div, div_ad_0);
  tcase_add_test(tc_div, div_ad_1);
  tcase_add_test(tc_div, div_ad_2);
  tcase_add_test(tc_div, div_ad_3);
  tcase_add_test(tc_div, div_ad_4);

  suite_add_tcase(s, tc_div);

  return s;
}
