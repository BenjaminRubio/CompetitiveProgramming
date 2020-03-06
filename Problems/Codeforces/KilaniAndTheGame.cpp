#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second
typedef pair<int, int> par;

int n, m, p;
vector<vector<char>> M;
vector<vector<vector<int>>> depth;
vector<int> s, ans;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs()
{
    ans.assign(p, 0);
    vector<queue<par>> q(p);
    depth.assign(n, vector<vector<int>>(m, vector<int>(p, -1)));
    rep(i, n) rep(j, m) if (M[i][j] != '.' && M[i][j] != '#')
    {
        q[M[i][j] - '1'].emplace(i, j);
        depth[i][j][M[i][j] - '1'] = 1;
    }

    int id = 0, t = 1;
    while (true)
    {
        int sz = 0;
        rep(i, p) sz += q[i].size();
        if (!sz) break;

        if (q[id].empty())
        {
            id = (id + 1) % p;
            if (!q[id].empty())
            {
                t = depth[q[id].front().ff][q[id].front().ss][id] - 1;
                if (t == 0) t = 1;
            }
            continue;
        }

        par c = q[id].front();
        int x = c.ff, y = c.ss;

        if (depth[x][y][id] - t == s[id] + 1)
        {
            id = (id + 1) % p;
            if (!q[id].empty())
            {
                t = depth[q[id].front().ff][q[id].front().ss][id] - 1;
                if (t == 0) t = 1;
            }
            continue;
        }

        q[id].pop();

        if (depth[x][y][id] != 1 and M[x][y] != '.') continue;

        M[x][y] = char(id + '1');
        ans[id]++;

        rep(k, 4) if (x + dx[k] >= 0 && x + dx[k] < n && 
                      y + dy[k] >= 0 && y + dy[k] < m &&
                      M[x + dx[k]][y + dy[k]] == '.' && 
                      depth[x + dx[k]][y + dy[k]][id] == -1)
        {
            depth[x + dx[k]][y + dy[k]][id] = depth[x][y][id] + 1;
            q[id].emplace(x + dx[k], y + dy[k]);
        }
    }
}

int main()
{
    cin >> n >> m >> p;

    s.resize(p);
    rep(i, p) cin >> s[i];

    M.assign(n, vector<char>(m));
    rep(i, n) rep(j, m) cin >> M[i][j];

    bfs();

    rep(i, p) cout << ans[i] << ' ';
    cout << '\n';
}