#include <iostream>


int main()
{
    
    int rows;
    int cols;
    int i;
    int j;
    int k;
    int counter = 1;
    std::cin >> rows >> cols;
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[cols];
    }

    for (k = 0; k < rows + cols - 1; k++)
    {
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < cols; j++)
            {
                if (i + j == k)
                {
                    matrix[i][j] = counter;
                    counter++;
                }
            }
        }
    }


    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {

            std::cout << matrix[i][j] << "\t";

        }
        std::cout << std::endl;
    }
    for (int i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
