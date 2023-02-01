#include <iostream>
#include <string>
#include <Windows.h>
#include <cmath>

long long real_string_hash(int p, int n, std::string& str)
{
    long long hash{ 0 };
    for (int i = 0; str[i]; i++)
    {
        hash += str[i] * pow(p,i);
        
    }
    return hash % n;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string str{};
    int p{ 0 }, n{ 0 };

    std::cout << "Введите p: ";
    std::cin >> p;
    std::cout << "Введите n: ";
    std::cin >> n;

    while (true)
    {
        std::cout << "Введите строку: ";
        std::getline(std::cin >> std::ws, str);

        std::cout << "Хэш строки " << str << " = " << real_string_hash(p, n, str) << "\n";

        if (str == "exit")break;
    }

    std::cout <<"\n";
    system("pause");
    return 0;
}