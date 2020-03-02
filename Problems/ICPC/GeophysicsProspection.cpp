#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int p, k, m;
vector<vector<vector<char>>> M;
vector<vector<vector<bool>>> v;
map<char, priority_queue<int>> ans;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int dfs(int x, int y, int z)
{
    v[x][y][z] = true;

    int ans = 0;
    rep(t, 6)
    {
        int x_ = x + dx[t], y_ = y + dy[t], z_ = z + dz[t];
        if (x_ >= 0 and x_ < m and y_ >= 0 and y_ < p and z_ >= 0 and z < k)
        {
            if (!v[x_][y_][z_] and M[x][y][z] == M[x_][y_][z_])
                ans += dfs(x_, y_, z_);
        }
    }

    return ans + 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T = 0;
    while (cin >> p >> k >> m)
    {
        M.assign(m, vector<vector<char>>(p, vector<char>(k)));
        rep(x, m) rep(y, p) rep(z, k) cin >> M[x][y][z];

        v.assign(m, vector<vector<bool>>(p, vector<bool>(k, false)));
        ans['a'] = {}; ans['b'] = {}; ans['c'] = {}; ans['d'] = {};
        rep(x, m) rep(y, p) rep(z, k) if (!v[x][y][z] and M[x][y][z] != '*')
            ans[M[x][y][z]].push(dfs(x, y, z));

        if (T++) cout << '\n';
        cout << "Case " << T << ":\n";
        for (auto e : ans)
        {
            cout << e.ff << ' ';
            if (e.ss.empty()) cout << 0;
            else while (!e.ss.empty())
            {
                cout << e.ss.top() << ' ';
                e.ss.pop();
            }
            cout << '\n';
        }
    }
}