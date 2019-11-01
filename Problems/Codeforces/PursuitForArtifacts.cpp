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

#define lg(x) (31 - __builtin_clz(x))
#define lgg(x) (63 - __builtin_clzll(x))
#define gcd __gcd

//ios::sync_with_stdio(0); cin.tie(0);
//cout.setf(ios::fixed); cout.precision(4);

#define debugx(x) // cerr << #x << ": " << x << endl
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
#define debugmp(m) //                                                                       \
    cerr << #m << endl;                                                                         \
    rep(i, (int)m.size())                                                                       \
    {                                                                                           \
        cerr << i << ":";                                                                       \
        rep(j, (int)m[i].size()) cerr << " {" << m[i][j].first << "," << m[i][j].second << "}"; \
        cerr << endl;                                                                           \
    }
#define print(x) copy(x.begin(), x.end(), ostream_iterator<int>(cout, “”)), cout << endl

struct UnionFind
{
    vector<int> p, rank, setSize;
    int numSets;
    UnionFind(int n)
    {
        numSets = n;
        setSize.assign(n, 1);
        rank.assign(n, 0);
        p.resize(n);
        rep(i, n) p[i] = i;
    }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            numSets--;
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y])
            {
                p[y] = x;
                setSize[x] += setSize[y];
            }
            else
            {
                p[x] = y;
                setSize[y] += setSize[x];
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

vi depth;
vi low;
vi parent_new;
graph g, g_aux, g_new;
stack<par> edge_stack;

void print_and_remove_bicomp(int u, int v, UnionFind &uf)
{
    par uv(u, v);
    vp aux;
    while (true)
    {
        par top = edge_stack.top();
        edge_stack.pop();
        aux.pb(top);
        // printf("(%d, %d)\n", top.first, top.second);
        if (top == uv)
            break;
    }
    if (aux.size() > 1)
        rep(i, aux.size()) uf.unionSet(aux[i].first, aux[i].second);
}

void dfs(int u, int p, int d, UnionFind &uf)
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
            dfs(v, u, d + 1, uf);
            if (p == -1)
                print_and_remove_bicomp(u, v, uf);
            else if (low[v] >= d)
                print_and_remove_bicomp(u, v, uf);
            if (low[v] > depth[u])
            {
                g_aux[u].pb(v);
                g_aux[v].pb(u);
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

void dfs_normal(int root, int n)
{
    stack<int> s;
    s.push(root);
    vector<bool> visited(n, false);
    visited[root] = true;
    while (!s.empty())
    {
        int u = s.top();
        s.pop();
        for (int v : g_new[u])
        {
            if (!visited[v])
            {
                parent_new[v] = u;
                visited[u] = true;
                s.push(v);
            }
        }
    }
}

int n, m, x, y, z, s, t;
map<par, int> edges, edges_new;
vi mapping, nodes;

int main()
{
    cin >> n >> m;
    depth.assign(n, -1);
    low.resize(n);
    g.resize(n);
    g_aux.resize(n);
    mapping.assign(n, -1);

    rep(i, m)
    {
        cin >> x >> y >> z;
        g[x - 1].pb(y - 1);
        g[y - 1].pb(x - 1);
        edges[{x - 1, y - 1}] = z;
        edges[{y - 1, x - 1}] = z;
    }

    cin >> s >> t;

    UnionFind uf(n);

    dfs(0, -1, 0, uf);

    // rep(i, n)
    //         cerr
    //     << uf.findSet(i) << '\n';

    int s_ = 0;
    rep(i, n)
    {
        int group = uf.findSet(i);
        if (mapping[group] == -1)
            mapping[group] = s_++;
    }
    g_new.assign(s_, {});
    parent_new.assign(s_, -1);
    nodes.assign(s_, 0);

    rep(i, n) for (auto j : g_aux[i]) g_new[mapping[uf.findSet(i)]].pb(mapping[uf.findSet(j)]);

    dfs_normal(mapping[uf.findSet(s - 1)], s_);

    rep(i, n) for (auto j : g_aux[i])
    {
        edges_new[{mapping[uf.findSet(i)], mapping[uf.findSet(j)]}] = edges[{i, j}];
        edges_new[{mapping[uf.findSet(j)], mapping[uf.findSet(i)]}] = edges[{i, j}];
        // cerr << mapping[uf.findSet(i)] << ' ' << mapping[uf.findSet(j)] << ' ' << edges[{i, j}] << '\n';
    }

    rep(i, n) for (auto j : g[i])
        if (uf.findSet(i) == uf.findSet(j) && edges[{i, j}])
            nodes[mapping[uf.findSet(i)]] = 1;

    int current = mapping[uf.findSet(t - 1)];
    while (parent_new[current] != -1)
    {
        // cerr << current << '\n';
        if (edges_new[{parent_new[current], current}])
        {
            cout << "YES\n";
            return 0;
        }
        if (nodes[current])
        {
            cout << "YES\n";
            return 0;
        }
        current = parent_new[current];
    }
    if (nodes[current])
    {
        cout << "YES\n";
        return 0;
    }

    cout << "NO\n";
    return 0;
}