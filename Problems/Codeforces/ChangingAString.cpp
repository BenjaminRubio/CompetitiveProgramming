#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++) 

string s, t;
int n, m;
int DP[1010][1010];

int dp(int i, int j)
{
    if (i == n or j == m) return DP[i][j] = n - i + m - j;

    if (DP[i][j] != -1) return DP[i][j];

    int ans = dp(i + 1, j + 1) + 1;            // replace
    if (s[i] == t[j]) ans = dp(i + 1, j + 1);  // advance
    ans = min(ans, dp(i, j + 1) + 1);          // insert
    ans = min(ans, dp(i + 1, j) + 1);          // erase

    return DP[i][j] = ans;
}

void print(int i, int j, int d)
{
    if (i == n and j == m) return;
    if (DP[i][j] == 0) return;

    if (s[i] == t[j] and DP[i][j] == DP[i + 1][j + 1]) print(i + 1, j + 1, d);
    else if (DP[i][j] == DP[i + 1][j + 1] + 1)
    {
        cout << "REPLACE " << i + d + 1 << ' ' << t[j] << '\n';
        print(i + 1, j + 1, d);
    }
    else if (DP[i][j] == DP[i][j + 1] + 1)
    {
        cout << "INSERT " << i + d + 1 << ' ' << t[j] << '\n';
        print(i, j + 1, d + 1);
    }
    else if (DP[i][j] == DP[i + 1][j] + 1)
    {
        cout << "DELETE " << i + d + 1 << '\n';
        print(i + 1, j, d - 1);
    }
}

int main()
{
    cin >> s >> t;
    n = s.size(), m = t.size();

    memset(DP, -1, sizeof DP);
    
    cout << dp(0, 0) << '\n';
    print(0, 0, 0);
}