#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, M;
vector<int> C;

ll DP[51][251];

ll dp(int i, int c)
{
    if (c < 0) return 0;
    if (c == 0) return 1;
    if (i == M) return 0;

    if (DP[i][c] != -1) return DP[i][c];

    return DP[i][c] = dp(i, c - C[i]) + dp(i + 1, c);
}

int main()
{
    cin >> N >> M;

    C.resize(M);
    rep(i, M) cin >> C[i];

    memset(DP, -1, sizeof DP);
    cout << dp(0, N) << '\n';
}