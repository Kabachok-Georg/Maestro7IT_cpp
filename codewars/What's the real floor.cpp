/*
    [ What's the real floor ? ]

    Americans are odd people: in their buildings, the first floor is actually the ground floor and there is no 13th floor ('cause of superstition).
    
    Write a function that given a floor in the american system returns the floor in the european system.
    
    With the 1st floor being replaced by the ground floor and the 13th floor being removed, the numbers move down to take their place.
    In case of above 13, they move down by two because there are two omitted numbers below them.

    Basements (negatives) stay the same as the universal level.

    Examples:
    1  =>  0 
    0  =>  0 
    5  =>  4 
    15  =>  13 
    -3  =>  -3 
*/

/**
 * @brief Возвращает реальный этаж в зависимости от заданного этажа.
 * 
 * В Европе этажи начинаются с 0, а в США с 1. Также в некоторых зданиях
 * отсутствует 13-й этаж из-за суеверий.
 * 
 * @param f Номер этажа, который нужно преобразовать.
 * @return int Реальный номер этажа:
 *         - Если f <= 0, возвращается f.
 *         - Если f < 13, возвращается f - 1.
 *         - Если f >= 13, возвращается f - 2.
 */

int getRealFloor(int f) {
    if (f <= 0) {
        return f;
    } else if (f < 13) {
        return f - 1;
    } else {
        return f - 2;
    }
}

// Авторы: Дуплей Максим и Данилов Георгий
// Дата: 22.12.2024