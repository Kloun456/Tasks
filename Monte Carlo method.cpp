// ВИС 21 Измайлов Егор
#include <iostream>
#include <ctime>

using namespace std;

double foo(double x, double y, double z)
{
    return x * y + y * z;
}

void Monte_Carlo(int n, double a1, double b1, double a2, double b2, double a3, double b3)
{
    double x, y, z, s = 0;
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        x = a1 + (b1 - a1) * ((float)rand() / RAND_MAX);
        y = a2 + (b2 - a2) * ((float)rand() / RAND_MAX);
        z = a3 + (b3 - a3) * ((float)rand() / RAND_MAX);
        s += foo(x, y, z);
    }
    s *= (b1 - a1) * (b2 - a2) * (b3 - a3) / n;
    cout << s;
}

int main()
{
    int n;
    double a1 = 0, b1 = 1, a2 = 1, b2 = 2, a3 = 0, b3 = 3;
    cout << "Eneter quantity trials: ";
    cin >> n;
    Monte_Carlo(n,a1,b1,a2,b2,a3,b3);

}