#include <check.h>
#include <limits.h>
#include <stdio.h>

#include "../s21_decimal.h"

START_TEST(test_is_less_1) {
  s21_decimal test_value_1 = {{10, 0, 0, 1 << 16}};
  s21_decimal test_value_2 = {{15, 0, 0, 1 << 16}};
  ck_assert_int_eq(s21_is_less(test_value_1, test_value_2), 1);
}
END_TEST

START_TEST(test_is_less_2) {
  s21_decimal test_value_1 = {{10, 0, 0, 5 << 16}};
  s21_decimal test_value_2 = {{15, 0, 0, 6 << 16}};
  ck_assert_int_eq(s21_is_less(test_value_1, test_value_2), 0);
}
END_TEST

START_TEST(test_is_less_3) {
  s21_decimal test_value_1 = {{19993, 0, 0, 0}};
  s21_decimal test_value_2 = {{6739, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(test_value_1, test_value_2), 0);
}
END_TEST

START_TEST(test_is_less_4) {
  s21_decimal test_value_1 = {{19993, 0, 0, 0}};
  s21_decimal test_value_2 = {{6739, 0, 0, 2147483648U}};
  ck_assert_int_eq(s21_is_less(test_value_1, test_value_2), 0);
}
END_TEST

START_TEST(test_is_less_5) {
  s21_decimal test_value_1 = {{19993, 0, 0, 0}};
  s21_decimal test_value_2 = {{19993, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(test_value_1, test_value_2), 0);
}
END_TEST

START_TEST(test_is_less_6) {
  s21_decimal test_value_1 = {{19993, 0, 0, 2 << 16}};
  s21_decimal test_value_2 = {{19993, 0, 0, 1 << 16}};
  ck_assert_int_eq(s21_is_less(test_value_1, test_value_2), 1);
}
END_TEST

START_TEST(test_is_less_7) {
  s21_decimal test_value_1 = {{0, 1, 0, 0}};
  s21_decimal test_value_2 = {{19993, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(test_value_1, test_value_2), 0);
}
END_TEST

START_TEST(test_is_less_8) {
  s21_decimal test_value_1 = {{19993, 1, 0, 2147483648U}};
  s21_decimal test_value_2 = {{19993, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less(test_value_1, test_value_2), 1);
}
END_TEST

START_TEST(is_less_0) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_1) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_2) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_3) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_4) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  set_exp(&val1, 11);
  set_exp(&val2, 10);
  ck_assert_int_eq(1, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_5) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  set_exp(&val1, 10);
  set_exp(&val2, 11);

  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_less_6) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  ck_assert_int_eq(0, s21_is_less(val1, val2));
}
END_TEST

START_TEST(is_greater_0) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_1) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_2) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_3) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  set_exp(&val1, 11);
  set_exp(&val2, 10);
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_4) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  set_exp(&val1, 10);
  set_exp(&val2, 11);
  ck_assert_int_eq(1, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_5) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val2.bits[2] = 257;
  ck_assert_int_eq(0, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_6) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[2] = 257;
  ck_assert_int_eq(1, s21_is_greater(val1, val2));
}
END_TEST

START_TEST(is_greater_or_equal_0) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(is_greater_or_equal_1) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(is_greater_or_equal_2) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(is_greater_or_equal_3) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(is_greater_or_equal_4) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  set_exp(&val1, 11);
  set_exp(&val2, 10);
  ck_assert_int_eq(0, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(is_greater_or_equal_5) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val1.bits[2] = 256;
  set_exp(&val1, 10);

  val2.bits[2] = 257;
  val2.bits[0] = 257;
  set_exp(&val2, 11);
  ck_assert_int_eq(1, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(is_greater_or_equal_6) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val2.bits[2] = 257;
  ck_assert_int_eq(0, s21_is_greater_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_0) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_1) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 255;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_2) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 256;
  val2.bits[0] = 256;
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_3) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 256;
  ck_assert_int_eq(0, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_4) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val2.bits[0] = 257;
  val1.bits[2] = 256;
  val2.bits[2] = 257;
  set_exp(&val1, 11);
  set_exp(&val2, 10);
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_5) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val1.bits[0] = 257;
  val1.bits[2] = 256;
  set_exp(&val1, 10);

  val2.bits[0] = 257;
  val2.bits[2] = 257;
  set_exp(&val2, 11);

  ck_assert_int_eq(0, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(is_less_or_equal_6) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  val2.bits[2] = 257;
  ck_assert_int_eq(1, s21_is_less_or_equal(val1, val2));
}
END_TEST

START_TEST(test_is_less_or_equal_1) {
  s21_decimal test_value_1 = {{10, 0, 0, 1 << 16}};
  s21_decimal test_value_2 = {{10, 0, 0, 1 << 16}};
  ck_assert_int_eq(s21_is_less_or_equal(test_value_1, test_value_2), 1);
}
END_TEST

START_TEST(test_is_less_or_equal_2) {
  s21_decimal test_value_1 = {{15, 0, 0, 5 << 16}};
  s21_decimal test_value_2 = {{15, 0, 0, 5 << 16}};
  ck_assert_int_eq(s21_is_less_or_equal(test_value_1, test_value_2), 1);
}
END_TEST

START_TEST(test_is_less_or_equal_3) {
  s21_decimal test_value_1 = {{19993, 0, 0, 0}};
  s21_decimal test_value_2 = {{6739, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(test_value_1, test_value_2), 0);
}
END_TEST

START_TEST(test_is_less_or_equal_4) {
  s21_decimal test_value_1 = {{6739, 0, 0, 2147483648U}};
  s21_decimal test_value_2 = {{6739, 0, 0, 2147483648U}};
  ck_assert_int_eq(s21_is_less_or_equal(test_value_1, test_value_2), 1);
}
END_TEST

START_TEST(test_is_less_or_equal_5) {
  s21_decimal test_value_1 = {{19993, 0, 0, 0}};
  s21_decimal test_value_2 = {{19993, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(test_value_1, test_value_2), 1);
}
END_TEST

START_TEST(test_is_less_or_equal_6) {
  s21_decimal test_value_1 = {{19993, 0, 0, 0}};
  s21_decimal test_value_2 = {{19993, 0, 0, 131072}};
  ck_assert_int_eq(s21_is_less_or_equal(test_value_1, test_value_2), 0);
}
END_TEST

START_TEST(test_is_less_or_equal_7) {
  s21_decimal test_value_1 = {{0, 1, 0, 0}};
  s21_decimal test_value_2 = {{19993, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(test_value_1, test_value_2), 0);
}
END_TEST

START_TEST(test_is_less_or_equal_8) {
  s21_decimal test_value_1 = {{19993, 1, 0, 2147483648U}};
  s21_decimal test_value_2 = {{19993, 0, 0, 0}};
  ck_assert_int_eq(s21_is_less_or_equal(test_value_1, test_value_2), 1);
}
END_TEST

START_TEST(is_equal_0) {
  s21_decimal val1 = {{0, 0, 0, 0}};
  s21_decimal val2 = {{0, 0, 0, 0}};

  if (get_dec(val2, 31) == 0) {
    val2.bits[3] = val2.bits[3] >> 2;
    val2.bits[3] = val2.bits[3] + pow(2, 29);
    val2.bits[3] = val2.bits[3] << 2;
  }

  ck_assert_int_eq(1, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(is_equal_1) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  set_exp(&val1, 3);
  set_exp(&val2, 3);
  ck_assert_int_eq(1, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(is_equal_2) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  set_exp(&val1, 3);
  set_exp(&val2, 2);
  ck_assert_int_eq(1, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(is_equal_3) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  ck_assert_int_eq(1, s21_is_equal(val1, val2));
}
END_TEST

START_TEST(is_not_equal_0) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  set_exp(&val1, 3);
  set_exp(&val2, 3);
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(is_not_equal_1) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  set_exp(&val1, 3);
  set_exp(&val2, 2);
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

START_TEST(is_not_equal_2) {
  s21_decimal val1 = {0};
  s21_decimal val2 = {0};
  ck_assert_int_eq(0, s21_is_not_equal(val1, val2));
}
END_TEST

/*int s21_is_less(s21_decimal, s21_decimal);// Меньше <*/
/*int s21_is_less_or_equal(s21_decimal, s21_decimal);// Меньше или равно <=*/
/*int s21_is_greater(s21_decimal, s21_decimal);// Больше >*/
/*int s21_is_greater_or_equal(s21_decimal, s21_decimal);// Больше или равно >=*/
/*int s21_is_equal(s21_decimal, s21_decimal);// Равно ==*/
/*int s21_is_not_equal(s21_decimal, s21_decimal);// Не равно !=*/

Suite *test_compare() {
  Suite *s = NULL;
  TCase *tc_less = NULL;
  TCase *tc_less_or_equal = NULL;
  TCase *tc_greater = NULL;
  TCase *tc_greater_or_equal = NULL;
  TCase *tc_equal = NULL;
  TCase *tc_not_equal = NULL;

  s = suite_create("test_compare");

  tc_less = tcase_create("less_case");
  tc_less_or_equal = tcase_create("less_or_equal_case");
  tc_greater = tcase_create("greater_case");
  tc_greater_or_equal = tcase_create("greater_or_equal_case");
  tc_equal = tcase_create("equal_case");
  tc_not_equal = tcase_create("not_equal_case");

  tcase_add_test(tc_less, test_is_less_1);
  tcase_add_test(tc_less, test_is_less_2);
  tcase_add_test(tc_less, test_is_less_3);
  tcase_add_test(tc_less, test_is_less_4);
  tcase_add_test(tc_less, test_is_less_5);
  tcase_add_test(tc_less, test_is_less_6);
  tcase_add_test(tc_less, test_is_less_7);
  tcase_add_test(tc_less, test_is_less_8);
  tcase_add_test(tc_less, is_less_0);
  tcase_add_test(tc_less, is_less_1);
  tcase_add_test(tc_less, is_less_2);
  tcase_add_test(tc_less, is_less_3);
  tcase_add_test(tc_less, is_less_4);
  tcase_add_test(tc_less, is_less_5);
  tcase_add_test(tc_less, is_less_6);
  tcase_add_test(tc_greater, is_greater_0);
  tcase_add_test(tc_greater, is_greater_1);
  tcase_add_test(tc_greater, is_greater_2);
  tcase_add_test(tc_greater, is_greater_3);
  tcase_add_test(tc_greater, is_greater_4);
  tcase_add_test(tc_greater, is_greater_5);
  tcase_add_test(tc_greater, is_greater_6);

  tcase_add_test(tc_greater_or_equal, is_greater_or_equal_0);
  tcase_add_test(tc_greater_or_equal, is_greater_or_equal_1);
  tcase_add_test(tc_greater_or_equal, is_greater_or_equal_2);
  tcase_add_test(tc_greater_or_equal, is_greater_or_equal_3);
  tcase_add_test(tc_greater_or_equal, is_greater_or_equal_4);
  tcase_add_test(tc_greater_or_equal, is_greater_or_equal_5);
  tcase_add_test(tc_greater_or_equal, is_greater_or_equal_6);

  tcase_add_test(tc_less_or_equal, is_less_or_equal_0);
  tcase_add_test(tc_less_or_equal, is_less_or_equal_1);
  tcase_add_test(tc_less_or_equal, is_less_or_equal_2);
  tcase_add_test(tc_less_or_equal, is_less_or_equal_3);
  tcase_add_test(tc_less_or_equal, is_less_or_equal_4);
  tcase_add_test(tc_less_or_equal, is_less_or_equal_5);
  tcase_add_test(tc_less_or_equal, is_less_or_equal_6);

  tcase_add_test(tc_less_or_equal, test_is_less_or_equal_1);
  tcase_add_test(tc_less_or_equal, test_is_less_or_equal_2);
  tcase_add_test(tc_less_or_equal, test_is_less_or_equal_3);
  tcase_add_test(tc_less_or_equal, test_is_less_or_equal_4);
  tcase_add_test(tc_less_or_equal, test_is_less_or_equal_5);
  tcase_add_test(tc_less_or_equal, test_is_less_or_equal_6);
  tcase_add_test(tc_less_or_equal, test_is_less_or_equal_7);
  tcase_add_test(tc_less_or_equal, test_is_less_or_equal_8);

  tcase_add_test(tc_equal, is_equal_0);
  tcase_add_test(tc_equal, is_equal_1);
  tcase_add_test(tc_equal, is_equal_2);
  tcase_add_test(tc_equal, is_equal_3);
  tcase_add_test(tc_not_equal, is_not_equal_0);
  tcase_add_test(tc_not_equal, is_not_equal_1);
  tcase_add_test(tc_not_equal, is_not_equal_2);

  suite_add_tcase(s, tc_less);
  suite_add_tcase(s, tc_less_or_equal);
  suite_add_tcase(s, tc_greater);
  suite_add_tcase(s, tc_greater_or_equal);
  suite_add_tcase(s, tc_equal);
  suite_add_tcase(s, tc_not_equal);

  return s;
}
