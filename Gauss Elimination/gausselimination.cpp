#include <bits/stdc++.h>
using namespace std;

const int mx = 20;
const double EPS = 1e-9;

int n;
double M[mx][mx]; // augmented matrix (n rows, n+1 columns)
double X[mx];

void solveSystem()
{
    // ---------- forward elimination: turn M into upper triangular form ----------
    for (int col = 0; col < n; col++)
    {
        // partial pivoting: bring the largest value in this column to the pivot row
        int piv = col;
        for (int r = col + 1; r < n; r++)
            if (fabs(M[r][col]) > fabs(M[piv][col]))
                piv = r;
        swap(M[piv], M[col]);

        if (fabs(M[col][col]) < EPS)
            continue; // no usable pivot in this column, move on

        // eliminate this column only in the rows BELOW the pivot
        for (int r = col + 1; r < n; r++)
        {
            double factor = M[r][col] / M[col][col];
            for (int c = col; c < n + 1; c++)
                M[r][c] -= factor * M[col][c];
        }
    }

    cout << fixed << setprecision(3);

    cout << "\nUpper triangular (row echelon) form :\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }

    // ---------- decide the type of solution ----------
    int type = 1; // 1 = solvable, 0 = no solution
    int rank = 0;

    for (int i = 0; i < n; i++)
    {
        bool rowZero = true;
        for (int j = 0; j < n; j++)
            if (fabs(M[i][j]) > EPS)
                rowZero = false;

        if (rowZero && fabs(M[i][n]) > EPS)
        {
            type = 0; // 0 = nonzero -> contradiction
            break;
        }
        else if (!rowZero)
            rank++;
    }

    if (type == 0)
    {
        cout << "No solution\n";
        return;
    }
    if (rank < n)
    {
        cout << "Infinite solutions\n";
        return;
    }

    // ---------- back substitution ----------
    for (int i = n - 1; i >= 0; i--)
    {
        double sum = 0;
        for (int j = i + 1; j < n; j++)
            sum += M[i][j] * X[j];
        X[i] = (M[i][n] - sum) / M[i][i];
    }

    cout << "Unique solution\n";
    cout << "Solution:\n";
    for (int i = 0; i < n; i++)
        cout << "x" << i + 1 << " = " << X[i] << endl;
}

int main()
{
    cout << "Enter number of equations: ";
    cin >> n;

    cout << "Enter the augmented matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n + 1; j++)
            cin >> M[i][j];

    solveSystem();

    return 0;
}
