#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, x;
vector<int> p;
int DP[101][101][101][3];

int dp(int i, int o, int e, int l)
{
    if (i == N) return 0;

    if (DP[i][o][e][l] != -1) return DP[i][o][e][l];

    if (p[i] != -1)
        return DP[i][o][e][l] = dp(i + 1, o, e, p[i]) + (l != p[i] && l != 2);

    int ans = INT_MAX;
    if (o) ans = min(ans, dp(i + 1, o - 1, e, 1) + (l == 0));
    if (e) ans = min(ans, dp(i + 1, o, e - 1, 0) + (l == 1));

    return DP[i][o][e][l] = ans;
}

int main()
{
    memset(DP, -1, sizeof DP);

    cin >> N;

    int e = N / 2, o = N - e;
    p.assign(N, -1);
    rep(i, N)
    {
        cin >> x;
        if (x) p[i] = x % 2;
        if (x && x % 2 == 0) e--;
        if (x && x % 2 == 1) o--;
    }

    cout << dp(0, o, e, 2) << '\n';
}