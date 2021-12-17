#include <iostream>
int main() {
	int N;
	std::cin >> N;
	int* mas = new int[N];
	for (int i = 0; i < N; ++i)
	{
		std::cout << i << ": ";
		std::cin >> mas[i];
	}
	int curr = mas[0], res = 0,x,y;
	for (int i = 1; i < N; ++i)
	{
		if ((mas[i] + curr) >= res)
		{
			res = mas[i] + curr;
			x = curr;
			y = mas[i];
			curr = mas[i];
		}
	}
	std::cout << x << " "<< y;
}
