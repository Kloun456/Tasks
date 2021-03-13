// ВИС 21 Измайлов Егор Метод половинного деления
#include <iostream>

using namespace std;

double f(double x)
{
	return sin(1+pow(x,2))-x;
}

void foo(double a, double b, double e)
{
	int iter = 1;
	double x;
	while (abs(b - a) >= e && iter < 200)
	{
		x = (a + b) / 2.0;
		if (f(x) == 0)
		{
			cout << "Найден точный корень x = " << x << endl;
			cout << "Кол-во итераций = " << iter << endl;
			cout << "Проверка f(x) =" << f(x) << endl;
			break;
		}
		else if (f(a) * f(x) < 0)
			b = x;
		else
			a = x;
		iter++;
		/*cout << "x = " << x << "\ta = " << a << "\tb = " << b << "\tf(x) = " << f(x) << endl;*/
	} 
	if (iter >= 200)
		cout << "За 200 итераций не удалось вычислить корень на данном отрезке. " << endl;
	else
	{
		x = (a + b) / 2.0;
		cout << "Корень x = " << x << endl;
		cout << "Кол-во итераций = " << iter << endl;
		cout << "Проверка f(x) = " << f(x) << endl;
	}
		
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout.setf(ios::fixed);
	cout.precision(13);
	double a=0.94721, b=0.94722, e=1e-12;
	foo(a, b, e);
}

