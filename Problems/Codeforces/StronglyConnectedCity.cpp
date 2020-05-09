#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n, m;
int dx[21], dy[21];
bool v[21][21];
char aux;

int dfs(int i, int j)
{
    v[i][j] = 1;

    int ans = 0;
    if (i + dx[j] >= 0 && i + dx[j] < n && !v[i + dx[j]][j]) 
        ans += dfs(i + dx[j], j);
    if (j + dy[i] >= 0 && j + dy[i] < m && !v[i][j + dy[i]]) 
        ans += dfs(i, j + dy[i]);
    return ans + 1;
}

int main()
{
    cin >> n >> m;
    rep(i, n)
    {
        cin >> aux;
        if (aux == '>') dy[i] = 1;
        else dy[i] = -1;
    }
    rep(j, m)
    {
        cin >> aux;
        if (aux == 'v') dx[j] = 1;
        else dx[j] = -1;
    }

    bool ans = true;
    rep(i, n) rep(j, m)
    {
        memset(v, 0, sizeof v);
        if (dfs(i, j) != n * m) ans = false;
    }

    if (ans) cout << "YES\n";
    else cout << "NO\n";
}