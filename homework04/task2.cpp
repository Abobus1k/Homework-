#include <iostream>

int main() {
    double sum = 0;
    int n = 0, counter = 1;
    double a = 2;
    std::cout << "Enter n: ";
    std::cin >> n;
    while (counter <= n)
    {
        ++counter;
        sum += 1. / a;
        a *= a;

    }
    std::cout << "sum = " << sum + 1 << "\n";
}