#include <iostream>
#include <string>
#include <Windows.h>

int find_substring_light_rabin_karp(std::string source, std::string substring)
{
    const int p = 29;
    const int n = 1000;

    int l_source = source.length(); 
    int l_substring = substring.length();

    int flag;
    int c = 1, i = 0;
    
    int hash_p = 0, hash = 0;
    while (i < l_substring) 
    {
        hash_p = (hash_p * p + substring[i]) % n;
        hash = (hash * p + source[i]) % n;
        i++;
    }
   
    for (int i = 1; i <= l_substring - 1; i++) c = (c * p) % n;

    i = 0;
    while (i <= l_source - l_substring) 
    {
        if (hash_p == hash) 
        {
            flag = 1;
            for (int j = 0; j < l_substring; j++) 
            {
                if (substring[j] == source[i + j]) continue;
                else 
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) return i;
        }
        if (i < l_source - l_substring) 
        {
            hash = ((p * (hash - source[i] * c)) + source[i + l_substring]) % n;
            if (hash < 0) hash = hash + n;
        }
        i++;
    }
    return -1;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string source{};
    std::string substring{};
    
    std::cout << "Введите строку, в которой будет осуществляться поиск : ";
    std::getline(std::cin >> std::ws, source);

    while (true)
    {
        std::cout << "Введите подстроку, которую нужно найти: ";
        std::getline(std::cin >> std::ws, substring);
        int index{ find_substring_light_rabin_karp(source, substring) };

        if (index == -1) { std::cout << "Подстрока " << substring << " не найдена " << "\n";  if (substring == "exit")break;}
        else std::cout << "Подстрока " << substring << " найдена по индексу " << index << "\n";     
    }

    std::cout << "\n";
    system("pause");
    return 0;
}