#include <iostream>

int main()
{
    int number;
    unsigned long long factorial = 1;

    std::cout << "Введите число: ";
    std::cin >> number;

    for (int i = 1; i <= number; ++i)
    {
        factorial *= i;
    }

    std::cout << "Факториал числа " << number << " равен " << factorial << "." << std::endl;

    return 0;
}

/*
!5 = 1 * 2 * 3 * 4 * 5 = 120
!6 = 6 * 120 = 720
!7 = 7 * 720 = 5040
*/
