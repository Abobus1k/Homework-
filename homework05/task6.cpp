Новое решение
#include <iostream>
int main() {
    int N;
    std::cin >> N;
    int* mas = new int[N];
    for (int i = 0; i < N; ++i)
    {
        std::cout << i << ": ";
        std::cin >> mas[i];
    }
    int d = mas[1] - mas[0];
    if (N > 2)
    {
        for (int i = 2; i < N; i++)
            if (d != mas[i-1] - mas[i-2])
            {
                d = 0;
                break;
            }
    }
    else
    {
        d = 0;
    }
    delete[] mas;
    
    std::cout << d;
    return 0;
}
Старое решение:
#include <iostream>
int main() {
    int N;
    std::cin >> N;
    int* mas = new int[N];
    for (int i = 0; i < N; ++i)
    {
        std::cout << i << ": ";
        std::cin >> mas[i];
    }
    bool flag = 0;
    int curr = mas[1], d = mas[1] - mas[0];
    if (N > 2)
        for (int i = 2; i < N; ++i)
        {
            if ((mas[i] - curr) == d)
            {
                curr = mas[i];
            }
            else
            {
                flag = 1;

            }
        }
    if (!flag) std::cout << d;
    if (flag)std::cout << "0";
}
