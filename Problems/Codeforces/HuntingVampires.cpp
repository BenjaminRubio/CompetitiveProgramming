#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int H, W;
vector<vector<char>> m;
vector<vector<bool>> visited;

bool check(int i, int j)
{
    int x = i, y = j;
    int u = 0;
    while (x--)
    {
        if (m[x][y] != '*') break;
        if (y and m[x][y - 1] == '*') return false;
        if (y < W - 1 and m[x][y + 1] == '*') return false;
        visited[x][y] = true;
        u++;
    }

    x = i, y = j;
    int l = 0;
    while (y--)
    {
        if (m[x][y] != '*') break;
        if (x and m[x - 1][y] == '*') return false;
        if (x < H - 1 and m[x + 1][y] == '*') return false;
        l++;
    }

    x = i, y = j;
    int r = 0;
    while (++y < W)
    {
        if (m[x][y] != '*') break;
        if (x and m[x - 1][y] == '*') return false;
        if (x < H - 1 and m[x + 1][y] == '*') return false;
        r++;
    }

    x = i, y = j;
    int d = 0;
    while (++x < H)
    {
        if (m[x][y] != '*') break;
        if (y and m[x][y - 1] == '*') return false;
        if (y < W - 1 and m[x][y + 1] == '*') return false;
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