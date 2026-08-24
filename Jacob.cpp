#include<bits/stdc++.h>
using namespace std;

double ep = 0.0001;

int main()
{
    int n;
    cin >> n;

    double a[n][n];
    double b[n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
        cin >> b[i];
    }

    double x[n];

    for(int i = 0; i < n; i++)
        x[i] = 0;

    double oldx[n];

    while(true)
    {
        for(int i = 0; i < n; i++)
            oldx[i] = x[i];

        for(int i = 0; i < n; i++)
        {
            double sum = 0;

            for(int j = 0; j < n; j++)
            {
                if(i != j)
                    sum += a[i][j] * oldx[j];   // Jacobi
            }

            x[i] = (b[i] - sum) / a[i][i];
        }

        bool done = true;

        for(int i = 0; i < n; i++)
        {
            if(abs(oldx[i] - x[i]) >= ep)
            {
                done = false;
                break;
            }
        }

        if(done)
            break;
    }

    for(int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
}
