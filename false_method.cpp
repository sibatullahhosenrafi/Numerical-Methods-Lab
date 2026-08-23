#include <bits/stdc++.h>

using namespace std;

double e = 0.01;
double func(double x)
{
    return x*x*x - 2*x*x +3*x +4;
}

void falseMethod(double a, double b)
{
    if(func(a) * func(b) >= 0)
    {
        cout << "Your assumed range is wrong";
        return;
    }

    double x0;
    double x1 = a;
    double x2 = b;

    int i = 0;

    while(abs(x2-x1)/abs(x2) >= e)
    {
        i++;

        x0 = x1 - (func(x1) * (x2-x1))
             / (func(x2) - func(x1));
//must use abs here
        if(abs(func(x0))<e)
        {
            break;
        }

        else if(func(x0) * func(x1) < 0)
        {
            x2 = x0;
        }
        else
        {
            x1 = x0;
        }

        cout << "Iteration " << i
             << "  x0 = " << x0 << endl;
    }

    cout << "Root: " << x0 << endl;
    cout << "Iterations: " << i << endl;
}

int main()
{
    //has to take small range here
    double a =-2, b =0.5;
    falseMethod(a,b);
}
