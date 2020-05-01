#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (int)n; i++)
typedef long long ll;

ll T, n;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;

        vector<ll> ans;
        ll l = 0, s = 0;
        rep(i, 32)
        {
            if (s >= n) break;
            s += 1ll << i;
            ans.push_back(1ll << i);
            l = 1ll << i;
        }

        if (s > n)
        {
            s -= l;
            ll r = n - s;
            l >>= 1ll;
            ans.pop_back();
            if (r >= l) ans.push_back(r);
            else
            {
                l >>= 1ll;
                ans.pop_back();
                ans.push_back(l + r / 2ll);
                ans.push_back(l + r / 2ll + bool(r % 2ll));
            }
        }

        cout << ans.size() - 1 << '\n';
        l = ans[0];
        if (ans.size() - 1)
        {
            rep(i, ans.size()) if (i) { cout << ans[i] - l << ' '; l = ans[i]; }
            cout << '\n';
        }
    }
}