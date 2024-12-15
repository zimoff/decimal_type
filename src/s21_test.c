#include "s21_test.h"

void test_result(Suite *suite) {
  SRunner *srunner = srunner_create(suite);
  srunner_run_all(srunner, CK_NORMAL);
  int failed_count = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  if (failed_count != 0) {
    printf("FAILED\n");
  } else {
    printf("SUCCESS\n");
  }
}

int main() {
  Suite *suites[] = {test_int_dec_convertation(),
                     test_add(),
                     test_sub(),
                     test_mul(),
                     test_div(),
                     test_compare(),
                     test_round(),
                     test_floor(),
                     test_truncate(),
                     test_dec_fl(),
                     test_fl_dec(),
                     test_nagete(),

                     NULL};

  for (int i = 0; suites[i] != NULL; i++) {
    test_result(suites[i]);
  }

  return 0;
}
