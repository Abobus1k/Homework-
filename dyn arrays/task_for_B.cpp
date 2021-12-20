#include <iostream>


void task_for_B(int** mas, int cols, int rows, bool direction)
{
    int Rows = rows;
    int Cols = cols;
    int i;
    int j;
    int counter=1;
    int k;

    if (!direction)
    {
        int curr = cols;
        cols = rows;
        rows = curr;
    }
    for (k = 0; k < rows + cols - 1; ++k)
    { 
        if (k%2==1)
        { 
        for (i = 0; i < rows; ++i)
            for (j = 0; j < cols; ++j)
                if (i + j == k)
                {
                    if (direction) mas[i][j] = counter;
                    else mas[j][i] = counter;
                    ++counter;
                }
        }
        else
        {
            for (j = 0; j < cols; ++j)
                for (i=0; i<rows;i++)
                if (i + j == k)
                {
                    if (direction) mas[i][j] = counter;
                    else mas[j][i] = counter;
                    ++counter;
                }

        }
    }
    for (i = 0; i < Rows; ++i)
    {
        for (j = 0; j < Cols; ++j)
        {
            std::cout << mas[i][j]<<"\t";
        }
        std::cout << "\n";
    }
}

int main()
{
    int rows, cols;
    bool direction;
    std::cout << "cols = ";
    std::cin >> cols;
    std::cout << "rows = ";
    std::cin >> rows;
    std::cout << "Choose direction 1 or 0 ";
    std::cin >> direction;

    int** mas = new int* [rows];

    for (int i = 0; i < rows; ++i)
    {
        mas[i] = new int[cols];
    }
    task_for_B(mas, cols, rows, direction);

    for (int i = 0; i < rows; ++i)
    {
        delete[] mas[i];
    }
    delete[] mas;
    return 0;
}
