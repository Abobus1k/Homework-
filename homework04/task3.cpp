#include <iostream>
#include <cmath>

int main()
{
    double s = 0., a = 1.;
    int n = 0;
    std::cout << "Enter n: ";
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        s += a;
        a = sin(a);
    }
    std::cout << "Answer: " << s << "\n";

}