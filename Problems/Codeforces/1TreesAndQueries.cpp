#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

struct LCA
{
    vector<int> E, D, H;    // E = euler tour, D = depth, H = first index of node in euler tour
    vector<int> DP;         // memo for range minimun query
    vector<vector<int>> *g; // pointer to graph
    int idx;                // tracks node ocurrences
    int n;                  // number of nodes

    int &rmq(int i, int e) { return DP[e * idx + i]; }
    inline int log2(int x) { return 31 - __builtin_clz(x); }

    void dfs(int u, int depth)
    {
        H[u] = idx;       // index of first u's ocurrence
        E[idx] = u;       // record node ocurrence
        D[idx++] = depth; // record depth
        for (int v : (*g)[u])
        {
            if (H[v] == -1)
            {
                dfs(v, depth + 1); // explore v's subtree and come back to u
                E[idx] = u;        // new ocurrence of u
                D[idx++] = depth;
            }
        }
    }

    LCA(vector<vector<int>> &_g, int root)
    {
        g = &_g;
        n = _g.size();
        H.assign(n, -1);
        E.resize(2 * n);
        D.resize(2 * n);
        idx = 0;
        dfs(root, 0); // euler tour
        int nn = idx; // <-- make sure you use the correct number
        int maxe = log2(nn);
        DP.resize(nn * (maxe + 1));
        // build sparse table with bottom-up DP
        rep(i, nn) rmq(i, 0) = i; // base case
        repx(e, 1, maxe + 1)
        { // general cases
            rep(i, (nn - (1 << e)) + 1)
            {
                // i ... i + 2 ^ (e-1) - 1
                int i1 = rmq(i, e - 1);
                // i + 2 ^ (e-1) ... i + 2 ^ e  - 1
                int i2 = rmq(i + (1 << (e - 1)), e - 1);
                // choose index with minimum depth
                rmq(i, e) = D[i1] < D[i2] ? i1 : i2;
            }
        }
    }

    int lca(int u, int v)
    {
        // get ocurrence indexes in increasing order
        int l = H[u], r = H[v];
        if (l > r)
            swap(l, r);
        // get node with minimum depth in range [l .. r] in O(1)
        int len = r - l + 1;
        int e = log2(len);
        int i1 = rmq(l, e);
        int i2 = rmq(r - ((1 << e) - 1), e);
        return D[i1] < D[i2] ? E[i1] : E[i2];
    }

    int dist(int u, int v)
    {
        // make sure you use H to retrieve the indexes of u and v
        // within the Euler Tour sequence before using D
        return D[H[u]] + D[H[v]] - 2 * D[H[lca(u, v)]];
    }
};

int n, u, v, q, x, y, a, b, k;
vector<vector<int>> g;

int main()
{
    cin >> n;

    g.resize(n);
    rep(i, n - 1)
    {
        cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    LCA lca(g, 0);

    cin >> q;
    rep(_, q)
    {
        cin >> x >> y >> a >> b >> k;
        x--; y--; a--; b--;

        int d1 = lca.dist(a, b);
        int dax = lca.dist(a, x), day = lca.dist(a, y), dbx = lca.dist(b, x), dby = lca.dist(b, y);
        int d2 = min(dax + dby + 1, day + dbx + 1);
        int d3 = max(dax + dby + 1, day + dbx + 1);

        if (k >= d1 and (k - d1) % 2 == 0) cout << "YES\n";
        else if (k >= d2 and (k - d2) % 2 == 0) cout << "YES\n";
        else if (k >= d3 and (k - d3) % 2 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}