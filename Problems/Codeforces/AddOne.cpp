#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

const ll MOD = 1e9 + 7;

int T, M;
string S;

ll DP[10][200010];
ll dp(int d, int m)
{
    if (m == 0) return 1;
    if (DP[d][m] != -1) return DP[d][m];

    if (d < 9) return DP[d][m] = dp(d + 1, m - 1);
    return DP[d][m] = (dp(0, m - 1) + dp(1, m - 1)) % MOD;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    memset(DP, -1, sizeof DP);

    cin >> T;
    rep(t, T)
    {
        cin >> S >> M;
        
        ll ans = 0;
        for (char c : S) ans = (ans + dp(c - '0', M)) % MOD;

        cout << ans << '\n';
    }
}