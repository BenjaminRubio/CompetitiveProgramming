#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

ll N, DP[510][510];

ll dp(int r, int h)
{
    if (r == 0) return 1;
    if (r <= h) return 0;
    if (DP[r][h] != -1) return DP[r][h];

    ll ans = 0;
    for (ll x = h + 1; x <= r; x++) ans += dp(r - x, x);

    return DP[r][h] = ans;
}

int main()
{
    cin >> N;

    memset(DP, -1, sizeof DP);
    cout << dp(N, 0) - 1 << '\n';
}