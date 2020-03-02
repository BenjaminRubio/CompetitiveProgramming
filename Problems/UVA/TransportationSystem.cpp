#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct Point
{
    int x, y;
    Point() {}
    double dist(Point &p)
    {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }
};

struct Edge
{
    int u, v, t;
    double w;
    Edge(int u, int v, double w, int t) : u(u), v(v), w(w), t(t) {}
    bool operator>(const Edge &o) const { return w > o.w; }
};

int T, n;
double r;
vector<Point> P;
vector<bool> visited;

void dfs(int i)
{
    visited[i] = true;
    rep(j, n) if (!visited[j] and P[i].dist(P[j]) <= r) dfs(j);
}

pair<double, double> find_mst() // Prim
{
    visited.assign(n, false);

    double cost1 = 0, cost2 = 0;
    int count = 1;
    visited[0] = true;

    priority_queue<Edge, vector<Edge>, greater<Edge>> q;
    rep(i, n - 1) q.emplace(0, i + 1, P[0].dist(P[i + 1]),
                            (P[0].dist(P[i + 1]) <= r) ? 0 : 1);

    while (!q.empty())
    {
        Edge edge = q.top(); q.pop();

        if (visited[edge.v]) continue;

        int u = edge.u, v = edge.v, t = edge.t;
        double cost = edge.w;
        // cerr << u << ' ' << v << ' ' << cost << ' ' << t << '\n';
        visited[v] = true;
        if (t) cost2 += cost;
        else cost1 += cost;

        if (++count == n) break;

        rep(i, n) if (!visited[i])
            q.emplace(v, i, P[i].dist(P[v]), (P[i].dist(P[v]) <= r) ? 0 : 1);
    }
    
    return {cost1, cost2};
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> T;
    rep(_, T)
    {
        cin >> n >> r;

        P.resize(n);
        rep(i, n) cin >> P[i].x >> P[i].y;

        int c = 0;
        visited.assign(n, false);
        rep(i, n) if (!visited[i]) { dfs(i); c++; }

        pair<double, double> ans = find_mst();

        cout << "Case #" << _ + 1 << ": ";
        cout << c << ' ' << round(ans.first) << ' ' << round(ans.second) << '\n';
    }
}