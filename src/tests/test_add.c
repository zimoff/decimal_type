#include <check.h>
#include <limits.h>
#include <stdio.h>

#include "../s21_decimal.h"
#include "../s21_test.h"

START_TEST(add_array) {
  int add_res = 0;
  int eq_res = 0;
  s21_decimal res_zero = {{0, 0, 0, 0}};

  s21_decimal num_arr_1[50];
  s21_decimal num_arr_2[50];
  s21_decimal add_test_arr[50];

  s21_decimal add_check_arr[50];

  dec_reader("./bin/test_nums_1.bin", num_arr_1);

  dec_reader("./bin/test_nums_2.bin", num_arr_2);

  dec_reader("./bin/add_test_res.bin", add_test_arr);

  for (int i = 0; i < 50; i++) {
    add_res = s21_add(num_arr_1[i], num_arr_2[i], add_check_arr + i);
    if (add_res) add_check_arr[i] = res_zero;

    eq_res = s21_is_equal(add_test_arr[i], add_check_arr[i]);
  }

  ck_assert_int_eq(eq_res, 1);
}
END_TEST

START_TEST(add_0) {
  s21_decimal val1 = {{15, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_1) {
  s21_decimal val1 = {{15, 0, 0, 0}};
  s21_decimal val2 = {{15, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_2) {
  s21_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_3) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{1, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(1, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_4) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal res;
  ck_assert_int_eq(1, s21_add(val1, val2, &res));
}
END_TEST

START_TEST(add_5) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(2, s21_add(val1, val2, &res));
}
END_TEST

Suite *test_add() {
  Suite *s = NULL;
  TCase *tc_add = NULL;

  s = suite_create("test_add_suite");
  tc_add = tcase_create("add_case");

  tcase_add_test(tc_add, add_array);
  tcase_add_test(tc_add, add_0);
  tcase_add_test(tc_add, add_1);
  tcase_add_test(tc_add, add_2);
  tcase_add_test(tc_add, add_3);
  tcase_add_test(tc_add, add_4);
  tcase_add_test(tc_add, add_5);

  suite_add_tcase(s, tc_add);

  return s;
}
