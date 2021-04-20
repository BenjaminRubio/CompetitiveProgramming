#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

const ll MOD = 1e9 + 7;

inline ll add(ll a, ll b) { return (a + b) % MOD; }
inline ll mul(ll a, ll b) { return (a * b) % MOD; }

ll T, N, K;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> K;

        ll ans = 1;
        rep(i, K) ans = mul(ans, N);

        cout << ans << '\n';
    }
}