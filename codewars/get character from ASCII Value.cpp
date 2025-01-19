/*
    [ get character from ASCII Value ]

    Write a function which takes a number and returns the corresponding ASCII char for that value.

    Example:
    65 --> 'A'
    97 --> 'a'
    48 --> '0'

    For ASCII table, you can refer to http://www.asciitable.com/
*/


/**
 * @brief Преобразует целое число в символ.
 * 
 * Эта функция принимает целое число и возвращает символ,
 * соответствующий этому числу в таблице ASCII.
 * 
 * @param i Целое число, которое нужно преобразовать в символ.
 * @return char Символ, соответствующий числу.
 * 
 * @note Если значение i выходит за пределы допустимых значений типа char,
 * результат может быть непредсказуемым.
 * 
 * @example
 * char c = get_char(65); // Возвращает 'A'
 */

char get_char(int i) {
    return static_cast<char>(i);
}

/*
char get_char(int i) {
  return i;
}
*/

// Авторы: Дуплей Максим и Данилов Георгий
// Дата: 22.12.2024