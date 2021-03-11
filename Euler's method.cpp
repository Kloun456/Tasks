// ВИС 21 Измайлов Егор
#include <iostream>
#define n 21
using namespace std;

long double foo(long double x, long double y)
{
    return (x * y) / (1 + pow(x, 2) + pow(y, 2));
}

void filling_x(long double* x, double h)
{
    x[0] = 1;
    for (int i = 1; i < n; i++)
        x[i] = x[i - 1] + h;
}

void Euler(long double* x, long double* y, double h)
{
    y[0] = 1;
    for (int i = 1; i < n; i++)
    {
        y[i] = y[i - 1] + foo(x[i-1],y[i-1]) * h;
        y[i] = y[i - 1] + h * (foo(x[i - 1], y[i - 1]) + foo(x[i], y[i])) / 2;
    }
}

void Runge(long double* x, long double* y, double h)
{
    long double k1, k2, k3, k4;
    y[0] = 1;
    for (int i = 1; i < n; i++)
    {
        k1 = foo(x[i - 1], y[i - 1]);
        k2 = foo(x[i - 1] + h / 2.0, y[i - 1] + h * k1 / 2);
        k3 = foo(x[i - 1] + h / 2.0, y[i - 1] + h * k2 / 2);
        k4 = foo(x[i - 1] + h, y[i - 1] + h * k3);
        y[i] = y[i - 1] + (h / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4));
    }
}

int main()
{
    double h = 0.05;
    long double* x = new long double[n];
    long double* y = new long double[n];
    filling_x(x,h);
    cout.setf(ios::fixed);
    cout.precision(13);
    Runge(x, y, h);
    cout << "Method Runge Kuta:\n";
    cout << "i\tx\t\ty\n";
    for (int i = 0; i < n; i++)
    {
        cout << i << "\t" << x[i] << "\t" << y[i] << endl;
    }
    Euler(x, y, h);
    cout << "\nEuler's method:\n";
    cout << "i\tx\t\ty\n";
    for (int i = 0; i < n; i++)
    {
        cout << i << "\t" << x[i] << "\t" << y[i] << endl;
    }
}
