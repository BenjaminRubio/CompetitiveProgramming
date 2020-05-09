#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

ll T, n;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;

        ll ans = 0;
        while (n > 1)
        {
            ll h = 1;
            while ((3ll * (h * (h + 1ll)) / 2ll - h) <= n) h++;
            h--;
            n -= (3ll * (h * (h + 1ll)) / 2ll - h);
            ans++;
        }
        cout << ans << '\n';
    }
}