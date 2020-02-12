#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int H, W;
vector<vector<char>> m;
vector<vector<bool>> visited;

bool check(int i, int j)
{
    if (j == 0 or j == W - 1) return false;

    int x = i, y = j;
    if (x and m[x - 1][y] == '*') return false;

    int u = 0;
    bool pos = false;
    while (x < H)
    {
        if (m[x][y] != '*') return false;
        if (m[x][y - 1] == '*' and m[x][y + 1] == '*') { pos = true; break; }
        if (m[x][y - 1] == '*' or m[x][y + 1] == '*') return false;
        visited[x][y] = 1;
        u++;
        x++;
    }
    if (!pos or !u) return false;
    visited[x][y] = 1;

    x = i + u, y = j;
    int l = 0;
    while (y--)
    {
        if (m[x][y] != '*') break;
        if (x and m[x - 1][y] == '*') return false;
        if (x < H - 1 and m[x + 1][y] == '*') return false;
        visited[x][y] = 1;
        l++;
    }

    x = i + u, y = j;
    int r = 0;
    while (++y < W)
    {
        if (m[x][y] != '*') break;
        if (x and m[x - 1][y] == '*') return false;
        if (x < H - 1 and m[x + 1][y] == '*') return false;
        visited[x][y] = 1;
        r++;
    }

    x = i + u, y = j;
    int d = 0;
    while (++x < H)
    {
        if (m[x][y] != '*') break;
        if (y and m[x][y - 1] == '*') return false;
        if (y < W - 1 and m[x][y + 1] == '*') return false;
        visited[x][y] = 1;
        d++;
    }

    if (u == l and l == r and d > u) return true;
    return false;
}

int main()
{
    cin >> H >> W;

    m.assign(H, vector<char>(W, '.'));
    rep(i, H) rep(j, W) cin >> m[i][j];

    int ans = 0;
    visited.assign(H, vector<bool>(W, false));
    rep(i, H) rep(j, W) if (!visited[i][j] and m[i][j] == '*') ans += check(i, j);

    cout << ans << '\n';
}