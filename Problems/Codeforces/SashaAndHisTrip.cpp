#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, V;
int DP[110][110];

int dp(int i, int f)
{
    if (DP[i][f] != -1)
        return DP[i][f];

    if (i == N - 1)
        return 0;

    int ans = INT_MAX;
    for (int j = 0; j <= V - f; j++)
        if (f + j > 0)
            ans = min(ans, j * (i + 1) + dp(i + 1, f + j - 1));
    return DP[i][f] = ans;
}

int main()
{
    cin >> N >> V;

    memset(DP, -1, sizeof DP);

    cout << dp(0, 0) << '\n';
}