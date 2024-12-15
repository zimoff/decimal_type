#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H
#include <stddef.h>

typedef struct {
  int bits[4];
} s21_decimal;

typedef struct {
  int bits[6];
  int exp;
} s21_dec_buf;

int s21_add(s21_decimal value_1, s21_decimal value_2,
            s21_decimal* result);  //Сложение
int s21_sub(s21_decimal value_1, s21_decimal value_2,
            s21_decimal* result);  //Вычитание
int s21_mul(s21_decimal value_1, s21_decimal value_2,
            s21_decimal* result);  //Умножение
int s21_div(s21_decimal value_1, s21_decimal value_2,
            s21_decimal* result);  //Деление
//Функции возвращают код ошибки:
// 0 - OK
// 1 - число слишком велико или равно бесконечности
// 2 - число слишком мало или равно отрицательной бесконечности
// 3 - деление на 0

int s21_is_less(s21_decimal, s21_decimal);           // Меньше <
int s21_is_less_or_equal(s21_decimal, s21_decimal);  // Меньше или равно <=
int s21_is_greater(s21_decimal, s21_decimal);  // Больше >
int s21_is_greater_or_equal(s21_decimal, s21_decimal);  // Больше или равно >=
int s21_is_equal(s21_decimal, s21_decimal);      // Равно ==
int s21_is_not_equal(s21_decimal, s21_decimal);  // Не равно !=
//Возвращаемое значение:
// 0 - FALSE
// 1 - TRUE

int s21_from_int_to_decimal(int src, s21_decimal* dst);      // Из int
int s21_from_float_to_decimal(float src, s21_decimal* dst);  // Из float
int s21_from_decimal_to_int(s21_decimal src, int* dst);      // В int
int s21_from_decimal_to_float(s21_decimal src, float* dst);  // В float
//Возвращаемое значение - код ошибки:
// 0 - OK
// 1 - ошибка конвертации

int s21_floor(s21_decimal value, s21_decimal* result);
// Округляет указанное Decimal число до ближайшего целого числа в сторону
// отрицательной бесконечности.

int s21_round(s21_decimal value, s21_decimal* result);
// Округляет Decimal до ближайшего целого числа.

int s21_truncate(s21_decimal value, s21_decimal* result);
// Возвращает целые цифры указанного Decimal числа; любые дробные цифры
// отбрасываются, включая конечные нули.

int s21_negate(s21_decimal value, s21_decimal* result);
// Возвращает результат умножения указанного Decimal на -1.

// getters,setters
int set_bit(int* num, size_t bit_num);
int get_bit(int* num, size_t bit_num);
int reset_bit(int* num, int bit_num);

int set_dec(s21_decimal* dec, size_t bit_num);
int get_dec(s21_decimal dec, size_t bit_num);

int set_bit_buf(s21_dec_buf* dec_buf, size_t bit_num);
int get_bit_buf(s21_dec_buf* dec_buf, size_t bit_num);
int reset_bit_buf(s21_dec_buf* dec_buf, size_t bit_num);

int get_exp(s21_decimal num);
void set_exp(s21_decimal* num, int exp);
//---------------------------------------------------------------

// m_processing

//---compare--
int more_int_m(int* s1, int* s2, int length);
int less_int_m(int* s1, int* s2, int size);
int equal_int_m(int* s1, int* s2, int size);

//---operations--
s21_dec_buf diff_buf(s21_dec_buf s1, s21_dec_buf s2);

int mul_buf(s21_dec_buf num1, s21_dec_buf num2, s21_dec_buf* buf);

s21_dec_buf div_buf(s21_dec_buf* num1, s21_dec_buf* num2);

s21_dec_buf shift(int* num, int shift_num, int size);

int sum_buf_buf(s21_dec_buf* dec_buf, s21_dec_buf* dec_num);

s21_decimal buf_to_dec(s21_dec_buf* buf);
s21_dec_buf dec_to_buf(s21_decimal* dec_num);

s21_dec_buf bank_round_for_operations(s21_dec_buf num, int* exp);
int buf_length_meter(s21_dec_buf buf);
int normalizator(s21_decimal num1, s21_decimal num2, s21_dec_buf* num_buf1,
                 s21_dec_buf* num_buf2);

int x_or(int a, int b);
int is_dec_zero(s21_decimal num1);

void show_num(int* num);
void show_float(float num);
void show_dec(s21_decimal num);
void show_dec_buf(s21_dec_buf num);
//---------------------------------------------------------------

#endif
