#include <iostream>
#include <cmath>

int main() {
    double eps, dx, x1, x2;

    std::cout << "Enter 'eps': ";
    std::cin >> eps;
    std::cout << "Enter 'dx': ";
    std::cin >> dx;
    std::cout << "Enter 'x2': ";
    std::cin >> x2;
    std::cout << "Enter 'x1': ";
    std::cin >> x1;
    while (x1 <= x2)
    {
        double sum = 0;
        double curr = x1;
        int a = 1;
        while (std::abs(curr) > eps)
        {
            sum += curr;
            a += 2;
            curr = -curr * x1 * x1 / (a * (a - 1));
        }
        std::cout << "x = " << x1 << ", sum f(x) = " << sum << ", sin = " << sin(x1) << "\n";
        x1 += dx;
    }
    return 0;
}