#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int rows, cols, j, i, counter = 1, k;
   /* int mas[100][100];

    cin >> rows >> cols;*/
    cin >> rows >> cols;
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
            
            cout << matrix[i][j] << "\t";
            
        }
        cout << endl;
    }
    return 0;
}