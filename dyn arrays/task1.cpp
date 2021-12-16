#include <iostream>

int main()
{
    int n, m;
    std::cout << "Введите количество столбцов: ";
    std::cin >> m;
    std::cout << "Введите количество строк: ";
    std::cin >> n;
    int counter = 0;
    int** matrix;
    matrix = new int* [n];

    for (int i = 0; i < n; ++i)
    {
        matrix[i] = new int[m];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (i % 2 == 0)
            {
                ++counter;
                matrix[i][j] = counter;
            }
            else {
                ++counter;
                matrix[i][m - j-1] = counter;
            }
        }
        std::cout << "\n";
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
    for (int i = 0; i < n; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
