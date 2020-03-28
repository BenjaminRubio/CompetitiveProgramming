#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n;
double x, v;
pair<double, double> a[500000];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cout.precision(12);

    cin >> n;

    rep(i, n) cin >> a[i].first >> a[i].second;

    double l = 0;
    double r = 5e9;
    rep(k, 65)
    {
        double m = (l + r) * .5;

        double prev = -1e9;
        bool collision = false, compare = false;
        rep(i, n)
        {
            double pos = a[i].first + a[i].second * m;
            if (a[i].second < 0 && compare && pos <= prev)
                collision = true;
            if (a[i].second > 0)
            {
                prev = max(prev, pos);
                compare = true;
            }
        }

        if (collision) r = m;
        else l = m;
    }

    if (r < 3e9)
        cout << (l + r) * 0.5 << '\n';
    else
        cout << -1 << '\n';
}