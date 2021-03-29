#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

const int INF = 1e9;

struct Edge
{
    int v, w;
    Edge(int v, int w) : v(v), w(w) {}
    bool operator<(const Edge &e) const { return w > e.w; }
};

int N, A, B, H;
vector<vector<Edge>> G;

int dijkstra(int s, int t)
{
    vector<int> C(1001, INF); C[s] = 0;
    priority_queue<Edge> q; q.emplace(s, 0);
    while (!q.empty())
    {
        int u = q.top().v, w = q.top().w; q.pop();
        if (C[u] < w) continue;
        for (auto e : G[u]) if (C[e.v] > e.w + w)
            C[e.v] = e.w + w, q.emplace(e.v, C[e.v]);
    }
    return C[t];
}

int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);

    while (cin >> N && N)
    {
        G.assign(1001, {});
        rep(_, N)
        {
            cin >> A >> B >> H;
            G[A].emplace_back(B, (A + B) * H);
            G[B].emplace_back(A, (A + B) * H);
        }

        cin >> A >> B;
        cout << dijkstra(A, B) / 100. << '\n';
    }
}