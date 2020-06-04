#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

ll T, a, b;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> a >> b;
        if (a > b) swap(a, b);

        if (b % a) { cout << -1 << '\n'; continue; }

        ll ans = 0;

        bool flag = false;
        ll p = (b / a);
        if (p != 1 && p % 2) flag = true;
        while (p > 1ll)
        {
            if (p % 2) { flag = true; break; }
            p /= 2ll;
            ans++;
        }

        if (flag) { cout << -1 << '\n'; continue; }

        cout << ans / 3ll + bool(ans % 3ll) << '\n';
    }
}