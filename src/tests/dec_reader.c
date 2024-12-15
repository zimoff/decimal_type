#include <stdio.h>
#include <stdlib.h>

#include "../s21_decimal.h"

int dec_reader(char* file_path, s21_decimal* num_arr) {
  int res = 0;

  s21_decimal* test_num = malloc(sizeof(s21_decimal));

  FILE* d_file = fopen(file_path, "rb");
  if (!d_file) {
    printf("open fail\n");
    res = -1;
    return res;
  }

  int count = 0;
  while (fread(test_num, sizeof(s21_decimal), 1, d_file)) {
    num_arr[count] = *test_num;
    count++;
  }

  fclose(d_file);

  free(test_num);

  return res;
}
