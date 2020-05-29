#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

long long T, h, c, t;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> h >> c >> t;

        double m = (c + h) * 0.5;

        if (t <= m + 0.00001) { cout << 2 << '\n'; continue; }
        if (t >= h) { cout << 1 << '\n'; continue; }

        long long l = 1;
        long long r = 1e15;
        while (l < r)
        {
            long long mid = (l + r) / 2ll;
            double d = (h * mid + c * (mid - 1.)) / (2. * mid - 1.) - t;
            if (d <= 0) r = mid;
            else l = mid + 1;
        }

        if (l > 1)
        {
            double d1 = (h * l + c * (l - 1)) / (2. * l - 1.) - t;
            double d2 = (h * (l - 1) + c * (l - 2)) / (2. * (l - 1) - 1.) - t;
            if (abs(d2) < abs(d1)) l--;
        }

        cout << (2ll * l - 1ll) << '\n';
        // cerr << (h * l + c * (l - 1)) / (2. * l - 1.) - t << '\n';
    }
}