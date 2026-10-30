#include <iostream>
#include <string>
#include <windows.h>

double** create_two_dim_array(int size_x, int size_y);
void fill_two_dim_array(double** mass2d, int size_x, int size_y);
void print_two_dim_array(double** mass2d, int size_x, int size_y);
void delete_two_dim_array(double** mass2d, int size_x);


double** create_two_dim_array(int size_x, int size_y)
{
	//double** out1d{ nullptr };
	//double* out2d{ nullptr };

	if (size_x > 0)
	{
		double** out1d = new double* [size_x] {0};

		for (int i = 0; i < size_x; i++) 
		{
			out1d[i] = new double[size_y] {0};
		}

		return(out1d);
	}
	else
	{
		return(nullptr);
	}
}



void fill_two_dim_array(double **mass2d, int size_x, int size_y)
{
	for (int i = 0; i < size_x; i++)
	{
		for (int j = 0; j < size_y; j++)
		{
			mass2d[i][j] = (j+1)*(i+1);
		}
	}
}

void print_two_dim_array(double** mass2d, int size_x, int size_y) 
{
	for (int i = 0; i < size_x; i++)
	{
		for (int j = 0; j < size_y; j++)
		{
			std::cout << mass2d[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

void delete_two_dim_array(double** mass2d, int size_x)
{
	for (int i = 0; i < size_x; i++)
	{
		delete[] mass2d[i];
	}
	delete[] mass2d;
}


int main(int argc, char** argv)
{
	int size_x{ 0 }, size_y{ 0 };
	double** mass{ nullptr };


	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	std::cout << "Введите количество строк: ";
	std::cin >> size_x;

	std::cout << "Введите количество столбцов: ";
	std::cin >> size_y;

	if ((size_x<= 0) || (size_y <= 0))
	{
		return(1);
	}

	mass = create_two_dim_array(size_x, size_y);

	fill_two_dim_array(mass, size_x , size_y);
	std::cout << "Таблица умножения: " << std::endl;
	print_two_dim_array(mass, size_x, size_y);


	delete_two_dim_array(mass, size_x);


	return(0);
}

