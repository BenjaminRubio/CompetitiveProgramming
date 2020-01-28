#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

const int MAXN = 100010;
int depth[MAXN];
int low[MAXN];
vector<int> g[MAXN];
stack<pair<int, int>> edge_stack;
set<int> s;

void remove_bicomp(int u, int v)
{
    pair<int, int> uv(u, v);
    while (true)
    {
        pair<int, int> top = edge_stack.top();
        edge_stack.pop();
        if (top == uv)
            break;
    }
}

void dfs(int u, int p, int d)
{
    static int num_root_children = 0;
    depth[u] = d;
    low[u] = d;
    for (int v : g[u])
    {
        if (v == p)
            continue;
        if (depth[v] == -1)
        {
            edge_stack.emplace(u, v);
            dfs(v, u, d + 1);
            if (p == -1)
            {
                if (++num_root_children == 2)
                    s.insert(u);
                remove_bicomp(u, v);
            }
            else if (low[v] >= d)
            {
                s.insert(u);
                remove_bicomp(u, v);
            }
            low[u] = min(low[u], low[v]);
        }
        else if (depth[v] < d)
        {
            edge_stack.emplace(u, v);
            low[u] = min(low[u], depth[v]);
        }
    }
}

int n, m, b, u, v;
vector<bool> is_base;
vector<int> bases, critical;

int main()
{
    cin >> n >> m >> b;

    rep(i, m)
    {
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }

    is_base.assign(n + 1, false);
    rep(i, b)
    {
        cin >> u;
        is_base[u - 1] = true;
        g[u - 1].push_back(n);
        g[n].push_back(u - 1);
    }
    is_base[n] = true;

    memset(depth, -1, sizeof depth);

    dfs(n, -1, 0);

    for (int v : s) if (!is_base[v])
        critical.push_back(v);

    cout << critical.size() << '\n';
    rep(i, critical.size())
    {
        if (i) cout << ' ';
        cout << critical[i] + 1;
    }
    cout << '\n';
}