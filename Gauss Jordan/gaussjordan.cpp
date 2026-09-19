#include <bits/stdc++.h>
using namespace std;

const int mx = 20;
const double EPS = 1e-9;

int n;
double M[mx][mx]; // augmented matrix (n rows, n+1 columns)

void solveSystem()
{
    // go column by column (col = the pivot column, 0 .. n-1)
    for (int col = 0; col < n; col++)
    {
        // --- partial pivoting: bring the largest value in this column to the top ---
        int piv = col;
        for (int r = col + 1; r < n; r++)
            if (fabs(M[r][col]) > fabs(M[piv][col]))
                piv = r;
        swap(M[piv], M[col]);

        if (fabs(M[col][col]) < EPS)
            continue; // no usable pivot in this column, move on

        // --- make the pivot 1 by dividing the whole row ---
        double pivotVal = M[col][col];
        for (int c = 0; c < n + 1; c++)
            M[col][c] /= pivotVal;

        // --- make every OTHER row 0 in this column (both above and below) ---
        for (int r = 0; r < n; r++)
        {
            if (r == col) continue;
            double factor = M[r][col];
            for (int c = 0; c < n + 1; c++)
                M[r][c] -= factor * M[col][c];
        }
    }

    cout << fixed << setprecision(3);

    cout << "\nReduced Row Echelon Form :\n";
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
        cout << "No solution\n";
    else if (rank < n)
        cout << "Infinite solutions\n";
    else
    {
        cout << "Unique solution\n";
        cout << "Solution:\n";
        for (int i = 0; i < n; i++)
            cout << "x" << i + 1 << " = " << M[i][n] << endl;
    }
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
