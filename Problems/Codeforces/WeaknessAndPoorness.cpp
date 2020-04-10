#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n;
vector<int> a;

double calc(double x)
{
    double M = 0, M_ = 0;
    double aux = 0, aux_ = 0;
    rep(i, n)
    {
        aux += a[i] - x; aux = max(0., aux);
        aux_ += x - a[i]; aux_ = max(0., aux_);
        M = max(M, aux);
        M_ = max(M_, aux_);
    }
    return max(M, M_);
}

int main()
{
    cout.setf(ios::fixed);
    cout.precision(10);

    cin >> n;

    a.resize(n);
    rep(i, n) cin >> a[i];

    double l = -20000, r = 20000;
    rep(_, 100)
    {
        double t = (r - l) / 3.;
        double v1 = calc(l + t);
        double v2 = calc(r - t);

        if (v1 >= v2) l = l + t;
        if (v2 >= v1) r = r - t;
    }

    cout << calc((l + r) / 2.) << '\n';
}