// Измайлов Егор ВИС 21 Метод итераций для СЛАУ
#include <iostream>
#include <iomanip>

using namespace std;

void Check(double** matrix, double* vector, double* x, double *deviders, const int& n)
{
    double* check = new double[n];
    for (int i = 0; i < n; i++)
        check[i] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                check[i] = check[i] + x[i] * deviders[i];
            else
                check[i] -= matrix[i][j] * x[j];
        }
        check[i] -= vector[i];
    }
    for (int i = 0; i < n; i++)
        x[i] = check[i];
    delete[] check;
}

double Max(double x1, double x2, double x3, double x4)
{
    double max;
    max = x1;
    if (max < x2)
    {
        max = x2;
        if (max < x3)
            max = x3;
        else if (max < x4)
            max = x4;
    }
    else if (max < x3)
    {
        max = x3;
        if (max < x4)
            max = x4;
    }
    else
        max = x4;
    return max;
}

void Print_vector(double* vector, const int& n)
{
    for (int i = 0; i < n; i++)
        cout << setw(4) << vector[i] << endl;
}

void Print_matrix(double** matrix, const int& n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(4) << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void Filling_matrix(double** matrix)
{
    matrix[0][0] = 0;
    matrix[0][1] = -3;
    matrix[0][2] = 1;
    matrix[0][3] = -2;
    matrix[1][0] = -2;
    matrix[1][1] = 0;
    matrix[1][2] = -1;
    matrix[1][3] = 1;
    matrix[2][0] = -1;
    matrix[2][1] = 2;
    matrix[2][2] = 0;
    matrix[2][3] = 2;
    matrix[3][0] = -1;
    matrix[3][1] = -1;
    matrix[3][2] = 2;
    matrix[3][3] = 0;
}

void Filling_matrix(double** matrix, const int& n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }
}

void Zeidel(double** matrix, double* vector, double* x, double *devider,const int& n, const double& eps)
{
    double* x1 = new double[n];
    int iter = 1;
    for (int i = 0; i < n; i++)
        x1[i] = vector[i];

    for (iter; iter < 200; iter++)
    {
        for (int i = 0; i < n; i++)
            x[i] = x1[i];
        for (int i = 0; i < n; i++)
            x1[i] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j < i)
                    x1[i] += matrix[i][j] * x1[j];
                else 
                    x1[i] += matrix[i][j] * x[j];
            }
            x1[i] = (x1[i] + vector[i])/devider[i];
        }
        if (Max(abs(x1[0] - x[0]), abs(x1[1] - x[1]), abs(x1[2] - x[2]), abs(x1[3] - x[3])) < eps)
            break;
    }
    for (int i = 0; i < n; i++)
        x[i] = x1[i];
    cout << "\nIter: " << iter;
    cout << "\n\nResult: " << endl;
    Print_vector(x, n);
    cout << "\nCheck:\n";
    Check(matrix, vector, x1, devider, n);
    Print_vector(x1, n);
}

int main()
{
    double** matrix, * vector, * x, e = 1e-12, *deviders;
    int n = 4;
    x = new double[n] {0};
    deviders = new double [n] {9, -7, 6, -9};
    vector = new double [n] {1, 5, 2, 1};
    matrix = new double* [n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new double[n];
    }
    cout << "Matrix:\n";
    Filling_matrix(matrix);
    Print_matrix(matrix, n);
    cout << "Vector:\n";
    Print_vector(vector, n);
    cout.setf(ios::fixed);
    cout.precision(13);
    Zeidel(matrix, vector, x, deviders, n, e);
    

}