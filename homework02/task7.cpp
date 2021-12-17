#include<cmath>
#include <iostream>
int main() {
	setlocale(LC_ALL, "russian");
	double R;
	std::cin >> R;
	long double sum = 0;
	for (double y = -(double)R; y <= (double)R; y += 1)
	{
		for (double x = -(double)R; x <= (double)R; x += 1)
		{
			if ((x * x + y * y) <= R * R)
			{
				++sum;
			}
		}
	}

	std::cout << sum;
}
