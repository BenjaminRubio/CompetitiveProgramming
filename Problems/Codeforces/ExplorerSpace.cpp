#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, M, K;
int D[510][510], R[510][510];
int DP[510][510][25];

int dp(int i, int j, int k)
{
    if (k == 0) return 0;

    if (DP[i][j][k] != -1) return DP[i][j][k];
    
    int ans = 1e9;
    if (i > 0) ans = min(ans, dp(i - 1, j, k - 1) + D[i - 1][j]);
    if (j > 0) ans = min(ans, dp(i, j - 1, k - 1) + R[i][j - 1]);
    if (i < N - 1) ans = min(ans, dp(i + 1, j, k - 1) + D[i][j]);
    if (j < M - 1) ans = min(ans, dp(i, j + 1, k - 1) + R[i][j]);

    return DP[i][j][k] = ans;
}

int main()
{
    cin >> N >> M >> K;

    if (K & 1)
    {
        rep(i, N)
        {
            rep(j, M) cout << -1 << ' ';
            cout << '\n';
        }
        return 0;
    }

    memset(R, 0, sizeof R);
    memset(D, 0, sizeof D);
    rep(i, N) rep(j, M - 1) cin >> R[i][j];
    rep(i, N - 1) rep(j, M) cin >> D[i][j];

    memset(DP, -1, sizeof DP);

    rep(i, N)
    {
        rep(j, M) cout << 2 * dp(i, j, K / 2) << ' ';
        cout << '\n';
    }
}