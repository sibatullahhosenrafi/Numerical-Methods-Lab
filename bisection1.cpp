#include<bits/stdc++.h>
using namespace std;
double a, b, c, d, e;
double steps = 0.5;
double ep = 0.0001;
double func(double x)
{
    return a * x * x * x * x + b * x * x * x + c * x * x + d * x + e;
}
double bisection_method(double x1,double x2,int &iterations)
{
    iterations = 0;
    while(abs(func(x1)-func(x2))>=ep)
    {
        double x0 = (x1 + x2) / 2;
        iterations++;
        if(abs(func(x0))<ep)
        {
            return x0;
        }
        else if(func(x0)*func(x1)<0)
        {
            x2 = x0;
        }
        else {
            x1 = x0;
        }
    }
        return (x1 + x2) / 2;

}

int main()
{
    cin >> a >> b >> c >> d>>e;
    double xmax = sqrt(pow(b / a, 2) - 2 * c / a);
    double x1 = -xmax;
    double x2 = x1 + steps;
    int rootcount = 0;
    while (x2 < xmax)
    {
        if(func(x2)*func(x1)<0)
        {
            int iterations;
            rootcount++;
            double root = bisection_method(x1, x2, iterations);
            cout << rootcount << " root: " << root << " interval" << "[" << x1 << "," << x2 << "]" << endl;
            cout << "Iterative method for " << rootcount << "root :" << iterations << endl;
        }
        x1 += steps;
        x2 += steps;
    }
}
