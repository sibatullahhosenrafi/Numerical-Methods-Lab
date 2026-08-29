#include <bits/stdc++.h>
using namespace std;

double ep = 0.001;
double step = 0.45;

double coeff[20];
int n;

double func(double x)
{
    double result = 0;

    for(int i = 0; i <= n; i++)
    {
        result += coeff[i] * pow(x, n - i);
    }

    return result;
}

double derivative(double x)
{
    double result = 0;

    for(int i = 0; i < n; i++)
    {
        result += (n - i) * coeff[i] * pow(x, n - i - 1);
    }

    return result;
}

double newton(double x, int &iteration)
{
    iteration = 0;

    while(true)
    {
        double fx = func(x);
        double dfx = derivative(x);

        double x0 = x - fx / dfx;

        iteration++;

        if(abs(x0 - x) < ep &&
           abs(func(x0) / fx) < ep)
        {
            return x0;
        }

        x = x0;
    }
}

int main()
{
    cin >> n;

    // Input:
    // an, an-1, ..., a1, a0
    for(int i = 0; i <= n; i++)
    {
        cin >> coeff[i];
    }

    // Calculate xmax
    double xmax = 0;

    for(int i = 1; i <= n; i++)
    {
        xmax = max(xmax, abs(coeff[i] / coeff[0]));
    }

    xmax = 1 + xmax;

    double x1 = -xmax;
    double x2 = x1 + step;

    int rootcount = 0;

    while(x2 <= xmax)
    {
        if(func(x1) * func(x2) < 0)
        {
            int iteration;

            rootcount++;

            // Use x1 as initial guess
            double root = newton(x1, iteration);

            cout << rootcount << " root : "
                 << root << endl;

            cout << "Search interval of " << rootcount
                 << " root : ["
                 << x1 << "," << x2 << "]"
                 << endl;

            cout << "Iteration needed for " << rootcount
                 << " root : "
                 << iteration << endl;
        }

        x1 += step;
        x2 += step;
    }

    return 0;
}
