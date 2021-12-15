#include <iostream>

int main() {
    double sum = 0;
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        sum += 1. / (double)i;
    }
    std::cout << "sum = " << sum << "\n";
}