#include <check.h>
#include <limits.h>
#include <stdio.h>

#include "../s21_decimal.h"
#include "../s21_test.h"

START_TEST(mul_array) {
  int mul_res = 0;
  int eq_res = 0;
  s21_decimal res_zero = {{0, 0, 0, 0}};

  s21_decimal num_arr_1[50];
  s21_decimal num_arr_2[50];
  s21_decimal mul_test_arr[50];

  s21_decimal mul_check_arr[50];

  dec_reader("./bin/test_nums_1.bin", num_arr_1);

  dec_reader("./bin/test_nums_2.bin", num_arr_2);

  dec_reader("./bin/mul_test_res.bin", mul_test_arr);

  for (int i = 0; i < 50; i++) {
    mul_res = s21_mul(num_arr_1[i], num_arr_2[i], mul_check_arr + i);
    if (mul_res) mul_check_arr[i] = res_zero;

    eq_res = s21_is_equal(mul_test_arr[i], mul_check_arr[i]);
  }

  ck_assert_int_eq(eq_res, 1);
}
END_TEST

START_TEST(mul_0) {
  s21_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_1) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_2) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_3) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_4) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_5) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_6) {
  s21_decimal val1 = {{12344355, 0, 0, 262144}};
  s21_decimal val2 = {{22224444, 0, 0, 262144}};
  s21_decimal res1 = {{0, 0, 0, 0}};
  s21_decimal res = {{-1608445486, 6387, 0, 458752}};
  /*printf("res test: \n");*/
  /*show_dec(res);*/
  s21_mul(val1, val2, &res1);
  /*printf("res check: \n");*/
  /*show_dec(res1);*/
  ck_assert_int_eq(1, s21_is_equal(res1, res));
}
END_TEST

START_TEST(mul_7) {
  s21_decimal val1 = {{12344355, 0, 0, 262144}};
  s21_decimal val2 = {{22224444, 0, 0, -2147221504}};
  s21_decimal res1 = {{0, 0, 0, 0}};
  s21_decimal res = {{-1608445486, 6387, 0, -2147024896}};
  s21_mul(val1, val2, &res1);
  ck_assert_int_eq(1, s21_is_equal(res1, res));
}
END_TEST

START_TEST(mul_8) {
  s21_decimal val1 = {{12344355, 0, 0, 262144}};
  s21_decimal val2 = {{22224444, 0, 0, 524288}};
  s21_decimal res1 = {{0, 0, 0, 0}};
  s21_decimal res = {{-1608445486, 6387, 0, 720896}};
  s21_mul(val1, val2, &res1);
  ck_assert_int_eq(1, s21_is_equal(res1, res));
}
END_TEST

START_TEST(mul_9) {
  s21_decimal val1 = {{12344355, 0, 0, 262144}};
  s21_decimal val2 = {{22224444, 0, 0, -2146959360}};
  s21_decimal res1 = {{0, 0, 0, 0}};
  s21_decimal res = {{-1608445486, 6387, 0, -2146762752}};
  s21_mul(val1, val2, &res1);
  ck_assert_int_eq(1, s21_is_equal(res1, res));
}
END_TEST

START_TEST(mul_10) {
  s21_decimal val1 = {{22224444, 0, 0, 524288}};
  s21_decimal val2 = {{1, 0, 0, -2147221504}};
  s21_decimal res1 = {{0, 0, 0, 0}};
  s21_decimal res = {{22224444, 0, 0, -2146697216}};
  s21_mul(val1, val2, &res1);
  ck_assert_int_eq(1, s21_is_equal(res1, res));
}
END_TEST

Suite *test_mul() {
  Suite *s = NULL;
  TCase *tc_mul = NULL;

  s = suite_create("test_mul_suite");
  tc_mul = tcase_create("mul_case");

  tcase_add_test(tc_mul, mul_array);
  tcase_add_test(tc_mul, mul_0);
  tcase_add_test(tc_mul, mul_1);
  tcase_add_test(tc_mul, mul_2);
  tcase_add_test(tc_mul, mul_3);
  tcase_add_test(tc_mul, mul_4);
  tcase_add_test(tc_mul, mul_5);
  tcase_add_test(tc_mul, mul_6);
  tcase_add_test(tc_mul, mul_7);
  tcase_add_test(tc_mul, mul_8);
  tcase_add_test(tc_mul, mul_9);
  tcase_add_test(tc_mul, mul_10);

  suite_add_tcase(s, tc_mul);

  return s;
}
