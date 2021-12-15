#include <iostream>

int main() {
    int const N = 6;
    int Arr[N];
    for (int i = 0; i <= N; ++i)
    {
        Arr[i] = i;
    }
    for (int i = 0; i <= N; ++i)
    {
        std::cout << Arr[i] << "   ";
    }
    std::cout << std::endl;
    for (int i = 0, j = N; i <= N / 2; ++i, --j)
    {
        std::cout << Arr[i] << "   " << Arr[j] << "   ";
    }
    return 0;
}