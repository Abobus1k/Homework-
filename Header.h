#pragma once
#include <iostream>
#include <fstream>
class Polynom 
{
private:
	int dgr_;
	double* coeff_;
public:
	Polynom();
	Polynom(int degree, double* clist);
	Polynom(const Polynom&);
	Polynom operator=(const Polynom& x);
	Polynom operator+(const Polynom& x);
	Polynom operator-(const Polynom& x);
	Polynom operator*(const Polynom& x);
	friend std::ostream& operator<< (std::ostream& s, const Polynom& c); 
	friend std::istream& operator >> (std::istream& s, Polynom& c);
	~Polynom();

	


};