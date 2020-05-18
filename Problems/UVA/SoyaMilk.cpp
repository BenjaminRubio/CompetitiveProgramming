#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

const double PI = acos(-1.0);

double l, w, h, t;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(3);

    while (cin >> l >> w >> h >> t)
    {
        t *= PI / 180.;
        double a = atan2(h, l);

        if (t < a) cout << w * l * (h - l * tan(t) * 0.5);
        else cout << w * h * h * tan(PI * 0.5 - t) * 0.5;

        cout << " mL\n";
    }
}