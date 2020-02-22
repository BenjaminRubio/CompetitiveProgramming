#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

struct UF
{
    int numSets;
    vector<int> p, rank, setSize;
    UF(int n)
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
        if (isSameSet(i, j)) return;
        numSets--;
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) p[y] = x, setSize[x] += setSize[y];
        else p[x] = y, setSize[y] += setSize[x];
        if (rank[x] == rank[y]) rank[y]++;
    }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int n, d;
vector<vector<char>> m;
vector<set<int>> g;
vector<bool> ispar;
vector<int> depth;
set<int> par;

bool toposort()
{
    vector<int> indegree(2 * n, 0);
    rep(u, 2 * n) if (ispar[u]) for (int v : g[u]) indegree[v]++;
    queue<pair<int, int>> q;
    int count = 0;
    rep(u, 2 * n) if (ispar[u]) if (indegree[u] == 0) q.push({u, 0});
    while (!q.empty())
    {
        int u = q.front().ff; depth[u] = d = q.front().ss; q.pop(); count++;
        for (int v : g[u]) if (--indegree[v] == 0) q.push({v, d + 1});
    }
    return count == par.size();
}

int main()
{
    int t = 0;
    while (cin >> n)
    {
        t++;
        if (n == -1 or !n) break;

        m.assign(n, vector<char>(n));
        rep(i, n) rep(j, n) cin >> m[i][j];

        UF uf(2 * n);
        rep(i, n) rep(j, n) if (m[i][j] == '0') uf.unionSet(i, n + j);
        g.assign(2 * n, {});
        rep(i, n) rep(j, n)
        {
            if (m[i][j] == '+') g[uf.findSet(n + j)].insert(uf.findSet(i));
            else if (m[i][j] == '-')
                g[uf.findSet(i)].insert(uf.findSet(n + j));
        }

        par.clear();
        ispar.assign(n, false);
        rep(i, 2 * n) ispar[uf.findSet(i)] = true, par.insert(uf.findSet(i));

        depth.assign(2 * n, 0);
        if (!toposort())
        {
            cout << "Case " << t << ": -1\n";
            continue;
        }

        int ans = INT_MAX;
        rep(i, d + 1)
        {
            int aux = 0;
            for (int j : par) aux += uf.sizeOfSet(j) * abs(depth[j] - i);
            ans = min(ans, aux);
        }

        cout <<  "Case " << t << ": " << ans << '\n';
    }
}