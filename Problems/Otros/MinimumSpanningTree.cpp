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
#define debugv(v)  //       \
    cerr << #v << ":";    \
    for (auto e : v)      \
        cerr << " " << e; \
    cerr << endl
#define debugm(m)  //                                      \
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

// MST apuntes Pablo Messina

struct Edge
{
    int u, v, cost;
    bool operator<(const Edge &o) const
    {
        return cost < o.cost;
    }
};

struct UnionFind
{
    vector<int> p, rank;
    UnionFind(int n)
    {
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
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y])
            {
                p[y] = x;
            }
            else
            {
                p[x] = y;
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
};

ll find_mst(int n_nodes, vector<Edge> &edges, wgraph &mst)
{
    sort(edges.begin(), edges.end());
    UnionFind uf(n_nodes);
    mst.assign(n_nodes, vector<par>());
    ll mstcost = 0;
    int count = 1;
    for (auto &e : edges)
    {
        int u = e.u, v = e.v, cost = e.cost;
        if (!uf.isSameSet(u, v))
        {
            mstcost += cost;
            uf.unionSet(u, v);
            mst[u].emplace_back(v, cost);
            mst[v].emplace_back(u, cost);
            if (++count == n_nodes)
                break;
        }
    }
    return mstcost;
}

int n, m, a, b, w;
vector<Edge> v;
wgraph g;

int main()
{
    cin >> n >> m;

    rep(i, m)
    {
        cin >> a >> b >> w;
        v.pb({a - 1, b - 1, w});
    }

    cout << find_mst(n, v, g) << '\n';
}