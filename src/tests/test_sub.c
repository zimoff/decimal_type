#include <check.h>
#include <limits.h>
#include <stdio.h>

#include "../s21_decimal.h"
#include "../s21_test.h"

START_TEST(sub_array) {
  int sub_res = 0;
  int eq_res = 0;
  s21_decimal res_zero = {{0, 0, 0, 0}};

  s21_decimal num_arr_1[50];
  s21_decimal num_arr_2[50];
  s21_decimal sub_test_arr[50];

  s21_decimal sub_check_arr[50];

  dec_reader("./bin/test_nums_1.bin", num_arr_1);

  dec_reader("./bin/test_nums_2.bin", num_arr_2);

  dec_reader("./bin/sub_test_res.bin", sub_test_arr);

  for (int i = 0; i < 50; i++) {
    sub_res = s21_sub(num_arr_1[i], num_arr_2[i], sub_check_arr + i);
    if (sub_res) sub_check_arr[i] = res_zero;

    eq_res = s21_is_equal(sub_test_arr[i], sub_check_arr[i]);
  }

  ck_assert_int_eq(eq_res, 1);
}
END_TEST

START_TEST(sub_0) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_1) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_2) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_3) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_4) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(1, s21_sub(val1, val2, &res));
}
END_TEST

Suite *test_sub() {
  Suite *s = NULL;
  TCase *tc_sub = NULL;

  s = suite_create("test_sub_suite");
  tc_sub = tcase_create("sub_case");

  tcase_add_test(tc_sub, sub_array);
  tcase_add_test(tc_sub, sub_0);
  tcase_add_test(tc_sub, sub_1);
  tcase_add_test(tc_sub, sub_2);
  tcase_add_test(tc_sub, sub_3);
  tcase_add_test(tc_sub, sub_4);

  suite_add_tcase(s, tc_sub);

  return s;
}
