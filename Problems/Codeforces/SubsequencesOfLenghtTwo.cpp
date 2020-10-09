#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, K; char a, b;
string S;

ll DP[210][210][210];

ll dp(int i, int c, int k)
{
    if (k < 0) return -1e9;
    if (i == N && k >= 0) return 0;
    if (DP[i][c][k] != -1) return DP[i][c][k];

    ll ans = -1e9;
    ans = max(ans, dp(i + 1, c + (S[i] == a), k) + ll(S[i] == b) * c);
    if (S[i] != a) ans = max(ans, dp(i + 1, c + 1, k - 1) + (a == b) * c);
    if (S[i] != b) ans = max(ans, dp(i + 1, c, k - 1) + c);

    return DP[i][c][k] = ans;
}

int main()
{
    cin >> N >> K >> S >> a >> b;

    memset(DP, -1, sizeof DP);

    cout << dp(0, 0, K) << '\n';
}