/*
#include <iostream>

int main() {
   int arr[5];
   int* ptr = arr;

   for (int i = 0; i < 5; i++) {
       std::cout << "Введите число " << i + 1 << ": ";
       std::cin >> arr[i];
   }

   int sum = 0;
   for (int i = 0; i < 5; i++) {
       sum += *(ptr + i);
   }

   int max = *ptr;
   int min = *ptr;
   for (int i = 1; i < 5; i++) {
       if (*(ptr + i) > max) max = *(ptr + i);
       if (*(ptr + i) < min) min = *(ptr + i);
   }

   std::cout << "Исходный массив: ";
   for (int i = 0; i < 5; i++) {
       std::cout << *(ptr + i) << " ";
   }
   std::cout << "\nСумма элементов: " << sum;
   std::cout << "\nМаксимальное значение: " << max;
   std::cout << "\nМинимальное значение: " << min;

   return 0;
}
*/
