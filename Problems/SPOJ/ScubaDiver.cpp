#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, o, n, c;
vector<int> O, N, W;
int DP[1001][22][80];

int dp(int i, int o, int n)
{
    if (i == c and (o > 0 or n > 0)) return 1e9;
    if (i == c) return 0;

    if (DP[i][o][n] != -1) return DP[i][o][n];

    int ans = min(dp(i + 1, o, n), 
                  dp(i + 1, max(o - O[i], 0), max(n - N[i], 0)) + W[i]);
    return DP[i][o][n] = ans;
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> o >> n >> c;

        O.resize(c); N.resize(c); W.resize(c);
        rep(i, c) cin >> O[i] >> N[i] >> W[i];

        memset(DP, -1, sizeof DP);
        cout << dp(0, o, n) << '\n';
    }
}