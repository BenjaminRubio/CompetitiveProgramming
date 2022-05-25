#include "../Template.cpp"

const int INF = 1e9;

struct Edge
{
    int v, w;
    Edge(int v, int w) : v(v), w(w) {}
};

int n; vi D;
vector<vector<Edge>> G;

bool bellmanFord(int s)
{
    D.assign(n, INF); D[s] = 0;
    rep(i, n - 1) rep(j, n) for (Edge e : G[j])
        D[e.v] = min(D[e.v], D[j] + e.w);

    bool neg = false;
    rep(i, n) for (Edge e : G[i]) if (D[e.v] > D[i] + e.w) neg = true;

    return neg;
}
