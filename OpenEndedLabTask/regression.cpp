#include<bits/stdc++.h>
using namespace std;

double eps = 1e-9;
int n;

vector<double> gauss_jordan(vector<vector<double>>& arr, int sz)
{
    int row = 0;
    for(int col = 0; col < sz && row < sz; col++)
    {
        int piv_row = row;
        for(int i = row + 1; i < sz; i++)
        {
            if(fabs(arr[i][col]) > fabs(arr[piv_row][col])) piv_row = i;
        }
        if(fabs(arr[piv_row][col]) <= eps) continue;
        
        swap(arr[row], arr[piv_row]);
        double pivot = arr[row][col];
        for(int i = 0; i <= sz; i++)
        {
            arr[row][i] /= pivot;
        }
        for(int i = 0; i < sz; i++)
        {
            if(i == row) continue;
            double m = arr[i][col];
            for(int j = col; j <= sz; j++)
            {
                arr[i][j] -= arr[row][j] * m;
            }
        }
        row++;
    }
    
    vector<double> ans(sz, 0);
    for(int i = 0; i < sz; i++)
    {
        ans[i] = arr[i][sz];
    }
    return ans;
}

// y = a + bx
void linear(vector<double> x, vector<double> y)
{
    double xi = 0, yi = 0, xi2 = 0, xiyi = 0;
    for(int i = 0; i < n; i++)
    {
        xi += x[i];
        yi += y[i];
        xi2 += x[i] * x[i];
        xiyi += x[i] * y[i];
    }
    vector<vector<double>> arr(2, vector<double>(3));
    arr[0][0] = n;   arr[0][1] = xi;  arr[0][2] = yi;
    arr[1][0] = xi;  arr[1][1] = xi2; arr[1][2] = xiyi;
    
    vector<double> ans = gauss_jordan(arr, 2);
    cout << "Linear Equation:" << endl;
    cout << "y = " << ans[0] << " + " << ans[1] << "x" << endl;
}

// y = a * e^(bx)
void td(vector<double> x, vector<double> y)
{
    double xi = 0, yi = 0, xi2 = 0, xiyi = 0;
    for(int i = 0; i < n; i++)
    {
        xi += x[i];
        yi += log(y[i]);
        xi2 += x[i] * x[i];
        xiyi += x[i] * log(y[i]);
    }
    vector<vector<double>> arr(2, vector<double>(3));
    arr[0][0] = n;   arr[0][1] = xi;  arr[0][2] = yi;
    arr[1][0] = xi;  arr[1][1] = xi2; arr[1][2] = xiyi;
    
    vector<double> ans = gauss_jordan(arr, 2);
    double a = exp(ans[0]), b = ans[1];
    cout << "Exponential Equation:" << endl;
    cout << "y = " << a << " * e^(" << b << "x)" << endl;
}

// y = a * x^b
void td2(vector<double> x, vector<double> y)
{
    double xi = 0, yi = 0, xi2 = 0, xiyi = 0;
    for(int i = 0; i < n; i++)
    {
        xi += log(x[i]);
        yi += log(y[i]);
        xi2 += log(x[i]) * log(x[i]);
        xiyi += log(x[i]) * log(y[i]);
    }
    vector<vector<double>> arr(2, vector<double>(3));
    arr[0][0] = n;   arr[0][1] = xi;  arr[0][2] = yi;
    arr[1][0] = xi;  arr[1][1] = xi2; arr[1][2] = xiyi;
    
    vector<double> ans = gauss_jordan(arr, 2);
    double a = exp(ans[0]), b = ans[1];
    cout << "Power Equation:" << endl;
    cout << "y = " << a << " * x^(" << b << ")" << endl;
}

// y = a + bx + cx^2
void poly(vector<double> x, vector<double> y)
{
    double xi = 0, xi2 = 0, yi = 0, xi3 = 0, xiyi = 0, xi4 = 0, xi2yi = 0;
    for(int i = 0; i < n; i++)
    {
        xi += x[i];
        yi += y[i];
        xi2 += x[i] * x[i];
        xi3 += pow(x[i], 3);
        xi4 += pow(x[i], 4);
        xiyi += x[i] * y[i];
        xi2yi += x[i] * x[i] * y[i];
    }
    vector<vector<double>> arr(3, vector<double>(4));
    arr[0][0] = n;   arr[0][1] = xi;  arr[0][2] = xi2; arr[0][3] = yi;
    arr[1][0] = xi;  arr[1][1] = xi2; arr[1][2] = xi3; arr[1][3] = xiyi;
    arr[2][0] = xi2; arr[2][1] = xi3; arr[2][2] = xi4; arr[2][3] = xi2yi;

    vector<double> ans = gauss_jordan(arr, 3);
    cout << "Polynomial Equation:" << endl;
    cout << "y = " << ans[0] << " + " << ans[1] << "x + " << ans[2] << "x^2" << endl;
}

int main()
{
    cout << "Enter number of data points (n): ";
    cin >> n;

    vector<double> x(n), y(n);
    cout << "Enter x and y values:" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    cout << "\n1. Linear\n2. Exponential\n3. Power\n4. Polynomial\n5. All\n";
    cout << "Enter choice: ";
    int choice;
    cin >> choice;
    cout << endl;

    if(choice == 1) linear(x, y);
    else if(choice == 2) td(x, y);
    else if(choice == 3) td2(x, y);
    else if(choice == 4) poly(x, y);
    else if(choice == 5)
    {
        linear(x, y);
        cout << endl;
        td(x, y);
        cout << endl;
        td2(x, y);
        cout << endl;
        poly(x, y);
    }

    return 0;
}
