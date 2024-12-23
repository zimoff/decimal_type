### Описание проекта **s21_decimal**

**s21_decimal** — это библиотека для работы с десятичными числами, разработанная на языке C для решения задач, требующих высокой точности вычислений. Она предназначена для финансовых и инженерных расчетов, где недопустимы ошибки округления, присущие типам с плавающей точкой. Библиотека поддерживает арифметические операции (сложение, вычитание, умножение, деление), операции сравнения (равно, больше, меньше и т.д.), преобразование типов (float и int в decimal и обратно), а также математические округления. Все вычисления основаны на использовании двоичного представления числа с разрядностью до 96 бит.

Реализация проекта соответствует стандарту C11 и включает в себя обработку пограничных значений, таких как бесконечность и деление на ноль. Каждая функция библиотеки покрыта unit-тестами, а проект построен с использованием Makefile, который предоставляет цели для сборки, тестирования и анализа покрытия кода. Итоговый продукт оформлен в виде статической библиотеки с заголовочным файлом, что позволяет легко интегрировать её в другие программы.

---

### Требования к проекту **s21_decimal**

1. Реализовать тип данных **decimal** в виде структуры с массивом целых чисел (`int bits[4]`), поддерживающим разрядность до 96 бит.  
2. Поддержка следующих операций:
   - Арифметические: сложение, вычитание, умножение, деление.
   - Операции сравнения: равно, не равно, больше, меньше, больше или равно, меньше или равно.
   - Преобразование типов: int <-> decimal, float <-> decimal.
   - Математические функции: округление, округление вниз, усечение, смена знака.  
3. Соблюдение стандартов:
   - Использование банковского округления для больших значений.
   - Корректная обработка пограничных случаев (деление на 0, переполнение, недопустимые значения).  
4. Реализация на языке C с использованием стандарта C11.  
5. Покрытие функций библиотеки unit-тестами с использованием **Check**.  
6. Организация сборки и тестирования через **Makefile**:
   - Цели: `all`, `clean`, `test`, `gcov_report`.  
7. Оформление результата в виде статической библиотеки (*s21_decimal.a*) с заголовочным файлом (*s21_decimal.h*).  
8. Запрещено использование типа `__int128` и устаревших конструкций языка.  
