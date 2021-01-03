#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

const ll MOD = 1e9 + 7;

inline ll add(ll x, ll y) { return (x + y) % MOD; }
inline ll mul(ll x, ll y) { return (x * y) % MOD; }

ll T, N;
vector<ll> X, B;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> N;

        X.resize(N); ll s = 0;
        rep(i, N) { cin >> X[i]; s = add(s, X[i]); }

        B.assign(60, 0);
        rep(i, N) rep(j, 60) if (X[i] & (1ll << j)) B[j]++;

        ll ans = 0;
        rep(i, N)
        {
            ll ss = 0;
            rep(j, 60) if (X[i] & (1ll << j)) ss = add(ss, mul((1ll << j) % MOD, B[j]));
            ans = add(ans, mul(N, mul(X[i] % MOD, ss)));
            ans = add(ans, mul(s, ss));
            ans = add(ans, mul(-1, mul(ss, ss)));
        }

        cout << add(ans, MOD) << '\n';
    }
}