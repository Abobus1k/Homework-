#include <iostream>

int main() {
    int n, system;
    std::cout << "Enter n: ";
    std::cin >> n;
    std::cout << "Enter numeral system: ";
    std::cin >> system;
    int a = 1;

    while (a <= n)
        a *= system;
    std::cout << "N in the numeral system " << system << ": ";
    while (a > 1)
    {
        a /= system;
        int d = n / a;
        if (d > 0) {
            if (d < 10)
            {
                std::cout << d;
            }
            else {
                std::cout << char(d + 55);
            }
            n %= a;

        }
        else
            std::cout << "0";

    }
    std::cout << "\n";
}