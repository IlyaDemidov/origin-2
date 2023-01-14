#include <iostream>
#include <Windows.h>

double fibonacci(double count)
{
    if (count == 0)
        return 0; 
    if (count == 1)
        return 1; 
    return fibonacci(count - 1) + fibonacci(count - 2);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Введите число: ";
    double fiba{ 0 };
    std::cin >> fiba;

    std::cout << "Число Фибоначчи: ";

    for (double count = 0; count < fiba; ++count)
        std::cout <<fibonacci(count) << " ";

          
    
    std::cout << "\n";
    system("pause");
    return 0;
  
}