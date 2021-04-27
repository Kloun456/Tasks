// ВИС 21 Измайлов Егор Метод Ньютона
#include <iostream>

using namespace std;

double f(double x)
{
    return pow(x,5)-2*cos(x)+1;
}

double fd(double x)
{
    return 5 * pow(x, 4) + 2 * sin(x);
}

void foo(double x0, double e)
{
    int iter=1;
    
    while(f(x0) / fd(x0) >= e && iter < 200)
    {
        /*cout << x0 << "\tf(x) = " << f(x0) << "\tfd(x) = " << fd(x0) << endl;*/
        x0 = x0 - f(x0) / fd(x0);
        iter++;
        if (f(x0) == 0)
        {
            cout << "Точный корень x = " << x0 << endl;
            cout << "Проверка f(x)= " << f(x0) << endl;
            cout << "Кол-во итераций = " << iter << endl;
        }
    } 

    if (iter == 200)
        cout << "За 200 итераций не нашлось корня." << endl;
    else
    {
        cout << "Корень x = " << x0 << endl;
        cout << "Проверка f(x)= " << f(x0) << endl;
        cout << "Кол-во итераций = " << iter << endl;
    }
}

int main()
{
    setlocale(0, "");
    double x0=0.81833,e=1e-12;
    cout.setf(ios::fixed);
    cout.precision(13);
    foo(x0, e);
}

