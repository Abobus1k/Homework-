#include <vector>
#include <iostream>
#include <fstream>

class Matrix {
private:
	int rows;
	int cols;
	std::vector<std::vector<double>> matrix;
public:
	Matrix()
	{
		std::cout << "Number of rows: ";
		std::cin>> rows;
		std::cout << "Number of columns: ";
		std::cin >> cols;
		for (int i = 0; i < rows; ++i)
		{
			matrix.push_back(std::vector<double>());
			for (int j = 0; j < cols; ++j)
			{
				matrix[i].push_back(0.0);
			}
		 
		}
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				std::cin >> matrix[i][j];
			}
		}
	}
	Matrix(int m, int n)
	{
		this->rows = n;
		this->cols = m;
		for (int i = 0; i < rows; ++i)
		{
			matrix.push_back(std::vector<double>());
			for (int j = 0; j < cols; ++j)
			{
				matrix[i].push_back(0.0);
			}
		}
	}
	friend std::ostream& operator<<(std::ostream& out, const Matrix& x)
	{
		for (int i = 0; i < x.rows; ++i)
		{
			for (int j = 0; j < x.cols; ++j)
			{
				out << x.matrix[i][j]<<'\t';
			}
			out << "\n";
			out << "\n";
			out << "\n";
		}
		return out;
	}
	Matrix operator*(const Matrix& x)
	{
		Matrix tmp(this->rows, x.cols);
		for (int i = 0; i < tmp.rows; ++i)
		{
			for (int j = 0; j < tmp.cols; ++j)
			{
				for (int k = 0; k < cols; ++k)
				{
					tmp.matrix[i][j] += matrix[i][k] * x.matrix[k][j];
				}
			}
		}
		this->matrix = tmp.matrix;
		this->cols = tmp.cols;
		this->rows = tmp.rows;
		return *this;
		//return tmp;
	}


};


int main(int argc, char*argv[])
{
	Matrix a;
	Matrix b;
	std::ofstream out(argv[1]);
	out << a;
	out<< b;
	out << a * b;
	
	return 1;
}