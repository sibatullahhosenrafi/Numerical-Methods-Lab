#include<bits/stdc++.h>
using namespace std;

#define eps 1e-9

int n;

vector<double> gauss_jordan(vector<vector<double>> arr, int sz)
{
    int row = 0;

    for(int col=0; col<sz and row<sz; col++)
    {
        int prow = row;

        for(int i=row+1; i<sz; i++)
        {
            if(fabs(arr[i][col]) > fabs(arr[prow][col]))
                prow = i;
        }

        if(fabs(arr[prow][col]) < eps)
            continue;

        swap(arr[prow], arr[row]);

        double pivot = arr[row][col];

        for(int j=0; j<=sz; j++)
        {
            arr[row][j] /= pivot;
        }

        for(int i=0; i<sz; i++)
        {
            if(i==row)
                continue;

            double m = arr[i][col];

            for(int j=0; j<=sz; j++)
            {
                arr[i][j] -= m*arr[row][j];
            }
        }

        row++;
    }

    int rank = row;

    for(int i=rank; i<sz; i++)
    {
        if(fabs(arr[i][sz]) > eps)
        {
            cout << "No solution" << endl;
            return {};
        }
    }

    if(rank<sz)
    {
        cout << "Inf solution" << endl;
        return {};
    }

    vector<double> ans(sz);

    for(int i=0; i<sz; i++)
    {
        ans[i] = arr[i][sz];
    }

    return ans;
}


// Linear Model
// y = a + bz

vector<double> linear(vector<double> z, vector<double> y)
{
    double zi=0, yi=0, zi2=0, ziyi=0;

    for(int i=0; i<n; i++)
    {
        zi += z[i];
        yi += y[i];
        zi2 += z[i]*z[i];
        ziyi += z[i]*y[i];
    }

    vector<vector<double>> arr(2, vector<double>(3));

    arr[0][0] = n;
    arr[0][1] = zi;
    arr[0][2] = yi;

    arr[1][0] = zi;
    arr[1][1] = zi2;
    arr[1][2] = ziyi;

    vector<double> ans = gauss_jordan(arr,2);

    return ans;
}


// Power Model
// y = pz^q

vector<double> power(vector<double> z, vector<double> y)
{
    double zi=0, yi=0, zi2=0, ziyi=0;

    for(int i=0; i<n; i++)
    {
        double Z = log(z[i]);
        double Y = log(y[i]);

        zi += Z;
        yi += Y;
        zi2 += Z*Z;
        ziyi += Z*Y;
    }

    vector<vector<double>> arr(2, vector<double>(3));

    arr[0][0] = n;
    arr[0][1] = zi;
    arr[0][2] = yi;

    arr[1][0] = zi;
    arr[1][1] = zi2;
    arr[1][2] = ziyi;

    vector<double> ans = gauss_jordan(arr,2);

    double p = exp(ans[0]);
    double q = ans[1];

    return {p,q};
}


// Polynomial Model
// y = a + bz + cz^2

vector<double> poly(vector<double> z, vector<double> y)
{
    double zi=0, yi=0, ziyi=0;
    double zi2=0, zi3=0, zi4=0, zi2yi=0;

    for(int i=0; i<n; i++)
    {
        zi += z[i];
        yi += y[i];
        zi2 += z[i]*z[i];
        ziyi += z[i]*y[i];
        zi3 += pow(z[i],3);
        zi4 += pow(z[i],4);
        zi2yi += pow(z[i],2)*y[i];
    }

    vector<vector<double>> arr(3, vector<double>(4));

    arr[0][0] = n;
    arr[0][1] = zi;
    arr[0][2] = zi2;
    arr[0][3] = yi;

    arr[1][0] = zi;
    arr[1][1] = zi2;
    arr[1][2] = zi3;
    arr[1][3] = ziyi;

    arr[2][0] = zi2;
    arr[2][1] = zi3;
    arr[2][2] = zi4;
    arr[2][3] = zi2yi;

    vector<double> ans = gauss_jordan(arr,3);

    return ans;
}


int main()
{
    cout << "Enter number of data points: ";
    cin >> n;

    vector<double> z(n), y(n);

    cout << "Enter z values:\n";

    for(int i=0; i<n; i++)
    {
        cin >> z[i];
    }

    cout << "Enter y values:\n";

    for(int i=0; i<n; i++)
    {
        cin >> y[i];
    }


    // Determine linear parameters

    vector<double> linear_ans = linear(z,y);

    double a = linear_ans[0];
    double b = linear_ans[1];


    // Determine power parameters

    vector<double> power_ans = power(z,y);

    double p = power_ans[0];
    double q = power_ans[1];


    // Determine polynomial parameters

    vector<double> poly_ans = poly(z,y);

    double A = poly_ans[0];
    double B = poly_ans[1];
    double C = poly_ans[2];


    cout << fixed << setprecision(4);


    // Display parameters

    cout << "\nLinear Model Parameters:\n";
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;


    cout << "\nPower Model Parameters:\n";
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;


    cout << "\nPolynomial Model Parameters:\n";
    cout << "a = " << A << endl;
    cout << "b = " << B << endl;
    cout << "c = " << C << endl;


    // Display equations

    cout << "\n==============================" << endl;
    cout << "Equations" << endl;
    cout << "==============================" << endl;

    cout << "Linear      : y = "
         << a << " + " << b << "z" << endl;

    cout << "Power       : y = "
         << p << "z^" << q << endl;

    cout << "Polynomial  : y = "
         << A << " + " << B << "z + "
         << C << "z^2" << endl;


    // Estimate y at z = 6

    double Z = 6;

    double linear_y = a + b*Z;

    double power_y = p*pow(Z,q);

    double poly_y = A + B*Z + C*Z*Z;


    cout << "\n==============================" << endl;
    cout << "Estimation at z = 6" << endl;
    cout << "==============================" << endl;

    cout << "Linear Model     : y = "
         << linear_y << endl;

    cout << "Power Model      : y = "
         << power_y << endl;

    cout << "Polynomial Model : y = "
         << poly_y << endl;

    return 0;
}
