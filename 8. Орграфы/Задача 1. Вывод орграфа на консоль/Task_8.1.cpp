#include <iostream>
#include <fstream>
#include <Windows.h>

int** create_two_dim_array(int rows, int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols]();
	}

	return arr;
}

void delete_two_dim_array(int** arr, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

void fill_two_dim_array_from_file(int** arr, int rows, int cols, std::ifstream& file)
{
	for (size_t i = 0; i < rows; i++)
	{

		for (int j = 0; j < cols; j++)
		{
			file >> arr[i][j];
		}

	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::ifstream in("input.txt");
	if (!in) { std::cout << "Не получилось открыть файл!" << std::endl; return 1; }

	int rows{ 0 }, cols{ 0 };
	in >> rows;
	cols = rows;

	int** arr = create_two_dim_array(rows, cols);
	
	fill_two_dim_array_from_file(arr, rows, cols, in);

	std::cout << "Текстовый вид орграфа: " << "\n";

	for (size_t i = 0; i < rows; i++)
	{
		bool oll_zero{ false };
		std::cout << i + 1 << ": ";

		for (size_t j = 0; j < cols; j++)
		{
			if (arr[i][j] != 0)
			{
				std::cout << j + 1 << " ";
				oll_zero = true;
			}
		}
		if (oll_zero == false) std::cout << "нет";
		std::cout << "\n";
	}

	delete_two_dim_array(arr, rows);
	
	std::cout << "\n";
	system("pause");
	return 0;
}