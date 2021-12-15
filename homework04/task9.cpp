#include<iostream>

int main()
{
    int x;
    std::cout << "num = ";
    std::cin >> x;
    int res = 0, i = 1;
    while (x)
    {
        res += i * (x % 2);
        i *= 10;
        x /= 2;
    }
    std::cout << res << "\n";
}