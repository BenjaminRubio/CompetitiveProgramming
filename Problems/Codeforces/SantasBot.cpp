#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

const ll MOD = 998244353;

ll N, K, C[1000010];
vector<vector<ll>> A;

ll gcdext(ll a, ll b, ll& x, ll& y)
{
    ll r2, x2, y2, r1, x1, y1, r0, x0, y0, q;
    r2 = a, x2 = 1, y2 = 0;
    r1 = b, x1 = 0, y1 = 1;
    while (r1)
    {
        q = r2 / r1, r0 = r2 % r1;
        x0 = x2 - q * x1, y0 = y2 - q * y1;
        r2 = r1, x2 = x1, y2 = y1;
        r1 = r0, x1 = x0, y1 = y0;        
    }
    ll g = r2; x = x2, y = y2;
    if (g < 0) g = -g, x = -x, y = -y;
    return g;
}

ll mulinv(ll a)
{
    ll x, y;
    gcdext(a, MOD, x, y);
    return (x % MOD + MOD) % MOD;
}

int main()
{
    cin >> N;

    A.assign(N, {});
    rep(i, N)
    {
        cin >> K;
        A[i].resize(K);
        rep(j, K) { cin >> A[i][j]; C[A[i][j]]++; }
    }

    ll ans = 0;
    rep(i, N)
    {
        ll x = 0, y = 0;
        rep(j, A[i].size()) x += C[A[i][j]], y += N * N;
        ans = (ans + x * mulinv(y)) % MOD;
    }

    cout << ans << '\n';
}