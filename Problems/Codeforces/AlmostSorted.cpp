#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

inline ll mul(ll a) { if (a >= 1e18) return 2e18; return 2ll * a; }

ll T, N, K;

ll DP[100010];

ll dp(int n)
{
    if (n <= 1) return 1;
    if (DP[n] != -1) return DP[n];
    return DP[n] = mul(dp(n - 1));
}

int main()
{
    cin >> T;
    memset(DP, -1, sizeof DP);

    while (T--)
    {
        cin >> N >> K;

        if (K > dp(N)) { cout << -1 << '\n'; continue; }

        ll off = 0;
        while (off < N && K)
        {
            ll x = off + 1;
            while (x < N && K > dp(N - x)) K -= dp(N - x), x++;
            ll y = x;
            while (y > off) cout << y << ' ', y--;
            off  = x;
        }
        cout << '\n';
    }
}