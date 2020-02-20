#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef pair<int, int> ii;
typedef long long ll;

struct Edge
{
    int u, v, cost;
    bool operator<(const Edge &o) const { return cost < o.cost; }
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

ll find_mst(int n_nodes, vector<Edge> &edges)
{
    vector<vector<ii>> mst;
    sort(edges.begin(), edges.end());
    UnionFind uf(n_nodes);
    mst.assign(n_nodes, vector<ii>());
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

int N, M, u, v, c;
vector<Edge> e;

int main()
{
    cin >> N >> M;

    rep(i, M)
    {
        cin >> u >> v >> c;
        e.push_back({u - 1, v - 1, c});
    }

    cout << find_mst(N, e) << '\n';
}