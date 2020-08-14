#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, M;
vector<int> a, b;

int DP[200][512];

int dp(int i, int o)
{
    if (i == N) return 0;
    if (DP[i][o] != -1) return DP[i][o];

    int ans = 1e9;
    rep(j, M) ans = min(ans, o | (a[i] & b[j]) | dp(i + 1, o | (a[i] & b[j])));
    return DP[i][o] = ans;
}

int main()
{
    cin >> N >> M;

    a.resize(N);
    rep(i, N) cin >> a[i];

    b.resize(M);
    rep(i, M) cin >> b[i];

    memset(DP, -1, sizeof DP);

    cout << dp(0, 0) << '\n';
}