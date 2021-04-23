
const int INF = 1e9;

struct Edge
{
    int v, w;
    Edge(int v, int w) : v(v), w(w) {}
};

int n;
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