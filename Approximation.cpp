//Измайлов Егор  ВИС 21 
#include <iostream>

using namespace std;

void Filling_x(double *x)
{
    x[0] = 0;
    x[1] = 2;
    x[2] = 3;
    x[3] = 5;
}

void Filling_y(double *y)
{
    y[0] = 110;
    y[1] = 130;
    y[2] = 149;
    y[3] = 168;
}

void copy_matrix(double **coefficient, double **coefficient_temp, const int &n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            coefficient_temp[i][j] = coefficient[i][j];
    }
}

void multiplication_matrix(double *free_coef, double** coefficient, double* result, const int& n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i] += coefficient[i][j] * free_coef[j];
        }
    }
}

void filling_unit_matrix(double** inv_matrix, const int& n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                inv_matrix[i][j] = 1;
            else
                inv_matrix[i][j] = 0;
        }
    }
}

void gauss(double** matrix, double* vector, double* x, const int& n)
{
    int i, j, m, j1;
    long double glav, temp;
    for (m = 0; m < n; m++)
    {
        glav = matrix[m][m];
        j1 = m;
        for (j = m; j < n; j++)
        {
            if (glav < matrix[j][m])
            {
                glav = matrix[j][m];
                j1 = j;
            }
        }
        
        if (j1 != m)   //swap
        {
            
            for (j = m; j < n; j++)
            {
                temp = matrix[m][j];
                matrix[m][j] = matrix[j1][j];
                matrix[j1][j] = temp;
            }
            
            temp = vector[m];
            vector[m] = vector[j1];
            vector[j1] = temp;
        }  // end swap

        for (j = m; j < n; j++)
            matrix[m][j] /= glav;
        
        vector[m] /= glav;

        for (i = m + 1; i < n; i++)
        {
            glav = matrix[i][m];
            for (j = m; j < n; j++)
            {
                matrix[i][j] = matrix[i][j] - matrix[m][j] * glav;
            }
            
            vector[i] = vector[i] - vector[m] * glav;
        }
    }

    x[n - 1] = vector[n - 1] / matrix[n - 1][n - 1];
    for (i = n - 1; i >= 0; i--)
    {
        x[i] = vector[i];
        for (j = i + 1; j < n; j++)
            x[i] = x[i] - matrix[i][j] * x[j];
    }
   
}

void Approximation(double **coefficient, double *free_coef, double *x, double *y, double *result, const int &q, const int &n)
{
    double temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            coefficient[i][j] = 0;
            for (int l = 0; l < q; l++)
                coefficient[i][j] += pow(x[l], i + j);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < q; j++)
        {
            free_coef[i] += y[j] * pow(x[j], i);
        }
    }

    cout << "\nMatrix coefficient:";
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        for (int j = 0; j < n; j++)
            cout << coefficient[i][j] << "\t";
    }

    cout << "\n\nMatrix free coefficient:\n";
    for (int i = 0; i < n; i++)
        cout << free_coef[i] << "\t";

  
    gauss(coefficient,free_coef,result,n);

    cout << "\nMatrix coefficient:";
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        for (int j = 0; j < n; j++)
            cout << coefficient[i][j] << "\t";
    }

    
}


int main()
{
    double **coefficient,*free_coef, *result, *x, *y;
    int k, q, n;
    cout << "Enter the power of the equation: ";
    cin >> k;
    cout << "\nEnter the quantity of point: ";
    cin >> q;
    n = k + 1;
    x = new double[n];
    y = new double[n];
    result = new double[n] {0};
    free_coef = new double[n] {0};
    coefficient = new double *[n];
    for (int i = 0; i < n; i++)
    {
        coefficient[i] = new double[n];
    }
    Filling_x(x);
    Filling_y(y);
    Approximation(coefficient, free_coef, x, y, result, q, n);

    cout << "\n\nResult:\n";
    for (int i = 0; i < n; i++)
        cout << "a"<< i << " = " <<result[i] << endl;

    
}
