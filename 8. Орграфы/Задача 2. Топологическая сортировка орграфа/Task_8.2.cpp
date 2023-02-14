#include <iostream>
#include <fstream>
#include <Windows.h>
#include <vector>

int** create_two_dim_array(int rows, int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols]();
	}

	return arr;
}

int* create_one_dim_array(int rows)
{
	int* arr = new int[rows];
	for (int i = 0; i < rows; i++) arr[i] = 0;
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

void delete_one_dim_array(int* arr)
{
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

void dfs_t(int** arr, int* arr_v, int rows, int cols, std::vector <int>& order)
{
	int r;
		
	arr_v[rows] = 1;
	for (r = 0; r < cols; r++)
	{
		if ((arr[rows][r] != 0) && (arr_v[r] == 0))
		{
			dfs_t(arr, arr_v, r, cols, order);
			
		}
	}
	order.insert(order.begin(), rows + 1);
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
	int* arr_v = create_one_dim_array(rows);
	std::vector <int> order;

	fill_two_dim_array_from_file(arr, rows, cols, in);

	std::cout << "Топологический порядок вершин: ";
	dfs_t(arr, arr_v, 0, cols, order);

	for (int i : order) std::cout << i << " ";

	delete_two_dim_array(arr, rows);
	delete_one_dim_array(arr_v);

	std::cout << "\n";
	system("pause");
	return 0;
}