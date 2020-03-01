#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second
typedef pair<int,int> ii;

int n, m, u, v, k;
vector<vector<ii>> g, g_;
vector<int> p, mindist, parent;

void dijkstra(int source) {
    parent.assign(n, -1);
    mindist.assign(n, INT_MAX);
    mindist[source] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.emplace(0, source);
    while (!q.empty()) {
        ii p = q.top(); q.pop();
        int u = p.ss, dist = p.ff;
        if (mindist[u] < dist) continue;
        for (ii& e : g_[u]) {
            int v = e.ss, w = e.ff;
            if (mindist[v] > dist + w) {
                mindist[v] = dist + w;
                parent[v] = u;
                q.emplace(mindist[v], v);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    g.assign(n, {});
    g_.assign(n, {});

    rep(i, m)
    {
        cin >> u >> v; u--; v--;
        g[u].emplace_back(1, v);
        g_[v].emplace_back(1, u);
    }

    cin >> k;

    p.resize(k);
    rep(i, k) { cin >> p[i]; p[i]--; }

    dijkstra(p[k - 1]);

    int m = 0, M = 0;
    rep(i, k - 1)
    {
        // cerr << mindist[p[i]] << ' ' << mindist[p[i + 1]] << '\n';
        if (mindist[p[i]] != mindist[p[i + 1]] + 1) { m++; M++; }
        else
        {
            int aux = 0;
            for (ii e : g[p[i]])
                if (mindist[p[i]] == mindist[e.ss] + 1) aux++;

            if (aux > 1) M++;
        }
    }

    cout << m << ' ' << M << '\n';
}