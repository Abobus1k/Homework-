#include "Header.h"
Polynom::Polynom()
{
	dgr_ = 0;
	coeff_ = NULL;
}
Polynom::Polynom(int degree, double* clist)
{
	this->dgr_ = degree;
	this->coeff_ = new double[dgr_ + 1];
	for (int i = 0; i <= dgr_; ++i)
	{
		this->coeff_[i] = clist[i];
	}
}
Polynom::Polynom(const Polynom& x)
{
	this->dgr_ = x.dgr_;
	this->coeff_ = new double[dgr_ + 1];
	for (int i = 0; i <= dgr_; ++i)
	{
		this->coeff_[i] = x.coeff_[i];
	}
}

Polynom Polynom::operator=(const Polynom& x)
{
	this->dgr_ = x.dgr_;
	if (this->coeff_ != NULL)
	{
		delete[] this->coeff_;
	}
	this->coeff_ = new double[dgr_ + 1];
	for (int i = 0; i <= dgr_; ++i)
	{
		this->coeff_[i] = x.coeff_[i];
	}
	return *this;
}

Polynom::~Polynom()
{
	dgr_ = 0;
	delete[] coeff_;
}
std::istream& operator>>(std::istream& s, Polynom& c)// перегруженный оператор ввода
{
    int i;
    for (i = 0; i <= c.dgr_; i++)
    {
        s >> c.coeff_[i];
    }
    return s;
}
std::ostream& operator<<(std::ostream& s, const Polynom& c)
{
    int i, n = 0;
    for (i = 0; i <= c.dgr_; i++)
    {
        if (c.coeff_[i] != 0)
            n++;
    }
    if (n != 0)
    {
        if (c.coeff_[0] != 0)
        {
            s << c.coeff_[0];
        }
        for (i = 1; i <= c.dgr_; i++)
        {
            if (c.coeff_[i] < 0)
            {
                if (c.coeff_[i] != -1)
                    s << c.coeff_[i] << "X^" << i;
                else
                    s << "-" << "X^" << i;
            }
            else
            {
                if (c.coeff_[i] != 0)
                {
                    if (c.coeff_[i] != 1)
                        s << "+" << c.coeff_[i] << "X^" << i;
                    else
                        s << "+" << "X^" << i;
                }
            }
        }
        s << '\n';
    }
    else
    {
        s << 0;
    }
    return s;
}
Polynom Polynom::operator+(const Polynom& x)
{
    Polynom Z = *this;
    if (Z.dgr_ > x.dgr_)//this>x
    {
        for (int i = 0; i <= x.dgr_; ++i)
        {
            Z.coeff_[i] = Z.coeff_[i] + x.coeff_[i];
        }
        return Z;
    }
    if (this->dgr_ < x.dgr_)//this<x
    {
        Polynom Z1;
        Z1 = Z;
        Z = x;//Теперь this>z
        for (int i = 0; i <= Z1.dgr_; ++i)
        {
            Z.coeff_[i] = Z.coeff_[i] + Z1.coeff_[i];
        }
        return Z;
    }
    else //this=x
    {
        for (int i = 0; i <= x.dgr_; ++i)
        {
            Z.coeff_[i] = Z.coeff_[i] + x.coeff_[i];
        }
        return Z;
    }
    return Z;
}
Polynom Polynom::operator-(const Polynom& x)
{
    Polynom Z = *this;
    if (Z.dgr_ > x.dgr_)//this>x
    {
        for (int i = 0; i <= x.dgr_; ++i)
        {
            Z.coeff_[i] = Z.coeff_[i] - x.coeff_[i];
        }
        return Z;
    }
    if (Z.dgr_ < x.dgr_)//this<x
    {
        Polynom Z1;
        Z1 = Z;
        Z = x;//Теперь this>z
        for (int i = 0; i <= Z1.dgr_; ++i)
        {
            Z.coeff_[i] = -Z.coeff_[i] + Z1.coeff_[i];
        }
        for (int j = Z1.dgr_ + 1; j <= Z.dgr_; ++j)
        {
           Z.coeff_[j] = -Z.coeff_[j];
        }
        return Z;
    }
    else //this=x
    {
        for (int i = 0; i <= x.dgr_; ++i)
        {
            Z.coeff_[i] = Z.coeff_[i] - x.coeff_[i];
        }
        return Z;
    }
    return Z;
}

Polynom Polynom::operator*(const Polynom& x)
{
    Polynom Z;
    Z = *this;
    Polynom Z1;
    double cycle;
    Z1.dgr_ = Z.dgr_ + x.dgr_;
    Z1.coeff_ = new double[Z1.dgr_ + 1];
    for (int m = 0; m <= Z1.dgr_; ++m)
    {
        Z1.coeff_[m] = 0.0;
    }
    for (int k = 0; k <= Z1.dgr_; ++k)
    {
        for (int i = 0; i <= Z.dgr_; ++i)
        {
            for (int j = 0; j <= x.dgr_; ++j)
            {
                if ((i + j) == k)
                {
                    
                    Z1.coeff_[k]+= Z.coeff_[i] * x.coeff_[j];
                }
            }
        }
    }
    Z = Z1;
    return Z;
}
