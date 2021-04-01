#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, X, Y;
string S;

int DP[1010][20];
bool D[1010][20];

int dp(int i, int p)
{
    if (i == N) return 0;
    if (D[i][p]) return DP[i][p];

    int ans;
    if (S[i] != '?') ans = dp(i + 1, S[i]);
    if (S[i] == 'J' && p == 'C') ans += X;
    if (S[i] == 'C' && p == 'J') ans += Y;
    if (S[i] == '?') ans = min(dp(i + 1, 'J') + (p == 'C' ? X : 0), dp(i + 1, 'C') + (p == 'J' ? Y : 0));

    D[i][p] = 1;
    return DP[i][p] = ans;
}

int main()
{
    cin >> T;
    rep(t, T)
    {
        cout << "Case #" << t + 1 << ": ";

        cin >> X >> Y >> S; N = S.size();

        memset(D, 0, sizeof D);
        cout << dp(0, 0) << '\n';
    }
}