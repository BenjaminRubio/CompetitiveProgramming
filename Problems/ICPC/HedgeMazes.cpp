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
#define invrep(i, a, b) for (int i = b; i-- > (int)a;)

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
            // rank is used to keep the tree short
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

int r, c, q, a, b;
vi depth, low;
graph g;
stack<par> edge_stack;
vector<par> cut_edges;

void dfs(int u, int p, int d) {
    depth[u] = d;
    low[u] = d;
    for(int v : g[u]) {
        if (v == p) continue;
        if (depth[v] == -1) {
            edge_stack.emplace(u,v);
            dfs(v, u, d + 1);
            if (low[v] > depth[u]) {
                cut_edges.pb({u, v});
            }
            low[u] = min(low[u], low[v]);
        } else if (depth[v] < d) {
            edge_stack.emplace(u,v);
            low[u] = min(low[u], depth[v]);
        }
    }
}

int main()
{
    while (cin >> r >> c >> q)
    {
        if (r == 0 && c == 0 && q == 0)
            break;

        g.assign(r, vi());
        depth.assign(r, -1);
        low.assign(r, 0);

        rep(i, c)
        {
            cin >> a >> b;
            g[a - 1].pb(b - 1);
            g[b - 1].pb(a - 1);
        }

        dfs(0, -1, 0);
        UnionFind uf(r);

        for (auto e : cut_edges)
        {
            uf.unionSet(e.first, e.second);
        }

        rep(i, q)
        {
            cin >> a >> b;
            if (uf.isSameSet(a - 1, b - 1))
                cout << "Y\n";
            else
                cout << "N\n";
        }

        stack<par>().swap(edge_stack);
        cut_edges.clear();

        cout << "-\n";
    }
}
