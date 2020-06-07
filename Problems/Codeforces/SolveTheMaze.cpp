#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int T, n, m;
vector<vector<int>> M;
vector<vector<bool>> V;
char ch;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y)
{
    V[x][y] = 1;
    rep(k, 4)
    {
        int x_ = x + dx[k], y_ = y + dy[k];
        if (x_ >= 0 && x_ < n && y_ >= 0 && y_ < m && M[x_][y_] > 0)
        {
            if (!V[x_][y_]) dfs(x_, y_);
        }
    }
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> m;

        M.assign(n, vector<int>(m, 0));
        vector<pair<int, int>> G, B;
        rep(i, n) rep(j, m)
        {
            cin >> ch;
            if (ch == 'G') M[i][j] = 2;
            if (ch == '.') M[i][j] = 1;
            if (ch == 'G') G.emplace_back(i, j);
            if (ch == 'B') B.emplace_back(i, j);
        }

        bool pos = true;
        for (auto e : B)
        {
            int x = e.ff, y = e.ss;
            rep(k, 4)
            {
                int x_ = x + dx[k], y_ = y + dy[k];
                if (x_ >= 0 && x_ < n && y_ >= 0 && y_ < m)
                {
                    if (M[x_][y_] == 1) M[x_][y_] = 0;
                    if (M[x_][y_] == 2) pos = false;
                }
            }
        }

        V.assign(n, vector<bool>(m, false));
        if (M[n - 1][m - 1] > 0) dfs(n - 1, m - 1);

        for (auto e : G) if (!V[e.ff][e.ss]) pos = false;

        if (pos) cout << "Yes\n";
        else cout << "No\n";
    }
}