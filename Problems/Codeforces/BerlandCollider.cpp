#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n;
double x, v;
vector<pair<double, double>> a;

int main()
{
    cout.precision(20);

    cin >> n;

    rep(i, n)
    {
        cin >> x >> v;
        a.push_back({x, v});
    }

    double l = 0;
    double r = 1e10;
    rep(k, 1000)
    {
        double m = (l + r) * 0.5;

        bool collision = false;
        double prev = DBL_MIN;
        bool compare = false;
        rep(i, n)
        {
            double pos = a[i].first + a[i].second * m;
            if (compare && i > 0 && a[i].second < 0 && pos <= prev)
                collision = true;
            if (a[i].second > 0)
            {
                prev = max(prev, pos);
                compare = true;
            }
        }

        if (collision)
            r = m;
        else
            l = m;
    }

    if (r < 1e10)
        cout << (l + r) * 0.5 << '\n';
    else
        cout << -1 << '\n';
}