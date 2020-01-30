#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n, m;
vector<vector<int>> A, H, V, G;
int DP[201][201][201];

int dp(int l, int r, int h)
{
    if (l == m and r == m and h == n)
        return 0;

    if (DP[l][r][h] != -1e9)
        return DP[l][r][h];

    int ans = INT_MIN;
    if (r > l) ans = max(ans, dp(l + 1, r, h) - H[h][l]);
    if (r < m) ans = max(ans, dp(l, r + 1, h) - H[h][r]);
    if (h < n) ans = max(ans, dp(l, r, h + 1) - V[h][l] - V[h][r] + G[h][r] - G[h][l]);

    return DP[l][r][h] = ans;
}

int main()
{
    cin >> n >> m;

    A.assign(n, vector<int>(m, 0));
    rep(i, n) rep(j, m) cin >> A[i][j];

    H.assign(n + 1, vector<int>(m, 0));
    rep(i, n + 1) rep(j, m) cin >> H[i][j];

    V.assign(n, vector<int>(m + 1, 0));
    rep(j, m + 1) rep(i, n) cin >> V[i][j];

    G.assign(n, vector<int>(m + 1, 0));
    rep(i, n)
    {
        int s = 0;
        rep(j, m)
        {
            G[i][j] = s;
            s += A[i][j];
        }
        G[i][m] = s;
    }

    rep(i, 201) rep(j, 201) rep(k, 201) DP[i][j][k] = -1e9;

    cout << dp(0, 0, 0) << '\n';
}