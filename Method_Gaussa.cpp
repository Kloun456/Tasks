// Измайлов Егор ВИС 21 Метод Гаусса
#include <iostream>
#include <iomanip>

using namespace std;

void copy_matrix(long double** copy_matrix, long double** matrix, const int &n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = copy_matrix[i][j];
		}
	}
}

void filling_matrix(long double** matrix, const int &n)
{
	matrix[0][0] = -3;
	matrix[0][1] = 2;
	matrix[0][2] = 9;
	matrix[0][3] = -5;
	matrix[1][0] = 3;
	matrix[1][1] = 1;
	matrix[1][2] = -3;
	matrix[1][3] = 11;
	matrix[2][0] = 3;
	matrix[2][1] = 7;
	matrix[2][2] = 4;
	matrix[2][3] = 8;
	matrix[3][0] = -5;
	matrix[3][1] = 2;
	matrix[3][2] = 4;
	matrix[3][3] = 9;
}

void filling_unit_matrix(long double **inv_matrix, const int &n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				inv_matrix[i][j] = 1;
			else
				inv_matrix[i][j] = 0;
		}
	}
}

void print_matrix(long double **matrix, const int &n)
{
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		for (int j = 0; j < n; j++)
		{
			cout << setw(4) << matrix[i][j] <<"\t";
		}
	}
	cout << endl;
}

void print_vector(long double *vector, const int &n)
{
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		cout << setw(4)<<vector[i] << "\t";
	}
	
}

void gauss(long double** matrix, long double **inv_matrix, long double* vector, long double* x, const int &n) 
{
	int i, j, m, j1; 
	long double glav, temp, det = 1;
	for (m = 0; m < n; m++)
	{
		glav = matrix[m][m];
		j1 = m;
		for (j = m; j < n; j++)
		{
			if (glav < matrix[j][m])
			{
				glav = matrix[j][m];
				j1 = j;
			}
		}
		det *= glav;
		if (j1 != m)   //swap
		{
			det = -det;
			for (j = m; j < n; j++)
			{
				temp = matrix[m][j];
				matrix[m][j] = matrix[j1][j];
				matrix[j1][j] = temp;
			}
			for (j = 0; j < n; j++)
			{
				temp = inv_matrix[m][j];
				inv_matrix[m][j] = inv_matrix[j1][j];
				inv_matrix[j1][j] = temp;
			}
			temp = vector[m];
			vector[m] = vector[j1];
			vector[j1] = temp;
		}  // end swap

		for (j = m; j < n; j++)
			matrix[m][j] /= glav;
		for (j = 0; j < n; j++)
			inv_matrix[m][j] /= glav;
		vector[m] /= glav;

		for (i = m + 1; i < n; i++)
		{
			glav = matrix[i][m];
			for (j = m; j < n; j++)
			{
				matrix[i][j] = matrix[i][j] - matrix[m][j] * glav;
			}
			for (j = 0; j < n; j++)
			{
				inv_matrix[i][j] = inv_matrix[i][j] - inv_matrix[m][j] * glav;
			}
			vector[i] = vector[i] - vector[m] * glav;
		}
	}
	
	for (m = n - 1; m >= 0; m--) // invert matrix
	{
		for (i = m - 1; i >= 0; i--)
		{
			glav = matrix[i][m];
			for (j = 0; j < n; j++)
			{
				inv_matrix[i][j] = inv_matrix[i][j] - inv_matrix[m][j] * glav;
			}
		}
	}     // end invert matrix
	x[n - 1] = vector[n - 1] / matrix[n - 1][n - 1];
	for (i = n-1; i >= 0; i--) 
	{
		x[i] = vector[i];                          
		for (j = i + 1; j < n; j++)  
			x[i] = x[i] - matrix[i][j] * x[j];    
	}
	cout << "\n\nDetermination: " << det << endl;
}

long double *check(long double **check_matrix, long double *x ,const int &n)
{
	long double* ch = new long double[n] {0, 0, 0, 0};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ch[i] += x[j]*check_matrix[i][j];
		}
	}
	return ch;
}

void check_invert(long double** check_matrix, long double** inv_matrix, const int& n)
{
	long double** result_matrix = new long double* [n];
	for (int i = 0; i < n; i++)
		result_matrix[i] = new long double[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			result_matrix[i][j] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				result_matrix[i][j] += check_matrix[i][k] * inv_matrix[k][j];
			}
		}
	}
	copy_matrix(result_matrix, check_matrix, n);
}

int main()
{
	const int n=4;
	long double **matrix , **check_matrix, *vector, *x, **inv_matrix;
	vector = new long double[n] {-6,7,6,4};
	x = new long double[n];
	matrix = new long double* [n];
	for (int i = 0; i < n; i++)
		matrix[i] = new long double[n];
	check_matrix = new long double* [n];
	for (int i = 0; i < n; i++)
		check_matrix[i] = new long double[n];
	inv_matrix = new long double* [n];
	for (int i = 0; i < n; i++)
		inv_matrix[i] = new long double[n];

	filling_unit_matrix(inv_matrix, n);
	filling_matrix(matrix,n);
	copy_matrix(matrix, check_matrix, n);
	cout << "Coefficient matrix:\n";
	print_matrix(matrix,n);
	cout << "\nVector:";
	print_vector(vector, n);
	gauss(matrix, inv_matrix, vector, x, n);
	cout.setf(ios::fixed);
	cout.precision(16);
	cout << "\nSolution: ";
	print_vector(x, n);
	cout.unsetf(ios::fixed);
	cout.precision(0);
	cout << "\n\nCheck:";
	x = check(check_matrix, x, n);
	print_vector(x, n);
	cout << "\n\nInvert_matrix: ";
	print_matrix(inv_matrix, n);
	cout << "\n\n Check invert_matrix: ";
	check_invert(check_matrix, inv_matrix, n);
	print_matrix(check_matrix, n);

	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
		delete[] check_matrix[i];
		delete[] inv_matrix[i];
	}
	delete inv_matrix;
	delete check_matrix;
	delete matrix;
	delete[] vector;
	delete[] x;
}
