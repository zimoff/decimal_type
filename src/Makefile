FLAGS= -Wall -Wextra -Werror -std=c11

LIBS= -lcheck -lm -lsubunit

OS = $(shell uname)

ifeq ($(OS), Linux)
	LIBS = -lcheck -lm -lsubunit
else
	LIBS = -lcheck
endif

all: s21_decimal.a

s21_decimal.a: clean
	gcc $(FLAGS) -c functions/*.c 
	gcc $(FLAGS) -c dec_processing/*.c 
	gcc $(FLAGS) -c dec_processing/m_processing/*.c 
	ar crs s21_decimal.a *.o
	rm -rf *.o

test: clean
	$(eval FLAGS= -Wall -Werror -Wextra -std=c11 --coverage)
	gcc $(FLAGS) -g -o s21_test s21_test.c dec_processing/m_processing/*.c dec_processing/*.c tests/*.c functions/*.c $(LIBS) 
	./s21_test 

gcov_report: test
	mkdir report
	gcov -b -l -p -c s21_*.gcno
	gcovr -o ./report/gcov_report.html --html --html-details -g -k -r . 
	open report/gcov_report.html

test_lib: clean s21_decimal.a
	$(eval LIBS += s21_decimal.a)
	gcc $(FLAGS) -g -o s21_test s21_test.c tests/*.c $(LIBS) 
	./s21_test 

clean:
	rm -rf *.o *.a *.gch *.gcov *.gcno *.gcna *.gcda *.info *.out s21_test s21_dec test_html s21_test_two s21_test_one
	rm -rf report

val: test
	valgrind --tool=memcheck --leak-check=yes  ./s21_test

clang_test:
	clang-format -style=Google -n  *.c *.h ./dec_processing/*.c 
	clang-format -style=Google -n  *.c *.h ./dec_processing/m_processing/*.c 
	clang-format -style=Google -n  *.c *.h ./tests/*.c
	clang-format -style=Google -n  *.c *.h ./functions/*.c

clang_format:
	clang-format -style=Google -i  *.c *.h ./dec_processing/*.c 
	clang-format -style=Google -i  *.c *.h ./dec_processing/m_processing/*.c 
	clang-format -style=Google -i  *.c *.h ./tests/*.c
	clang-format -style=Google -i  *.c *.h ./functions/*.c
