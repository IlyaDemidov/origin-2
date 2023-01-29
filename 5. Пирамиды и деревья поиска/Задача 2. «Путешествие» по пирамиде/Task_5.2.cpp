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

bool checking_branch_left(int size_arr, int& index)
{
    int index_next = 2 * index + 1;

    if (index_next > size_arr - 1) return false;
    else { index = index_next; return true; }
}

bool checking_branch_right(int size_arr, int& index)
{
    int index_next = 2 * index + 2;

    if (index_next > size_arr - 1) return false;
    else { index = index_next; return true; }
}

bool checking_up(int& index)
{
    int index_next = (index - 1) / 2;

    if (index_next == index) return false;
    else { index = index_next; return true; }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int arr_1[6]{ 1, 3, 6, 5, 9, 8 };
    //int arr_2[8]{ 94, 67, 18, 44, 55, 12, 6, 42 };
    //int arr_3[10]{ 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };

    print_arr(arr_1, 6);
    print_pyramid(arr_1, 6);

    int index{ 0 };
    bool exit_loop = true;

    while (exit_loop)
    {
        std::cout << "Вы находитесь здесь: ";
        print_pyramid_element(arr_1, 6, index);
        std::cout << "\n";

        char var{ '0' };
        std::cout << "Введите команду:"; std::cin >> var;
        std::cin.ignore(100, '\n');

        switch (var)
        { 
            case 'l': checking_branch_left(6, index) ? std::cout << "OK" << "\n" : std::cout << "Ошибка! Отсутствует левый потомок" << "\n"; break;
            case 'r': checking_branch_right(6, index) ? std::cout << "OK" << "\n" : std::cout << "Ошибка! Отсутствует правый потомок" << "\n"; break;
            case 'u': checking_up(index) ? std::cout << "OK" << "\n" : std::cout << "Ошибка! Отсутствует родитель" << "\n"; break;
            case 'e': exit_loop = false; break;

        default: break;
        }

    }

    std::cout << "\n";
    system("pause");

    return 0;
}
