#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

typedef pair<int, int> par;
typedef vector<par> vp;
typedef vector<vp> wgraph;

bool bellman_ford(wgraph &g, int start)
{
    int n = g.size();
    vector<int> dist(n, 1e9);
    dist[start] = 0;
    rep(i, n - 1) rep(u, n) for (par p : g[u])
    {
        int v = p.first, w = p.second;
        dist[v] = min(dist[v], dist[u] + w);
    }

    bool negativeCycle = false;
    rep(u, n) for (par p : g[u])
    {
        int v = p.first, w = p.second;
        if (dist[v] > dist[u] + w)
            negativeCycle = true;
    }

    return negativeCycle;
}

int N, a, b, h;
vp segments;
set<int> compress;
map<int, int> new_axis;
wgraph g;

int main()
{
    cin >> N;
    rep(i, N)
    {
        cin >> a >> b >> h;
        segments.push_back({a, b});
        compress.insert(a);
        compress.insert(b);
    }

    int M = 1;
    for (int x : compress)
        new_axis[x] = M++;

    rep(i, N) segments[i] = {2 * new_axis[segments[i].first], 2 * new_axis[segments[i].second] - 1};

    int low = 0;
    int high = N;
    while (low < high)
    {
        int m = (low + high) >> 1;

        g.assign(2 * M + 1, {});
        rep(i, 2 * M) g[0].push_back({i + 1, 0});
        repx(i, 1, 2 * M) g[i + 1].push_back({i, 0});
        rep(i, N) g[segments[i].first].push_back({segments[i].second, m});
        rep(i, N) g[segments[i].second].push_back({segments[i].first, -1});

        bool solvable = !bellman_ford(g, 0);
        if (solvable)
            high = m;
        else
            low = m + 1;
    }

    cout << low << '\n';
}