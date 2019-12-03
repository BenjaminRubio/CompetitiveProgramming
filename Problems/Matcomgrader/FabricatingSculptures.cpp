#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int s, b;
vector<vector<int>> DP;

int dp(int b, int s)
{
    if (b < 0 || s <= 0)
        return 0;
    if (b == 0 || s == 1)
        return 1;
    if (DP[b][s] != -1)
        return DP[b][s];
    int ans = dp(b - s, s);
    ans = (ans + dp(b, s - 1)) % MOD;
    ans = (ans + dp(b, s - 1)) % MOD;
    return DP[b][s] = ((ans - dp(b, s - 2)) % MOD + MOD) % MOD;
}

int main()
{
    cin >> s >> b;
    DP.assign(b + 1, vector<int>(s + 1, -1));

    cout << dp(b - s, s) << '\n';
}