#include <iostream>
#include<Windows.h>

int Binary_search(int* arr, int size, int s_p)
{
	int left{ 0 };
	int right{ size - 1 };
	
	while (right > left)
	{
		int middle = (left + right) / 2;
		if(arr[middle] == s_p) return middle;
		if (arr[middle] < s_p) left = middle + 1;
		else if (arr[middle] > s_p) right = middle - 1;
		else return middle;
	}
	if (arr[left] == s_p) return left;
}

int Array_search(int* arr, int size, int s_p,int (*B_search)(int* arr, int size, int s_p))
{
	return (size - B_search(arr, size, s_p) - 1);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int const size{9};
	
	int arr[size]{ 14, 16, 19, 32, 32, 32, 56, 69, 72 };

	int starting_point{ 0 };

	std::cout << "Введите точку отсчёта: ";
	std::cin >> starting_point;

	std::cout << "Количество элементов в массиве больших, чем " << starting_point << ": " 
		<< Array_search(arr, size, starting_point, Binary_search) << "\n";

	std::cout << Binary_search(arr, size, starting_point);
	std::cout << "\n";
	system("pause");
	return 0;
}