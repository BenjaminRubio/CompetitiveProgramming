#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

const ll MOD = 1e9 + 7;

ll T, N, P;
vector<ll> k;

ll binexp(ll b, ll p)
{
    b %= MOD;
    ll ans = 1ll;
    while (p > 0)
    {
        if (p % 2ll) ans = (ans * b) % MOD;
        b = (b * b) % MOD;
        p /= 2ll;
    }
    return ans;
}

ll logP(ll x)
{
    ll ans = 1;
    while (x) { x /= P; ans++; }
    return ans;
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> P;

        k.resize(N);
        rep(i, N) cin >> k[i];

        if (P == 1) { cout << bool(N % 2) << '\n'; continue; }

        sort(k.begin(), k.end(), greater<ll>());
        k.push_back(0);

        ll d = 0;
        rep(i, N + 1)
        {
            if (i) d = (d * binexp(P, k[i - 1ll] - k[i])) % MOD;
            if (i == N) break;
            
            if (d > 0) d = ((d + (MOD - 1ll)) % MOD + MOD) % MOD;
            else d = (d + 1ll) % MOD;
        }

        cout << (d % MOD + MOD) % MOD << '\n';
    }
}