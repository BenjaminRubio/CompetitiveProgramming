#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> par;
typedef vector<int> vi;
typedef vector<float> vfloat;
typedef vector<par> vp;
typedef vector<vi> graph;
typedef vector<vp> wgraph;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define invrep(i, b, a) for (int i = b; i >= a; --i)

#define pb push_back
#define pf push_front
#define eb emplace_back
#define ppb pop_back

#define umap unordered_map

#define lg(x) (31 - __buitlin_clz(x))
#define lgg(x) (63 - __buitlin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x) cerr << #x << ": " << x << endl
#define debugv(v)         \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
    cerr << endl
#define debugm(m)                                        \
    cerr << #m << endl;                                  \
    rep(i, (int)m.size())                                \
    {                                                    \
        cerr << i << ":";                                \
        rep(j, (int)m[i].size()) cerr << " " << m[i][j]; \
        cerr << endl;                                    \
    }
#define debugmp(m) //\
    cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

int n, c, k, x;
graph counts;
graph members;
graph g, g_;
vi parity;
vector<bool> visited;

vi depth;
vi low;
stack<par> edge_stack;

set<par> cut_edges;
set<par> not_cut;

void print_and_remove_bicomp(int u, int v)
{
    par uv(u, v);
    while (true)
    {
        par top = edge_stack.top();
        edge_stack.pop();
        if (top == uv)
            break;
    }
}

void dfs_ap(int u, int p, int d)
{
    static int num_root_children = 0;
    depth[u] = d;
    low[u] = d;
    for (int v : g_[u])
    {
        if (v == p)
            continue;
        if (depth[v] == -1 || cut_edges.count({u, v}))
        {
            edge_stack.emplace(u, v);
            dfs_ap(v, u, d + 1);
            if (p == -1)
                print_and_remove_bicomp(u, v);
            else if (low[v] >= d)
                print_and_remove_bicomp(u, v);
            if (low[v] > depth[u])
            {
                if (cut_edges.count({u, v}) > 0)
                {
                    cut_edges.erase({u, v});
                    cut_edges.erase({v, u});
                    not_cut.insert({u, v});
                    not_cut.insert({v, u});
                }
                else if (not_cut.count({u, v}) == 0)
                {
                    cut_edges.insert({u, v});
                    cut_edges.insert({v, u});
                    // cerr << u << ' ' << v << '\n';
                }
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

void dfs(int root)
{
    stack<int> s;
    s.push(root);
    visited[root] = true;
    while (!s.empty())
    {
        int u = s.top();
        s.pop();
        visited[u] = true;
        for (int v : g_[u])
        {
            if (!visited[v])
            {
                s.push(v);
            }
        }
    }
}

int count_cc()
{
    int count = 0;
    visited.assign(c, 0);
    rep(i, c)
    {
        if (!visited[i] && members[i].size() > 0)
        {
            count++, dfs(i);
        }
    }
    return count;
}

int main()
{
    while (cin >> n >> c)
    {
        if (n == 0 && c == 0)
            break;

        counts.assign(n, vi());
        members.assign(c, vi());
        g.assign(c, vi());
        g_.assign(c, vi());
        parity.assign(c, 0);
        depth.assign(c, -1);
        low.assign(c, -1);

        rep(i, c)
        {
            cin >> k;
            rep(j, k)
            {
                cin >> x;
                members[i].pb(x);
                counts[x].pb(i);
                if (counts[x].size() == 2)
                {
                    g[counts[x][0]].pb(i);
                    parity[i]++;
                    parity[counts[x][0]]++;
                    g_[counts[x][0]].pb(i);
                    g_[i].pb(counts[x][0]);
                }
            }
        }

        // debugm(g);

        dfs_ap(c - 1, -1, 0);

        if (count_cc() > 1)
        {
            cout << -1 << '\n';
            continue;
        }

        int impares = 0;
        vi colores_impares;
        rep(i, c)
        {
            if (parity[i] % 2 == 1)
            {
                impares++;
                colores_impares.pb(i);
            }
        }

        if (impares == 0)
        {
            cout << 0 << '\n';
        }
        else if (impares == 2)
        {
            int ans = 1e9;
            for (int node : members[colores_impares[0]])
            {
                if (members[colores_impares[0]].size() > 1 && counts[node].size() == 2)
                {
                    par edge = {counts[node][0], counts[node][1]};
                    if (cut_edges.count(edge) == 0)
                        ans = min(ans, node);
                }
                else
                    ans = min(ans, node);
                
            }

            for (int node : members[colores_impares[1]])
            {
                if (members[colores_impares[1]].size() > 1 && counts[node].size() == 2)
                {
                    par edge = {counts[node][0], counts[node][1]};
                    if (cut_edges.count(edge) == 0)
                        ans = min(ans, node);
                }
                else
                    ans = min(ans, node);
                
            }

            cout << ans << '\n';
        }
        else
        {
            cout << -1 << '\n';
        }

        cut_edges.clear();
        not_cut.clear();
    }
}