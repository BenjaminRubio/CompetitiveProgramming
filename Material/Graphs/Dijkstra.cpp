
const int INF = 1e9;

struct Edge
{
    int v, w;  // CHECK FOR OVERFLOW
    Edge(int v, int w) : v(v), w(w) {}
    bool operator<(const Edge &e) const { return w > e.w; }
};

int n;
vector<vector<Edge>> G;

int dijkstra(int s, int t)
{
    vi C(n, INF); C[s] = 0;  // CHECK FOR OVERFLOW
    priority_queue<Edge> q; q.emplace(s, 0);
    while (!q.empty())
    {
        int u = q.top().v, w = q.top().w; q.pop();  // CHECK FOR OVERFLOW
        if (C[u] < w) continue;
        for (auto e : G[u]) if (C[e.v] > e.w + w)
            C[e.v] = e.w + w, q.emplace(e.v, C[e.v]);
    }
    return C[t];
}