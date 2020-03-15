#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep_(i, n) for (int i = (int)n - 1; i >= 0; i--)

int n, u, v;
vector<vector<int>> g;
vector<int> ans;
map<pair<int, int>, int> edges;

int main()
{
    cin >> n;

    g.assign(n, {});
    ans.assign(n - 1, -1);
    rep(i, n - 1)
    {
        cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
        edges[{u, v}] = i;
        edges[{v, u}] = i;
    }

    bool done = false;
    rep(i, n)
    {
        if (g[i].size() >= 3)
        {
            ans[edges[{i, g[i][0]}]] = 0;
            ans[edges[{i, g[i][1]}]] = 1;
            ans[edges[{i, g[i][2]}]] = 2;
            done = true;
            break;
        }
    }

    int aux = 3;
    if (!done) aux = 0;
    rep(i, n - 1) if (ans[i] == -1) ans[i] = aux++;

    rep(i, n - 1) cout << ans[i] << '\n';
}