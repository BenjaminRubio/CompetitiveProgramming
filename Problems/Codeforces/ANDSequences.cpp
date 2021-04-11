#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

const ll MOD = 1e9 + 7;

ll T, N;
vector<ll> A;

ll inv(ll x)
{
    ll ans = 1, b = x, p = MOD - 2;
    while (p)
    {
        if (p & 1ll) ans = (ans * b) % MOD;
        p >>= 1, b = (b * b) % MOD;
    }
    return ans;
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        A.resize(N); rep(i, N) cin >> A[i];

        ll acc = A[0];
        rep(i, N) acc &= A[i];

        ll c = 0;
        rep(i, N) if (A[i] == acc) c++;

        if (c > 1)
        {
            ll ans = 1;
            rep(i, c) ans = (ans * (i + 1ll)) % MOD;
            rep(i, c - 2) ans = (ans * inv(i + 1)) % MOD;
            rep(i, N - 2) ans = (ans * (i + 1ll)) % MOD;

            cout << ans << '\n';
        }
        else cout << 0 << '\n';
    }
}