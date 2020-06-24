#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

const int MOD = 1e9 + 7;

int T, N;
int DP[2000010];

int dp(int n)
{
    if (n < 0) return 0;

    if (DP[n] != -1) return DP[n];

    int ans = 4 * (n % 3 == 0);

    ans = (ans + 2 * dp(n - 2)) % MOD;
    ans = (ans + dp(n - 1)) % MOD;
    return DP[n] = ans;
}

int main()
{
    cin >> T;

    memset(DP, -1, sizeof DP);

    while (T--)
    {
        cin >> N;
        cout << dp(N - 3) << '\n';
    }
}