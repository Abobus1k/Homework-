#include <iostream>

int main() {
    int const N = 6;
    int Arr[N];
    int max = 0, e1, e2;
    for (int i = 0; i <= N; ++i)
    {
        Arr[i] = rand() % 100;
        std::cout << i << ": " << Arr[i] << "   ";
    }
    std::cout << std::endl;
    for (int i = 0; i < N; ++i)
    {
        if ((Arr[i] + Arr[i + 1]) > max)
        {
            max = Arr[i] + Arr[i + 1];
            e1 = Arr[i];
            e2 = Arr[i + 1];
        }
    }
    std::cout << "Max = " << max << " Element 1 = " << e1 << " Element 2 = " << e2 << std::endl;


    return 0;
}