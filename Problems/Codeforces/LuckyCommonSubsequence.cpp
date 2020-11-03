#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, M, S, L[110], DP[110][110][110];
string A, B, V;

int dp(int i, int j, int k)
{
    if (i == N || j == M) return 0;

    if (DP[i][j][k] != -1) return DP[i][j][k];

    int ans = 0;
    if (A[i] == B[j])
    {
        int kk = k;
        while (V[kk] != A[i] && kk) kk = L[kk - 1];
        if (V[kk] != A[i] || ++kk < S) ans = max(ans, 1 + dp(i + 1, j + 1, kk));
    }
    ans = max(ans, dp(i + 1, j, k));
    ans = max(ans, dp(i, j + 1, k));

    return DP[i][j][k] = ans;
}

int main()
{
    cin >> A >> B >> V;

    N = A.size(), M = B.size(), S = V.size();

    L[0] = 0; rep(j, S - 1)
    {
        int i = L[j]; while (V[i] != V[j + 1] && i) i = L[i - 1];
        L[j + 1] = (V[i] == V[j + 1] ? i + 1 : 0);
    }

    memset(DP, -1, sizeof DP);

    if (!dp(0, 0, 0)) { cout << 0 << '\n'; return 0; }

    int i = 0, j = 0, k = 0;
    while (1)
    {
        if (i == N || j == M) break;
        int ans = dp(i, j, k);
        if (A[i] == B[j])
        {
            int kk = k;
            while (V[kk] != A[i] && kk) kk = L[kk - 1];
            if ((V[kk] != A[i] || ++kk < S) && (1 + dp(i + 1, j + 1, kk)) == ans)
            { cout << A[i]; i++, j++, k = kk; continue; }
        }
        if (dp(i + 1, j, k) == ans) { i++; continue; }
        if (dp(i, j + 1, k) == ans) { j++; continue; }
    }
    cout << '\n';
}