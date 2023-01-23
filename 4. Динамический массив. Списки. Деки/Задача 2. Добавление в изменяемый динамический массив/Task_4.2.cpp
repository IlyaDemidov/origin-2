#include <iostream>
#include<Windows.h>

void print_dynamic_array(int* arr, const int& logical_size, const int& actual_size)
{
    for (int i = 0; i < logical_size; i++)
    {
        std::cout << arr[i] << " ";
    }

    for (int i = logical_size; i < actual_size; i++)
    {
        std::cout << "_" << " ";
    }
}

int* append_to_dynamic_array(int* arr, int& logical_size, int& actual_size, const int& new_value)
{
    if (logical_size < actual_size)
    {
        arr[logical_size] = new_value;
        logical_size++;
        return arr;
    }
    
    if (logical_size == actual_size)
    {
        int* arr_new = new int[actual_size *= 2];
        for (size_t i = 0; i < logical_size; i++)
        {
            arr_new[i] = arr[i];
        }

        arr_new[logical_size] = new_value;
        logical_size++;
        delete[] arr;

        return arr_new;
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

    std::cout << "Динамический массив: ";
    print_dynamic_array(arr, logical_size, actual_size);
    std::cout << "\n";

    while (true)
    {
        std::cout << "Введите элемент для добавления: ";
        int new_value{ 0 };
        std::cin >> new_value;

        if (new_value == 0)
        {
            std::cout << "Спасибо! Ваш массив: ";
            print_dynamic_array(arr, logical_size, actual_size);
            break;
        }

        arr = append_to_dynamic_array(arr, logical_size, actual_size, new_value);
        
        std::cout << "Динамический массив: ";
        print_dynamic_array(arr, logical_size, actual_size);
        std::cout << "\n";
    }

    delete[] arr;
    
    std::cout << "\n";
    system("pause");
    return 0;
}
