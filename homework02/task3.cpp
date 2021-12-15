#include <iostream>
#include <cmath>
int main() {
    double R, r, x, y, nr;
    std::cout << "R: ";
    std::cin >> R;
    std::cout << "r: ";
    std::cin >> r;
    std::cout << "coordinates: \n";
    std::cout << "x: ";
    std::cin >> x;
    std::cout << "y: ";
    std::cin >> y;
    nr = sqrt((x * x) + (y * y));
    if (nr > r and nr < R)
    {
        std::cout << "попадает в кольцо\n";
    }
    else {
        std::cout << "не попадает в кольцо\n";
    }
    return 0;

}