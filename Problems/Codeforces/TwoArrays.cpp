#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

const long long MOD = 1e9 + 7;
int n, m;
long long DP[11][1001];

long long dp(int ind, int d)
{
    if (DP[ind][d] != -1)
        return DP[ind][d];

    if (ind == m)
        return 1;

    long long ans = 0;
    rep(i, d + 1) ans = (ans + (d - i + 1) * dp(ind + 1, i)) % MOD;

    return DP[ind][d] = ans;
}

int main()
{
    cin >> n >> m;

    memset(DP, -1, sizeof DP);

    cout << dp(0, n - 1) << '\n';
}