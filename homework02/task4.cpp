#include <iostream>
int main()
{
    double x, eps, s = 0., deg = 1.;
    std::cout << "Enter eps: ";
    std::cin >> eps;
    std::cout << "Enter x: ";
    std::cin >> x;

    while (deg > eps)
    {
        s += deg;
        deg *= x;
    }

    std::cout << "Series value: " << s << std::endl;
    std::cout << "Function value: " << 1 / (1 - x) << std::endl;
    return 0;
}