#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

const ll MOD = 1e9 + 7;

ll N;

int main()
{
    cin >> N;

    ll ans = 1ll;
    rep(i, N) ans = (ans * (i + 1ll)) % MOD;

    ll res = 1;
    rep(i, N - 1) res = (res * 2ll) % MOD;

    cout << ((ans - res) % MOD + MOD) % MOD << '\n';
}