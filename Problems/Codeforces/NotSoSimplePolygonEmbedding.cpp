#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long double ld;

const ld PI = acos(-1.0);

int T;
ld N;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(10);

    cin >> T;
    while (T--)
    {
        cin >> N;

        ld a = PI / (2. * N), a_ = a * 0.5;
        ld L = 1. / sin(a);

        ld l = 0, r = PI;
        rep(_, 100)
        {
            ld t = (r - l) / 3.;
            ld m1 = l + t, m2 = r - t, v1, v2;

            v1 = max(cos(a_ - m1), cos(m1));
            v2 = max(cos(a_ - m2), cos(m2));

            if (v1 > v2) l = m1;
            if (v1 < v2) r = m2;
            if (v1 == v2) l = m1, r = m2;
        }

        ld m = (l + r) * 0.5;
        ld v = L * max(cos(a_ - m), cos(m));

        cout << -1. * v << '\n';
    }
}