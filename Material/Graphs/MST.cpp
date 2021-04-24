
// PRIM //

struct Edge
{
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator>(const Edge &e) const { return w > e.w; }
};

int find_mst(vector<vector<Edge>> &g, vector<vector<Edge>> &T)
{
    int n = g.size();
    vector<bool> V(n, 0);
    T.assign(n, {});

    int ans = 0, c = 1; V[0] = 1;
    priority_queue<Edge, vector<Edge>, greater<Edge>> q;
    for (Edge &p : g[0]) q.emplace(0, p.v, p.w);

    while (!q.empty())
    {
        Edge e = q.top(); q.pop();

        if (V[e.v]) continue;

        int u = e.u, v = e.v, w = e.w;
        V[v] = true, ans += w;
        T[u].eb(u, v, w);
        T[v].eb(v, u, w);

        if (++c == n) break;

        for (Edge &p : g[v]) if (!V[p.v]) q.emplace(v, p.v, p.w);
    }
    
    return ans;
}