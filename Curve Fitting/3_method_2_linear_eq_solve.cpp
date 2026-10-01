#include <bits/stdc++.h>
using namespace std;

const int mx = 20;
const double EPS = 1e-9;


// ============================================================
// GAUSSIAN ELIMINATION
// ============================================================

bool gaussElimination(int n, double M[mx][mx], double X[mx])
{
    // Forward Elimination
    for (int col = 0; col < n; col++)
    {
        // Partial Pivoting
        int piv = col;

        for (int r = col + 1; r < n; r++)
        {
            if (fabs(M[r][col]) > fabs(M[piv][col]))
                piv = r;
        }

        swap(M[piv], M[col]);

        // Check for zero pivot
        if (fabs(M[col][col]) < EPS)
            return false;

        // Eliminate values BELOW pivot
        for (int r = col + 1; r < n; r++)
        {
            double factor = M[r][col] / M[col][col];

            for (int c = col; c <= n; c++)
            {
                M[r][c] -= factor * M[col][c];
            }
        }
    }

    // Back Substitution
    for (int i = n - 1; i >= 0; i--)
    {
        double sum = 0;

        for (int j = i + 1; j < n; j++)
        {
            sum += M[i][j] * X[j];
        }

        X[i] = (M[i][n] - sum) / M[i][i];
    }

    return true;
}


// ============================================================
// GAUSS-JORDAN
// ============================================================

bool gaussJordan(int n, double M[mx][mx], double X[mx])
{
    for (int col = 0; col < n; col++)
    {
        // Partial Pivoting
        int piv = col;

        for (int r = col + 1; r < n; r++)
        {
            if (fabs(M[r][col]) > fabs(M[piv][col]))
                piv = r;
        }

        swap(M[piv], M[col]);

        // Check for zero pivot
        if (fabs(M[col][col]) < EPS)
            return false;

        // Make pivot = 1
        double pivot = M[col][col];

        for (int c = 0; c <= n; c++)
        {
            M[col][c] /= pivot;
        }

        // Make all OTHER values in this column = 0
        for (int r = 0; r < n; r++)
        {
            if (r == col)
                continue;

            double factor = M[r][col];

            for (int c = 0; c <= n; c++)
            {
                M[r][c] -= factor * M[col][c];
            }
        }
    }

    // Solution is directly in last column
    for (int i = 0; i < n; i++)
    {
        X[i] = M[i][n];
    }

    return true;
}


// ============================================================
// LINEAR REGRESSION
// y = a + bx
// ============================================================

void linearRegression(vector<double>& x,
                      vector<double>& y,
                      int solver)
{
    int n = x.size();

    double sumx = 0;
    double sumy = 0;
    double sumxy = 0;
    double sumx2 = 0;

    // Calculate summations
    for (int i = 0; i < n; i++)
    {
        sumx += x[i];
        sumy += y[i];
        sumxy += x[i] * y[i];
        sumx2 += x[i] * x[i];
    }

    /*
        Normal equations:

        n*a + sumx*b  = sumy
        sumx*a + sumx2*b = sumxy
    */

    double M[mx][mx] = {};

    M[0][0] = n;
    M[0][1] = sumx;
    M[0][2] = sumy;

    M[1][0] = sumx;
    M[1][1] = sumx2;
    M[1][2] = sumxy;

    double X[mx] = {};

    bool ok;

    if (solver == 1)
        ok = gaussElimination(2, M, X);
    else
        ok = gaussJordan(2, M, X);

    if (!ok)
    {
        cout << "System cannot be solved.\n";
        return;
    }

    double a = X[0];
    double b = X[1];

    cout << fixed << setprecision(6);

    cout << "\nLinear Regression\n";
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "Best Fit Line:\n";
    cout << "y = " << a << " + "
         << b << "x\n";
}


// ============================================================
// POLYNOMIAL REGRESSION
// y = a + bx + cx^2
// ============================================================

void polynomialRegression(vector<double>& x,
                          vector<double>& y,
                          int solver)
{
    int n = x.size();

    double sx = 0;
    double sx2 = 0;
    double sx3 = 0;
    double sx4 = 0;

    double sy = 0;
    double sxy = 0;
    double sx2y = 0;

    // Calculate required summations
    for (int i = 0; i < n; i++)
    {
        double xi = x[i];
        double yi = y[i];

        sx += xi;
        sx2 += xi * xi;
        sx3 += xi * xi * xi;
        sx4 += xi * xi * xi * xi;

        sy += yi;
        sxy += xi * yi;
        sx2y += xi * xi * yi;
    }

    /*
        Normal equations:

        n*a + sx*b + sx2*c = sy

        sx*a + sx2*b + sx3*c = sxy

        sx2*a + sx3*b + sx4*c = sx2y
    */

    double M[mx][mx] = {};

    M[0][0] = n;
    M[0][1] = sx;
    M[0][2] = sx2;
    M[0][3] = sy;

    M[1][0] = sx;
    M[1][1] = sx2;
    M[1][2] = sx3;
    M[1][3] = sxy;

    M[2][0] = sx2;
    M[2][1] = sx3;
    M[2][2] = sx4;
    M[2][3] = sx2y;

    double X[mx] = {};

    bool ok;

    if (solver == 1)
        ok = gaussElimination(3, M, X);
    else
        ok = gaussJordan(3, M, X);

    if (!ok)
    {
        cout << "System cannot be solved.\n";
        return;
    }

    double a = X[0];
    double b = X[1];
    double c = X[2];

    cout << fixed << setprecision(6);

    cout << "\nPolynomial Regression\n";
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    cout << "Best Fit Quadratic Curve:\n";

    cout << "y = " << a
         << " + " << b << "x"
         << " + " << c << "x^2\n";
}


// ============================================================
// TRANSCENDENTAL REGRESSION
// y = a * e^(bx)
// ============================================================

void transcendentalRegression(vector<double>& x,
                              vector<double>& y,
                              int solver)
{
    int n = x.size();

    double Sx = 0;
    double Sy = 0;
    double Sxx = 0;
    double Sxy = 0;

    // Transformation:
    //
    // y = a * e^(bx)
    //
    // ln(y) = ln(a) + bx
    //
    // Let A = ln(a)
    //
    // Then:
    // Y = A + bx

    for (int i = 0; i < n; i++)
    {
        double X = x[i];
        double Y = log(y[i]);

        Sx += X;
        Sy += Y;
        Sxx += X * X;
        Sxy += X * Y;
    }

    /*
        Normal equations:

        n*A + Sx*b = Sy

        Sx*A + Sxx*b = Sxy
    */

    double M[mx][mx] = {};

    M[0][0] = n;
    M[0][1] = Sx;
    M[0][2] = Sy;

    M[1][0] = Sx;
    M[1][1] = Sxx;
    M[1][2] = Sxy;

    double X[mx] = {};

    bool ok;

    if (solver == 1)
        ok = gaussElimination(2, M, X);
    else
        ok = gaussJordan(2, M, X);

    if (!ok)
    {
        cout << "System cannot be solved.\n";
        return;
    }

    double A = X[0];
    double b = X[1];

    // A = ln(a)
    // Therefore:
    // a = e^A

    double a = exp(A);

    cout << fixed << setprecision(6);

    cout << "\nTranscendental Regression\n";
    cout << "A = " << A << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "Best Fit Transcendental Curve:\n";

    cout << "y = " << a
         << " * e^(" << b << "x)\n";
}


// ============================================================
// MAIN
// ============================================================

int main()
{
    int method;
    int solver;

    cout << "=====================================\n";
    cout << "       REGRESSION METHODS\n";
    cout << "=====================================\n";

    cout << "\n1. Linear Regression\n";
    cout << "2. Polynomial Regression\n";
    cout << "3. Transcendental Regression\n";

    cout << "\nEnter regression method: ";
    cin >> method;

    cout << "\n=====================================\n";
    cout << "          SOLVING METHOD\n";
    cout << "=====================================\n";

    cout << "\n1. Gaussian Elimination\n";
    cout << "2. Gauss-Jordan Elimination\n";

    cout << "\nEnter solving method: ";
    cin >> solver;

    int n;

    cout << "\nEnter number of data points: ";
    cin >> n;

    vector<double> x(n);
    vector<double> y(n);

    cout << "\nEnter x and y values:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    // Select regression method

    if (method == 1)
    {
        linearRegression(x, y, solver);
    }
    else if (method == 2)
    {
        polynomialRegression(x, y, solver);
    }
    else if (method == 3)
    {
        // Transcendental regression requires y > 0
        for (int i = 0; i < n; i++)
        {
            if (y[i] <= 0)
            {
                cout << "Error: Transcendental regression "
                     << "requires y > 0.\n";
                return 0;
            }
        }

        transcendentalRegression(x, y, solver);
    }
    else
    {
        cout << "Invalid regression method!\n";
    }

    return 0;
}
