#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define ff first
#define ss second

ll T, N, K;
vector<pair<ll, ll>> I;

int main()
{
    cin >> T;
    rep(tt, T)
    {
        cout << "Case #" << tt + 1 << ": ";

        cin >> N >> K;

        I.resize(N);  
        rep(i, N) { cin >> I[i].ff >> I[i].ss; }

        sort(I.begin(), I.end());

        ll ans = 0, l = LLONG_MIN;
        for (auto &e : I)
        {
            if (e.ss <= l) continue;
            ll s = max(e.ff, l);
            ll c = (e.ss - s - 1ll) / K + 1ll;
            ans += c, l = s + c * K;
        }

        cout << ans << '\n';
    }
}