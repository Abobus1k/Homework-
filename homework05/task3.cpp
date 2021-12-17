#include <iostream>
#include <cmath>
int main()
{

	double j;
	double k;
	double x;
	int n;
	std::cout << "x: ";
	std::cin >> x;
	std::cout << "n: ";
	std::cin >> n;
	k = x;
	if (n % 2 == 0)
	{
		for (double i = 0; i < n / 2; ++i)
		{
			j = sin(k);
			k = sin(j);
		}
	}
	else
	{
		for (int i = 0; i < n / 2; ++i)
		{
			j = sin(k);
			k = sin(j);
		}
		k = sin(k);
	}

	std::cout << k;
}