#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, M;
string A, B;

int DP[6000][6000];

int dp(int i, int j)
{
    if (i >= N || j >= M) return 0;
    if (DP[i][j] != -1) return DP[i][j];

    int ans = 0;
    if (A[i] == B[j]) ans = max(ans, 2 + dp(i + 1, j + 1));
    ans = max(ans, dp(i, j + 1) - 1);
    ans = max(ans, dp(i + 1, j) - 1);
    ans = max(ans, dp(i + 1, j + 1) - 2);

    return DP[i][j] = ans;
}

int main()
{
    cin >> N >> M;
    cin >> A >> B;

    memset(DP, -1, sizeof DP);

    int ans = 0;
    rep(i, N) rep(j, M) ans = max(ans, dp(i, j));

    cout << ans << '\n';
}