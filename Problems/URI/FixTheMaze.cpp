#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N;
vector<vector<char>> b;
vector<vector<bool>> v;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool barrier(int i, int j, int k, int l, int r, int u, int d)
{
    if (k == 0 and (i + r) >= 0 and (i + r) < 2 * N - 1)
    {
        if (b[i + r][(r == 0) ? d : u] == 'H') return true;
    }
    else if (k == 0) return true;
    if (k == 1 and (i + l) >= 0 and (i + l) < 2 * N - 1)
    {
        if (b[i + l][(l == 0) ? d : u] == 'H') return true;
    }
    else if (k == 1) return true;
    if (k == 2 and d >= 0 and d < N)
    {
        if (b[i][d] == 'V') return true;
    }
    else if (k == 2) return true;
    if (k == 3 and u >= 0 and u < N)
    {
        if (b[i - 1][u] == 'V') return true;
    }
    else if (k == 3) return true;
    return false;
}

void dfs(int i, int j)
{
    v[i][j] = 1;

    int l, r, u, d;
    if (i % 2 == 1 and j % 2 == 1) u = j / 2, d = j / 2, l = -1, r = 0;
    if (i % 2 == 0 and j % 2 == 0) u = j / 2 - 1, d = j / 2, l = -1, r = 0;
    if (i % 2 == 1 and j % 2 == 0) u = j / 2, d = j / 2 - 1, l = 0, r = -1;
    if (i % 2 == 0 and j % 2 == 1) u = j / 2, d = j / 2, l = 0, r = -1;

    rep(k, 4)
    {
        int x = i + dx[k];
        int y = j + dy[k];

        if (x >= 0 and y >= 0 and x < 2 * N and y < 2 * N + 1 and !v[x][y])
            if (barrier(i, j, k, l, r, u, d)) dfs(x, y);
    }
}

int main()
{
    while (cin >> N)
    {
        b.assign(2 * N - 1, vector<char>(N, '.'));

        set<char> d;
        rep(i, 2 * N - 1) rep(j, N) { cin >> b[i][j]; d.insert(b[i][j]); }

        if (d.size() == 1 and N > 1)
        {
            if (b[0][0] == 'H') cout << 0 << '\n';
            else cout << N << '\n';
            continue;
        }

        int ans = 0;
        v.assign(2 * N, vector<bool>(2 * N + 1, 0));
        rep(i, 2 * N) rep(j, 2 * N + 1) if (!v[i][j]) { dfs(i, j); ans++; }

        cout << ans - 1 << '\n';
    }
}