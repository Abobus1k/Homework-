#include<iostream>
int length_x(int x)
{
	int res = 0;
	while (x)
	{
		res++;
		x /= 10;
	}
	return res;
}
int main()
{
	int n, m, max = 0;
	std::cin >> n >> m;
	int** matrix = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = new int[m];
	}
	for (int j = 0; j < m; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			matrix[i][j] = rand();
			if (matrix[i][j] > max) 
				max = matrix[i][j];
		}
	}
	max = length_x(max);
	for (int j = 0; j < m; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			int x = length_x(matrix[i][j]);
			for (int i=0; i<n; ++i)
			{
				delete[] matrix[i];
			}
			delete[] matrix;

			std::cout << matrix[i][j];
			for (int i = 0; i <= max - x; ++i) std::cout << " ";
		}
		std::cout << std::endl;
	}
}
