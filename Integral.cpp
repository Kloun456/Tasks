// ВИС 21  Измайлов Егор
#include <iostream>
#include <ctime>
#include <thread>

using namespace std;

double foo(double x)
{
    return abs(pow(sin(pow(pow(x,3)+1,0.5)),1.5));
}

void trapezoid(int n, double a, double b, double e)
{
    double s = 0, s1 = 1, h, x;
    int iter = 0;
    while (abs(s1 - s) >= e)
    {
        s = s1;
        h = (b - a) / n;
        x = a + h;
        s1 = 0;
        for (int i = 0; i < n-2; i++)
        {
            s1 += foo(x);
            x += h;
        }
        s1 = h * (((foo(a) + foo(b)) / 2) + s1);
        n *= 2;
        iter++;
        
    }
    cout << "\nTrapezium method:\n";
    cout << "\nSum = " << s1;
    cout << "\n\nIter = " << iter << endl;

}

void middle_rectangle(int n, double a, double b, double e)
{
    double s = 0, s1 = 1, h, x;
    int iter = 0;
    while (abs(s1 - s) >= e)
    {
        s = s1;
        h = (b - a) / n;
        x = a;
        s1 = 0;
        for (int i = 0; i < n; i++)
        {
            s1 += foo((x+x+h)/2.0);
            x += h;
        }
        s1 *= h;
        n *= 2;
        iter++;

    }
    cout << "\nMiddle rectangle method:\n";
    cout << "\nSum = " << s1;
    cout << "\n\nIter = " << iter << endl;
}

void right_rectangle(int n, double a, double b, double e)
{
    double s = 0, s1 = 1, h, x;
    int iter = 0;
    while (abs(s1 - s) >= e)
    {
        s = s1;
        h = (b - a) / n;
        x = a + h;
        s1 = 0;
        for (int i = 0; i <= n; i++)
        {
            s1 += foo(x);
            x += h;
        }
        
        s1 *= h;
        n *= 2;
        iter++;
    }
    cout << "\nRight rectangle method:\n";
    cout << "\nSum = " << s1;
    cout << "\n\nIter = " << iter << endl;
}

void left_rectangle(int n, double a, double b, double e)
{
    double s = 0, s1 = 1, h, x;
    int iter = 0;
    while (abs(s1 - s) >= e)
    {
        s = s1;
        h = (b - a) / n;
        x = a;
        s1 = 0;
        for (int i = 0; i < n; i++)
        {
            s1 += foo(x);
            x += h;
        }
        s1 *= h;
        n *= 2;
        iter++; 
       
    }
    cout << "\nLeft rectangle method:\n";
    cout << "\nSum = " << s1;
    cout << "\n\nIter = " << iter << endl;
}

int main()
{
    double n = 100;
    double a = -1, b = 2, e = pow(10, (-7));
    thread th1(right_rectangle,n,a,b,e);
    thread th2(left_rectangle,n,a,b,e);
    thread th3(middle_rectangle,n,a,b,e);
    
    cout.setf(ios::fixed);
    cout.precision(13);

    trapezoid(n,a,b,e);
    th1.join();
    th2.join();
    th3.join();
    cout << endl << clock();
}