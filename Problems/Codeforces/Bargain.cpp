#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

const ll MAXN = 1e5 + 1;
const ll MOD = 1e9 + 7;
string N;
ll S[MAXN], P[MAXN];

ll add(ll a, ll b) { return (a + b) % MOD; }
ll mul(ll a, ll b) { return (a * b) % MOD; }

int main()
{
    P[0] = 1, S[0] = 0;
    rep(i, MAXN - 1) P[i + 1] = (P[i] * 10) % MOD, S[i + 1] = (S[i] + P[i] * (i + 1ll)) % MOD; 

    cin >> N;
    reverse(N.begin(), N.end());
    ll T = N.size();

    ll ans = 0, s = 0;
    for (char c : N)
    {
        ll d = c - '0';
        ans = add(ans, mul(d, S[s]));
        ans = add(ans, mul(mul(d, P[s]), ((T - s - 1) * (T - s) / 2ll) % MOD));

        s++;
    }

    cout << (ans + MOD) % MOD << '\n';
}