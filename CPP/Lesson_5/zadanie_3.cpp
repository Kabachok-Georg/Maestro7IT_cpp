#include <iostream>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int data[4] = {1, 2, 3, 4};
    printArray(data, 4); // Передача массива в функцию
    return 0;
}

/*
Размерность массива - то колличество элементов, с которыми он может работать (записаны)
*/