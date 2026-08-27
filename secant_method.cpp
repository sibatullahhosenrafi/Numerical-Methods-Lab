#include <bits/stdc++.h>
using namespace std;

#define EPSILON 0.001
#define steps 0.45

double coef[20];
int n;

double func(double x)
{
    double result = 0;

    for(int i = 0; i <= n; i++)
    {
        result += coef[i] * pow(x, n - i);
    }

    return result;
}

double secant(double x1, double x2, int &iteration)
{
    iteration = 0;

    while(true)
    {
        double f1 = func(x1);
        double f2 = func(x2);

        double x0 = x2 - (f2 * (x2 - x1)) / (f2 - f1);

        iteration++;

        if(abs(x0 - x2) < EPSILON &&
           abs(func(x0) / f2) < EPSILON)
        {
            return x0;
        }

        x1 = x2;
        x2 = x0;
    }
}

int main()
{
    cin >> n;

    // Input coefficients:
    // an, an-1, ..., a1, a0
    for(int i = 0; i <= n; i++)
    {
        cin >> coef[i];
    }

    // Calculate xmax
    double xmax = 0;

    for(int i = 1; i <= n; i++)
    {
        xmax = max(xmax, abs(coef[i] / coef[0]));
    }

    xmax = 1 + xmax;

    double x1 = -xmax;
    double x2 = x1 + steps;

    int rootCount = 0;

    while(x2 <= xmax)
    {
        if(func(x1) * func(x2) < 0)
        {
            int iteration;

            rootCount++;

            double root = secant(x1, x2, iteration);

            cout << rootCount << " root : " << root << endl;

            cout << "Search interval of " << rootCount
                 << " root : [" << x1 << "," << x2 << "]"
                 << endl;

            cout << "Iteration needed for " << rootCount
                 << " root : " << iteration << endl;
        }

        x1 += steps;
        x2 += steps;
    }

    return 0;
}
