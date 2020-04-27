#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

ll T, X;
vector<ll> lucky, l = {0, 4, 7};
vector<ll> ans(6);
bool DP[10000][7];

bool dp(ll x, int i)
{
    if (i == 6) return (x == 0);

    if (!DP[x][i]) return false;

    for (ll y : lucky)
    {
        if (y > x) break;
        if (dp(x - y, i + 1))
        {
            ans[i] = y;
            return true;
        }
    }

    return DP[x][i] = false;
}

int main()
{
    rep(i1, 3) rep(i2, 3) rep(i3, 3)
        lucky.push_back(l[i1] * 100 + l[i2] * 10 + l[i3]);

    cin >> T;
    while (T--)
    {
        memset(DP, true, sizeof DP);
        ans.assign(6, 0ll);

        cin >> X;

        ll X1 = X % 4000ll, X2 = X - X1;
        if (!dp(X1, 0))
        {

            X1 += 4000ll;
            X2 -= 4000ll;
            if (X2 < 0 or !dp(X1, 0))
            {
                cout << -1 << '\n';
                continue;
            }
        }

        ll pow = 1000;
        X2 = X2 / 4000ll;
        while (X2)
        {
            ll d = X2 % 10ll; X2 /= 10ll;
            if (d > 6)
            {
                rep(i, 4) ans[i + 2] += 7ll * pow;
                d -= 7ll;
            }
            rep(i, d) ans[i] += 4ll * pow;
            pow *= 10ll;
        }

        rep(i, 6) cout << ans[i] << ' ';
        cout << '\n';
    }
}