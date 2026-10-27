#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return 1.0 / (1.0 + (x * x));
}

// void simp(double a, double b, int n, double h) {
//     double ans = f(a) + f(b);

//     double odd_sum = 0;
//     double x = a+h;
//     while (x<b) {
//         odd_sum += f(x);
//         x += 2*h;
//     }

//     double even_sum = 0;
//     x = a+2*h;
//     while (x<b) {
//         even_sum += f(x);
//         x += 2*h;
//     }

//     ans += 4*odd_sum + 2*even_sum;

//     ans = (h/3)*ans;
//     cout << ans << endl;
// }

void simp(double a, double b, int n, double h) {
    double ans = f(a) + f(b);

    double odd_sum = 0;
    double even_sum = 0;

    for (int i=1; i<n; i++) {
        double x = a+i*h;
        if (i%2==1) {
            odd_sum += f(x);
        }
        else even_sum += f(x);
    }

    ans += 4*odd_sum + 2*even_sum;

    ans = (h/3)*ans;
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
