// Измайлов Егор  ВИС 21  Интерполяционная формула Лагранжа
#include <iostream>

using namespace std;

void foo(double* x0, double* yf, const int &n1)
{
	for (int i = 0; i < n1; i++)
	{
		yf[i] = sin(x0[i]) / (1 + pow(x0[i], 2));
	}
}

void fx(int a, int b, double *x, int n)
{
	double pi = 3.141592653589793;
	for (int i = 0; i < n; i++)
	{
		x[i] = ((b + a) / 2 + ((b - a) / 2) * cos((pi*(2*i+1))/(2*n)));
	}
}

void fy(double* x, double* y, int n)
{
	for (int i = 0; i < n; i++)
	{
		y[i] = (sin(x[i])) / (1 + pow(x[i],2));
	}
}

void Lagrange(double *x, double *y, double *x0, double *yL3, const int &n, const int &n1)
{
	double S, p;
	for (int m = 0; m < n1; m++)
	{
		S = 0;
		for (int i = 0; i < n; i++)
		{
			p = 1;
			for (int j = 0; j < n; j++)
			{
				if (i != j)
				{
					p *= (x0[m] - x[j]) / (x[i] - x[j]);
				}
			}
			S += y[i] * p;
		}
		yL3[m] = S;
	} 
}

void Check(double* x, double* y, double x0, double S, const int& n)
{
	cout << "\nx = " << x0 ;
	for (int i = 0; i < n; i++)
	{
		if (x0 < x[i+1] && x0 > x[i])
		{
			cout << "\nx = " << x[i] << "   y = " << y[i];
			cout << "\nx = " << x0 << "   y = " << S;
		}
		else
			cout << "\nx = " << x[i] << "   y = " << y[i];
	}
}

int main()
{
	double* x, * y, *x0 , S, *yL3, *yf;
	int n = 4, a = -3, b = 3, n1 = 13;
	x = new double[n];
	y = new double[n];
	x0 = new double[n1]{-3,-2.5,-2,-1.5,-1,-0.5,0,0.5,1,1.5,2,2.5,3};
	yL3 = new double[n1];
	yf = new double[n1];

	cout << "X:\n";
	fx(a, b, x, n);
	for (int i = 0; i < n; i++)
		cout << x[i] << "     ";

	cout << "\nY:\n";
	fy(x, y, n);
	for (int i = 0; i < n; i++)
		cout << y[i] << "     ";

	cout << "\nCheck:\n";
	cout << "x         L3               f(x) \n";
	Lagrange(x,y,x0,yL3,n,n1);
	foo(x0, yf, n1);
	for (int i = 0; i < n1; i++)
	{
		cout << x0[i] << "\t" << yL3[i] << "\t" << yf[i] << endl;
	}

	delete[] x;
	delete[] x0;
	delete[] y;
	delete[] yf;
	delete[] yL3;	
}
