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
	int max = mas[0] + mas[1];
	int k = 1;
	for (int i = 2; i < N; ++i)
	{
		if ((mas[i - 1] + mas[i]) > max)
		{
			max = mas[i - 1] + mas[i];
			k = i;

		}
	}
	std::cout << mas[k - 1] << " " << mas[k];

}
