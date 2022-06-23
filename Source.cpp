#include "Header.h"
int main()
{
	double a[] = {1.4,-2.5,3.1};
	double b[] = {1.2,2.3,-1.7,-3.1};
	Polynom p(2, a);
	Polynom q(2, b);
	Polynom r1;
	Polynom r2;
	Polynom r3;
	r1 = p + q;
	r2 = q - p;
	r3 = p * q;
	
	
	std::cout << "p+q\t"<<r1;
	std::cout << "p-q\t" << r2;
	std::cout << "p*q\t" << r3;
	return 1;
}