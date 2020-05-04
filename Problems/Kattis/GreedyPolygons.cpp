#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

const double PI = 3.141592653589793238462643383279502884L;

int T;
double n, l, d, g;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(10);

    cin >> T;
    while (T--)
    {
        cin >> n >> l >> d >> g;
        d *= g;

        double a = l * l * n / (4. * tan(PI / n));

        a += n * l * d;
        a += PI * d * d;

        cout << a << '\n';
    }
}