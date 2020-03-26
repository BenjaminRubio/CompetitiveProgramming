#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int m, n;
vector<vector<char>> M; // map
vector<vector<bool>> V; // visited
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

bool paint(int i, int j)
{
    if (i >= 0 and i < m and j >= 0 and j < n and M[i][j] == '-' and !V[i][j])
    {
        V[i][j] = true;
        rep(k, 4) paint(i + dx[k], j + dy[k]);
        return true;
    }
    return false;
}

int main()
{
    int T = 1;
    while (cin >> m >> n)
    {
        M.assign(m, vector<char>(n));
        V.assign(m, vector<bool>(n, false));
        rep(i, m) rep(j, n) cin >> M[i][j];

        int ans = 0;
        rep(i, m) rep(j, n) ans += paint(i, j);

        cout << "Case " << T++ << ": " << ans << '\n';
    }
}