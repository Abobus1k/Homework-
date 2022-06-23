#include <vector>
#include <iostream>
#include <cmath>

class K
{
private:
	std::vector<double> coef;
	double pi = 3.14;

public:
	K()
	{
		coef.resize(6);
		for (int i = 0; i < 6; ++i)
		{
			coef.push_back(0.0);
		}
	}
	K(K& x)
	{
		coef.resize(6);
		for (int i = 0; i < 6; ++i)
		{
			coef[i] = x.coef[i];
		}
	}
	K(double* coef_)
	{
		coef.resize(6);
		for (int i = 0; i < 6; ++i)
		{
			coef[i] = coef_[i];
		}
	}	
	K Transport(double x, double y)
	{
		double i, j, k;
		i = 2 * coef[0] * x + coef[1] * y + coef[3];//coef[3]=i
		j = coef[1] * x + 2 * coef[2] * y + coef[4];
		k = coef[0] * x * x + coef[1] * x * y + coef[2] * y * y + coef[3] * x + coef[4] * y + coef[5];
		coef[3] = i;
		coef[4] = j;
		coef[5] = k;
		return *this;
	}
	K Rotate(double phi)
	{
		double teta;
		teta = phi * pi / 180;
		double x1, x2, x3, x4, x5;
		x1 = coef[0] * cos(teta) * cos(teta) + coef[1] * cos(teta) * sin(teta) + coef[2] * sin(teta) + sin(teta);
		x2 = coef[0] * sin(teta) * sin(teta) - coef[1] * cos(teta) * sin(teta) + coef[2] * cos(teta) * cos(teta);
		x3 = -2 * coef[0] * cos(teta) * sin(teta) + coef[1] * (cos(teta) * cos(teta) - sin(teta) * sin(teta)) + 2 * coef[2] * sin(teta) * cos(teta);
		x4 = coef[3] * cos(teta) + coef[4] * sin(teta);
		x5 = -coef[3] * sin(teta) + coef[4] * cos(teta);
		coef[0] = x1;
		coef[2] = x2;
		coef[1] = x3;
		coef[3] = x4;
		coef[4] = x5;
		return *this;

	}
	friend std::ostream& operator<<(std::ostream& out, const K& k)
	{
		out << k.coef[0] << "x^2+";
		out << k.coef[1]<<"xy+";
		out << k.coef[2]<<"y^2+";
		out << k.coef[3]<<"x+";
		out << k.coef[4]<<"y+";
		out << k.coef[5];
			
		return out;
	}
};




int main()
{
	double a[6] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };
	K KRIV(a);
	KRIV.Rotate(30);
	std::cout << KRIV;
	return 1;
}
