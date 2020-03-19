#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

ll n, k, p;

int main()
{
    cin >> n >> k;

    ll ans1 = 0;
    rep(i, k) ans1 += (n - i);

    ll ans2 = 1;
    ll aux = 0;
    bool add = false;
    rep(i, n)
    {
        cin >> p;
        if (p > n - k)
        {
            if (add) ans2 = (ans2 * (aux + 1)) % 998244353;
            aux = 0;
            add = true;
        }
        else aux++;
    }

    cout << ans1 << ' ' << ans2 << '\n';
}