#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

ll u, v;
vector<ll> ans(3, 0);

int main()
{
    cin >> u >> v;

    if (u > v) { cout << -1 << '\n'; return 0; }

    bool pos = true;
    rep(i, 64)
    {
        ll aux = ans[0] + ans[1] + ans[2];
        if (!((1ll << i) & u) and !((1ll << i) & v) and (aux & (1ll << i)))
        {
            if (ans[0] & (1ll << (i - 1))) ans[2] |= (1ll << (i - 1));
            else ans[0] |= (1ll << (i - 1));
            ans[1] |= (1ll << (i - 1));
        }
        if (!((1ll << i) & u) and ((1ll << i) & v) and !(aux & (1ll << i)))
        {
            if (i == 0) { pos = false; break; }
            if (ans[0] & (1ll << (i - 1))) ans[2] |= (1ll << (i - 1));
            else ans[0] |= (1ll << (i - 1));
            ans[1] |= (1ll << (i - 1));
        }
        if (((1ll << i) & u) and !((1ll << i) & v) and !(aux & (1ll << i)))
        {
            if (i == 0) { pos = false; break; }
            if (ans[0] & (1ll << (i - 1))) ans[2] |= (1ll << (i - 1));
            else ans[0] |= (1ll << (i - 1));
            ans[1] |= (1ll << (i - 1)), ans[0] |= (1ll << i);
        }
        if (((1ll << i) & u) and !((1ll << i) & v) and (aux & (1ll << i)))
            ans[0] |= (1ll << i);
        if (((1ll << i) & u) and ((1ll << i) & v) and (aux & (1ll << i)))
        {
            if (i == 0) { pos = false; break; }
            if (ans[0] & (1ll << (i - 1))) ans[2] |= (1ll << (i - 1));
            else ans[0] |= (1ll << (i - 1));
            ans[1] |= (1ll << (i - 1)), ans[0] |= (1ll << i);
        }
        if (((1ll << i) & u) and ((1ll << i) & v) and !(aux & (1ll << i)))
            ans[0] |= (1ll << i);
    }

    if (!pos) { cout << -1 << '\n'; return 0; }

    int l = 0;
    rep(i, 3) if (ans[i] != 0) l = i + 1;
    cout << l << '\n';
    rep(i, l) cout << ans[i] << ' ';
    cout << '\n';
}