#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

ll T, N;
vector<ll> H, C;

ll cost(ll h)
{
    ll ans = 0;
    rep(i, N) ans += abs(H[i] - h) * C[i];
    return ans;
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        H.resize(N), C.resize(N);
        rep(i, N) cin >> H[i];
        rep(i, N) cin >> C[i];

        ll l = 0, r = 10000;
        while (l < r)
        {
            int m = (l + r) / 2;

            if (cost(m) <= cost(m + 1)) r = m;
            else l = m + 1;
        }

        cout << cost(l) << '\n';
    }
}