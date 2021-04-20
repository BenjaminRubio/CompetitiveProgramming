#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

const double PI = acos(-1.0L);

int T;
double b, c;

double f(double x)
{
    return (x * x + b * x + c) / sin(x);
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> b >> c;

        double l = 0, r = .5 * PI;
        rep(_, 100)
        {
            double t = (r - l) / 3, m1 = l + t, m2 = r - t;

            double f1 = f(m1), f2 = f(m2);
            if (f1 <= f2) r = m2;
            if (f1 >= f2) l = m1;
        }

        cout.precision(10);
        cout << f((l + r) * .5) << '\n';
    }
}