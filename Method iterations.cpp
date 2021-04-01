// ВИС 21 Измайлов Егор Метод итераций
#include <iostream>

using namespace std;

double f(double x)
{
    return pow((2*cos(x)-1),(1.0/5.0));
}

double check(double x0)
{
    return pow(x0, 5) - 2 * cos(x0) + 1;
}

void foo(double x0, double e)
{
    int iter=0;
    double x;
    do
    {
        x = x0;
        /*cout << " x =" << x << "\tx0 = " << x0 << "\tf(x) = " << f(x0) << endl;*/
        x0 = f(x0);
        iter++;
    } while (abs(x0 - x) >= e && iter<200);
    
    if (iter == 200)
        cout << " За 200 итераций не нашлось корня. " << endl;
    else
    {
        cout << "x = " << x0 << endl;
        cout << "Check: " << check(x0) << endl;
        cout << "Iterations: " << iter << endl;

    }
        
}


int main()
{
    setlocale(0, "");
    cout.setf(ios::fixed);
    cout.precision(13);
    double e=1e-12, x0=0.81822;
    foo(x0,e);
    return 0;
}

