#include <iostream>
#include <string>
#include <Windows.h>

int simple_string_hash(std::string& str)
{
    int hash{ 0 };
    for (int i = 0; str[i]; i++)
        hash += str[i];
    return hash;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string str{};

    while (true)
    {
        std::cout << "Введите строку: ";
        std::getline(std::cin >> std::ws, str);

        std::cout << "Наивный хэш строки " << str << " = " << simple_string_hash(str) << "\n";

        if (str == "exit")break;
    }

    std::cout <<"\n";
    system("pause");
    return 0;
}