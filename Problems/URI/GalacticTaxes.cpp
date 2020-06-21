#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

const double INF = 1e10;

struct F
{
    int v; double A, B;
    F(int v, int A, int B) : v(v), A(A), B(B) {}
    double eval(double T) { return A * T + B; }
};

struct Edge
{
    int v; double w;
    Edge(int v, double w) : v(v), w(w) {}
    bool operator>(const Edge &e) const { return w > e.w; }
};

int N, M, u, v;
double A, B;
vector<vector<F>> g;

double dijkstra(int s, int t, double T)
{
    vector<double> cost(N, INF);
    priority_queue<Edge, vector<Edge>, greater<Edge>> q;

    q.emplace(s, 0);
    cost[s] = 0;
    while (!q.empty())
    {
        int u = q.top().v; double w = q.top().w; q.pop();

        if (cost[u] < w) continue;

        for (auto e : g[u]) if (cost[e.v] > e.eval(T) + w)
        {
            cost[e.v] = e.eval(T) + w;
            q.emplace(e.v, cost[e.v]);
        }
    }
    return cost[t];
}

int main()
{
    cout.setf(ios::fixed);
    cout.precision(5);

    cin >> N >> M;

    g.assign(N, {});
    rep(_, M)
    {
        cin >> u >> v >> A >> B; u--, v--;
        g[u].emplace_back(v, A, B);
        g[v].emplace_back(u, A, B);
    }

    double l = 0, r = 24 * 60;
    double t, T1, T2, v1, v2;
    rep(_, 100)
    {
        t = (r - l) / 3.;
        T1 = l + t, T2 = r - t;

        v1 = dijkstra(0, N - 1, T1), v2 = dijkstra(0, N - 1, T2);

        if (v1 > v2) r = T2;
        if (v2 > v1) l = T1;
        if (v1 == v2) l = T1, r = T2;
    }

    cout << (v1 + v2) * .5 << '\n';
}