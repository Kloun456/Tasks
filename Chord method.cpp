// ВИС 21 Измайлов Егор Метод хорд
#include <iostream>

using namespace std;

double f(double x)
{
    return pow(x,5)-2*cos(x)+1;
}
void foo(double a, double b, double e)
{
    double x=0, x0;
    int iter=0;
    do
    {
        x0 = x;
        x = a - (f(a)*(b-a)/(f(b)-f(a)));
        if (f(x) * f(b) > 0)
            b = x;
        else
            a = x;
        
        /*cout << "f(x) = " << f(x) << "\tf(b)"<< f(b)  << "\tx = " << x << "\ta = "<< a << "\tb = "<< b <<  endl;*/
        if (f(x) == 0)
        {
            cout << "Точное значение корня = " << x << endl;
            cout << "Проверка = " << f(x) << endl;
            cout << "Кол-во итераций = " << iter << endl;
        }
        iter++;
    } while ( iter < 200 && abs(x-x0)>=e);

    if (iter == 200)
        cout << "За 200 итераций не найдено корня.";
    else
    {
        cout.setf(ios::fixed);  
        cout.precision(13);
        cout << "Значение корня = " << x << endl;
        cout << "Проверка = " << f(x) << endl;
        cout << "Кол-во итераций = " << iter << endl;
    }
        

}

int main()
{
    setlocale(0,"");
    double a = 0.81822, b = 0.81833, e = 1e-12;
    foo(a, b, e);
    
}
