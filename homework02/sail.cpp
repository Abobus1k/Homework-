#include<iostream>
int main() {
	double x, y;
	std::cin >> x >> y;
	bool proverka = false;
	if (((x + 1) * (x + 1) + y * y <= 1) && (y <= 0))
	{
		proverka = true;
	}
	if (((x - 1) * (x - 1) + y * y <= 1) && (y <= 0))
	{
		proverka = true;
	}
	if ((y <= x / 2 + 2) && (x <= 0) && (x >= -1) && (y >= 0))
	{
		proverka = true;
	}
	if ((y <= -2 * x + 2) && (x <= 1) && (x >= 0) && (y >= 0))
	{
		proverka = true;
	}
	if (proverka) std::cout << "popal";
	if (!proverka) std::cout << "ne popal";
}
