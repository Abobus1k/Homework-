#include <iostream>
#include <cmath>

int main()
{
    int n = 0;
    double eps, sum = 0, one = 1.;
    std::cout << "Enter eps: ";
    std::cin >> eps;

    while ((1 / ((double)n * 2. + 1)) > eps)
    {
        sum += one / ((double)n * 2. + 1);
        one *= -1;
        n += 1;
    }
    std::cout << "pi=" << 4. * sum << std::endl;

}