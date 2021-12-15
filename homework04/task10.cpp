#include <iostream>

int main() {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;
    int a = 1;
    while (a <= n)
        a *= 16;
    std::cout << "N in hexadecimal notation: ";
    while (a > 1)
    {
        a /= 16;
        int d = n / a;
        if (d > 0) {
            if (d < 10)
            {
                std::cout << d;
            }
            else {
                std::cout << (char)(d + 55);
            }

            n %= a;
        }
        else
            std::cout << "0";

    }
    std::cout << "\n";

}