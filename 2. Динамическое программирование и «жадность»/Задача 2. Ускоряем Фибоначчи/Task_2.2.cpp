#include <iostream>
#include <Windows.h>
#include <vector>

double fibonacci(double count)
{
    static std::vector<double> results{ 0, 1 };

    if (count < static_cast<double>(std::size(results)))
        return results[count];
    else
    {
        results.push_back(fibonacci(count - 1) + fibonacci(count - 2));
        return results[count];
    }
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
        std::cout << fibonacci(count) << " ";



    std::cout << "\n";
    system("pause");
    return 0;

}