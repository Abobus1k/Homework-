#include <iostream>
void shiftArray(int A[], int n, int k)
{
    int counter = 0;
    k >= n ? k -= n : k = k;
    while (counter < k)
    {
        int tmp_1 = A[0];
        for (int i = 0; i < n; ++i)
        {
            A[i] = A[i + 1];
        }
        A[n - 1] = tmp_1;
        ++counter;
    }
}
int main()
{
    int const N = 3;
    int Arr[N] = { 0, 1, 2 };
    std::cout << "        Arr[]: ";
    for (int i = 0; i < N; ++i)
    {
        std::cout << Arr[i] << "    ";
    }
    std::cout << "\n";
    shiftArray(Arr, N, 6);
    std::cout << "Shifted Arr[]: ";
    for (int i = 0; i < N; ++i)
    {
        std::cout << Arr[i] << "    ";
    }
    std::cout << "\n";
    return 0;
}