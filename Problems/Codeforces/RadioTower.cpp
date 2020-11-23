#include <bits/stdc++.h>
using namespace std;
    
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
    
const ll MOD = 998244353;
    
ll N;
ll F[200010], P[200010];
    
ll inv(ll b)
{
    ll a = 1, p = MOD - 2; b %= MOD;
    while (p)
    {
        if (p & 1ll) a = (a * b) % MOD;
        b = (b * b) % MOD, p >>= 1ll;
    }
    return (a + MOD) % MOD;
}
    
int main()
{
    F[0] = 1, F[1] = 1;
    rep(i, 200000) F[i + 2] = (F[i] + F[i + 1]) % MOD;
    
    P[0] = 1;
    rep(i, 200000) P[i + 1] = (P[i] * 2) % MOD;
    
    cin >> N;
    
    cout << (F[N - 1] * inv(P[N])) % MOD << '\n';
}