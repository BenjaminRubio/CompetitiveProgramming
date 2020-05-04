#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef pair<int, int> ii;
typedef long long ll;

const int MAXN = 1e5 + 1;
int N, M, u, v;
vector<vector<int>> g;
vector<vector<int>> G;
vector<int> maps;
int sz[MAXN];
int id;

struct tarjanSCC {
    vector<int> _stack, ids, low;
    vector<bool> instack;
    vector<vector<int>>* g;
    int n, ID;
    void dfs(int u) {
        ids[u] = low[u] = ID++;
        instack[u] = true;
        _stack.push_back(u);
        for (int v : (*g)[u]) {
            if (ids[v] == -1) {
                dfs(v);
                low[u] = min(low[v], low[u]);
            } else if (instack[v]) {
                low[u] = min(low[v], low[u]);
            }
        }
        if (low[u] == ids[u]) {
            int k = 0;
            while (1) {
                k++;
                int x = _stack.back(); _stack.pop_back();
                maps[x] = id;
                instack[x] = false;
                if (x == u) break;
            }

            sz[id] = k;
            id++;
        }
    }
    tarjanSCC(vector<vector<int>>& _g) {
        g = &_g;
        n = _g.size();
        _stack.reserve(n);
        ids.assign(n, -1);
        low.resize(n);
        instack.assign(n, 0);
        ID = 0;
        rep(u, n) if (ids[u] == -1) dfs(u);
    }
};

bool vis[MAXN];
vector<int> sorted;
void dfs2(int u)
{
    vis[u] = true;
    for (int v : G[u]) if (!vis[v]) dfs2(v);
    sorted.push_back(u);
}

void topo_sort()
{  
    memset(vis, false, sizeof(bool) * id);
    sorted.clear(); 
    rep(i, id) if (!vis[i]) dfs2(i);
}

int main()
{
    cin >> N >> M;

    g.assign(N, {});
    rep(i, M)
    {
        cin >> u >> v;
        g[u].push_back(v);
    }

    id = 0;
    maps.resize(N);
    tarjanSCC tarj(g);

    G.assign(id, {});
    rep(u, N) for (int v : g[u]) if (maps[u] != maps[v]) G[maps[u]].push_back(maps[v]);

    topo_sort();

    ll ans = 0, prev = 0;
    for (int i : sorted)
    {
        ans += prev * sz[i] - G[i].size();
        prev += sz[i];
    }

    cout << ans << '\n';
}