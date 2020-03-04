#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

const int INF = 1e9;

struct Edge
{
    int v, w;
    Edge(int v, int w) : v(v), w(w) {}
};

int T, n, m, x, y, t;
vector<vector<Edge>> g;
vector<int> D;

bool bellmanFord(int s)
{
    D.assign(n, INF); D[s] = 0;
    rep(i, n - 1) rep(j, n) for (Edge e : g[j])
        D[e.v] = min(D[e.v], D[j] + e.w);

    bool neg = false;
    rep(i, n) for (Edge e : g[i]) if (D[e.v] > D[i] + e.w) neg = true;

    return neg;
}

int main()
{
    cin >> T;
    rep(_, T)
    {
        cin >> n >> m;

        g.assign(n, {});
        rep(_, m)
        {
            cin >> x >> y >> t;
            g[x].emplace_back(y, t);
        }

        bool ans = bellmanFord(0);

        if (ans) cout << "possible\n";
        else cout << "not possible\n";
    }
}