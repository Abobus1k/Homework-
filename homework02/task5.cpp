#include <iostream>
int main()
{
    double a, b, c, d, x;
    std::cout << "A: ";
    std::cin >> a;
    std::cout << "B: ";
    std::cin >> b;
    std::cout << "C: ";
    std::cin >> c;
    std::cout << "D: ";
    std::cin >> d;
    std::cout << "x: ";
    std::cin >> x;

    std::cout << "y = " << c + (x - a) * (d - b) / (c - a) << std::endl;

}