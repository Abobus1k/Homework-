#include <iostream>

double smthrnd() {
    return (double)rand() / RAND_MAX;
}

int main() {
    int n;
    std::cout << "Enter n:";
    std::cin >> n;
    double points_in = 0.;
    for (int i = 0; i < n; i++)
    {
        double x = smthrnd();
        double y = smthrnd();
        if ((x * x + y * y) <= 1){
         points_in +=1;   
        }
        else
            points_in +=0;
    }
    std::cout << (points_in / (double)n) << std::endl;
}
