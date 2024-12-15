#ifndef SRC_S21_TEST_H
#define SRC_S21_TEST_H

#include <check.h>
#include <stdio.h>

#include "s21_decimal.h"

int dec_reader(char *file_path, s21_decimal *num_arr);

Suite *test_int_dec_convertation();
Suite *test_add();
Suite *test_sub();
Suite *test_mul();
Suite *test_div();
Suite *test_compare();
Suite *test_round();
Suite *test_floor();
Suite *test_truncate();
Suite *test_dec_fl();
Suite *test_fl_dec();
Suite *test_nagete();

#endif
