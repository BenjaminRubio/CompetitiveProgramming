#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n;
vector<double> x, v;

int main()
{
    cout.precision(10);

    cin >> n;

    x.resize(n); v.resize(n);
    rep(i, n) cin >> x[i];
    rep(i, n) cin >> v[i];

    double l = 0, r = 1e9 + 1;
    rep(i, 1000)
    {
        double m = (l + r) * 0.5;

        double L = DBL_MIN, R = DBL_MAX;
        rep(i, n)
        {
            L = max(L, x[i] - v[i] * m);
            R = min(R, x[i] + v[i] * m);
        }

        if (R >= L) r = m;
        else l = m;
    }

    cout << (l + r) * 0.5 << '\n';
}