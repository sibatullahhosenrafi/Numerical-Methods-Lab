#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return sqrt(x);
}

void simp(double a, double b, int n, double h) {
    double ans = f(a) + f(b);

    double sum1 = 0;
    double sum2 = 0;

    for (int i=1; i<n; i++) {
        double x = a+i*h;
        if (i%3==0) {
            sum1 += f(x);
        }
        else sum2 += f(x);
    }

    ans += 3*sum2 + 2*sum1;
    ans = ans*3*h/8;
    cout << ans << endl;
}

int main() {
    double a, b;
    int n;
    cin >> a >> b >> n;

    double h = (b - a) / n;
    simp(a, b, n, h);

    return 0;
}
