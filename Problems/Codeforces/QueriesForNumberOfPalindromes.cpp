#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, Q, l, r;
string S;
vector<vector<int>> P, DP;

int dp(int i, int j)
{
    if (j - i <= 1) return P[i][j] + (j - i == 1) * 2;
    if (DP[i][j] != -1) return DP[i][j];
    return DP[i][j] = dp(i + 1, j) + dp(i, j - 1) - dp(i + 1, j - 1) + P[i][j];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> S; N = S.size();

    P.assign(N, vector<int>(N, 0));
    rep(k, N) rep(i, N) if (i + k < N)
    {
        if (k == 0) P[i][i] = 1;
        if (k == 1) P[i][i + k] = (S[i] == S[i + k]);
        if (k >= 2) P[i][i + k] = (P[i + 1][i + k - 1] && S[i] == S[i + k]);
    }

    cin >> Q;
    DP.assign(N, vector<int>(N, -1));
    while (Q--)
    {
        cin >> l >> r; l--, r--;
        cout << dp(l, r) << '\n';
    }
}