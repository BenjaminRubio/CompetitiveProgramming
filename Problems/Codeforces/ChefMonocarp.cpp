#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int Q, N;
vector<int> T;

int DP[210][510];

int dp(int i, int j)
{
    if (j == 401) return 1e6;
    if (i == N) return 0;
    if (DP[i][j] != -1) return DP[i][j];

    int ans = INT_MAX;
    ans = min(ans, dp(i + 1, j + 1) + abs(T[i] - j));
    ans = min(ans, dp(i, j + 1));

    return DP[i][j] = ans;
}

int main()
{
    cin >> Q;
    while (Q--)
    {
        cin >> N;

        T.resize(N);
        rep(i, N) cin >> T[i];

        sort(T.begin(), T.end());

        memset(DP, -1, sizeof DP);

        cout << dp(0, 1) << '\n';
    }
}