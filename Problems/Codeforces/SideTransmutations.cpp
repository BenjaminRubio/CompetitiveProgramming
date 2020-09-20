#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

const ll MOD = 998244353;

ll bin_exp(ll b, ll p)
{
    b %= MOD; ll ans = 1;
    while (p)
    {
        if (p & 1ll) ans = (ans * b) % MOD;
        b = (b * b) % MOD, p >>= 1ll;
    }
    return ans;
}

ll N, M, A;
vector<ll> B;

int main()
{
    cin >> N >> M >> A;

    B.resize(M);
    rep(i, M) cin >> B[i];
    reverse(B.begin(), B.end()); B.push_back(0);
    
    ll ans = bin_exp(A, N - B[0] * 2);
    rep(i, M + 1) if (i)
    {
        ll w = bin_exp(A, B[i - 1] - B[i]);
        w = (w + w * (w - 1ll) / 2ll) % MOD;
        ans = (ans * w) % MOD;
    }

    cout << ans << '\n';
}