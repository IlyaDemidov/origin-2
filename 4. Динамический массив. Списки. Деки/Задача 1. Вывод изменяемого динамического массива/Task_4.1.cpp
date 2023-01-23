#include <iostream>
#include<Windows.h>

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
    std::cout << "Динамический массив: ";

    for (int i = 0; i < logical_size; i++)
    {
        std::cout << arr[i] << " ";
    }

    for (int i = logical_size; i < actual_size; i++)
    {
        std::cout << "_" << " ";
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int logical_size{ 0 }, actual_size{ 0 };

    std::cout << "Введите фактичеcкий размер массива: ";
    std::cin >> actual_size;
    std::cout << "Введите логический размер массива: ";
    std::cin >> logical_size;

    if (logical_size > actual_size)
    {
        std::cout << "Ошибка! Логический размер массива не может превышать фактический!";
        std::cout << "\n";
        system("pause");
        return 1;
    }

    int* arr = new int[actual_size];

    for (int i = 0; i < logical_size; i++)
    {
        std::cout << "Введите arr[" << i << "]: ";
        std::cin >> arr[i];
    }

    print_dynamic_array(arr, logical_size, actual_size);

    delete[] arr;

    std::cout << "\n";
    system("pause");
    return 0;
}
