#include <iostream>
#include <Windows.h>

void print_arr(int* arr, int size_arr)
{
    std::cout << "Исходный массив: ";

    for (size_t i = 0; i < size_arr; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << "\n";
}

int element_level(int index_arr)
{
    int level{ 0 };
    int index_max{ 2 };

    while (true)
    {
        level++;
        if (index_arr <= index_max) return level;
        index_max = (index_max * 2) + 2;
    }
}

void branchand_parent_element(int* arr, int index)
{
    int endex_parent = (index - 1) / 2;

    index % 2 == 0 ? std::cout << " right" << "(" << arr[endex_parent] << ") " : std::cout << " left" << "(" << arr[endex_parent] << ") ";
}

void print_pyramid_element(int* arr, int size_arr, int index)
{
    if (index == 0) { std::cout << 0 << " root " << arr[0]; }
    else
    {
        std::cout << element_level(index);
        branchand_parent_element(arr, index);
        std::cout << arr[index];
    }
}

void print_pyramid(int* arr, int size_arr)
{
    std::cout << "Пирамида:" << "\n";

    for (int i = 0; i < size_arr; i++)
    {
        print_pyramid_element(arr, size_arr, i);
        std::cout << "\n";
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int arr_1[6]{ 1, 3, 6, 5, 9, 8 };
    int arr_2[8]{ 94, 67, 18, 44, 55, 12, 6, 42 };
    int arr_3[10]{ 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };

    std::cout << "////////////////" << "\n";

    print_arr(arr_1, 6);
    print_pyramid(arr_1, 6);

    std::cout << "////////////////" << "\n";

    print_arr(arr_2, 8);
    print_pyramid(arr_2, 8);

    std::cout << "////////////////" << "\n";

    print_arr(arr_3, 10);
    print_pyramid(arr_3, 10);

    std::cout << "\n";
    system("pause");

    return 0;
}
