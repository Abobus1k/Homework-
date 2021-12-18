#include <iostream>
int main()
{
    int rows;
    int cols;
    int counter = 1;
    int step; 
    bool check = false;
    std::cin >> cols >> rows;
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[cols];
    }
    int i = 0; 
    int j = 0;
    int min;
    int max;
    if (rows < cols)
    {
        min = rows;
        max = cols;
    }
    else
    {
        min = cols;
        max = rows;
    }       
    for (int size = 1; size <= min; size += 2)
    {
        step = i;
        for (; j < cols - size + step; j++)
        {
            matrix[i][j] = counter;
            counter++;
        }

        for (; i < rows - size + step; i++)
        {
            matrix[i][j] = counter;
            counter++;
        }

        if (min != 1)
        {
            for (; j > 0 + step; j--)
            {
                matrix[i][j] = counter;
                counter++;
                if (counter == rows * cols + 1)
                {
                    check = true;
                    break;
                }
            }
            if (check == true)
            {
                break;
            }
            for (; i > 0 + step; i--)
            {
                matrix[i][j] = counter;
                counter++;
                if (counter == rows * cols + 1)
                {
                    check = true;
                    break;
                }
            }
            if (check == true)
            {
                break;
            }
        }
        else
        {
            matrix[rows - 1][cols - 1] = max;
        }
        i++;
        j++;
    }
    if (rows % 2 != 0 && cols % 2 != 0 && rows == cols)
    {
        matrix[rows / 2][cols / 2] = rows * cols;
    }
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}