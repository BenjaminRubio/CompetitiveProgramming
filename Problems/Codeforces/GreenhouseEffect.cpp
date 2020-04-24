#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n, m;
string aux;
vector<int> t;
int DP[5010][5010];

int dp(int i, int l)
{
    if (i == n) return 0;

    if (DP[i][l] != -1) return DP[i][l];

    int ans = dp(i + 1, l) + 1;
    if (t[i] >= l) ans = min(ans, dp(i + 1, t[i]));

    return DP[i][l] = ans;
}

int main()
{
    cin >> n >> m;
    
    t.resize(n);
    rep(i, n) cin >> t[i] >> aux;

    memset(DP, -1, sizeof DP);
    cout << dp(0, 0) << '\n';
}