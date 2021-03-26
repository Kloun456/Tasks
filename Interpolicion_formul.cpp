// Измайлов Егор ВИС 21 Первая интерполяционная формула Ньютона
#include <iostream>


using namespace std;

void interpolic(double *y, double x, double x0, double h, const int &n)
{
    double s = y[0], q, q1 = 1;
    q = (x - x0) / h;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n-i; j++)
        {
            y[j] = y[j + 1] - y[j];
        }
        q1 = q1 * (q - i + 1) / i;
        s += q1 * y[0];
    }
    cout << s;
}

int main()
{
    int n=6;
    double x = 1.1, x0 = 1, h = 0.2, *y;
    y = new double[n] {1.1,1.9,3.2,3.8,4.9,5.8};
    cout << "Result:\n";
    cout.setf(ios::fixed);
    cout.precision(7);
    interpolic(y, x, x0, h, n);
}
