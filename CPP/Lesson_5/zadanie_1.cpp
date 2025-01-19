#include <iostream>

int main() {
    int numbers[5] = {1, 2, 3, 4, 5}; // Объявление и инициализация массива целых чисел

    for (int i = 0; i < 5; ++i) {
        std::cout << "Element " << i << ": " << numbers[i] << std::endl;
    }

    return 0;
}

/*
 ID's:      0  1  2  3  4  5  6  7  8  9
 Numbers:   1  2  3  4  5  6  7  8  9  10
 Positions: 1  2  3  4  5  6  7  8  9  10
*/

/*
Размерность массива - то колличество элементов, с которыми он может работать (записаны)
*/
