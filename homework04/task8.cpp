#include <iostream>

int main() {
    int n, counter = 0, s = 0;
    std::cout << "Enter n: ";
    std::cin >> n;
    while (n)
    {
        s += (n % 10);
        n /= 10;
    }
    std::cout << "s: " << s << "\n";
}