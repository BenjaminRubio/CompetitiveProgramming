#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

const ll INF = 1e10;

struct Edge
{
    int v; ll w;
    Edge(int v, ll w) : v(v), w(w) {}
    bool operator<(const Edge &e) const { return w > e.w; }
};

int N, M;
pair<int, int> f;
vector<pair<int, int>> P, X, Y;
vector<vector<Edge>> G;

ll inf(int i, int j) { return min(abs(P[i].ff - P[j].ff), abs(P[i].ss - P[j].ss)); }
ll cost(int i) { return abs(P[i].ff - f.ff) + abs(P[i].ss - f.ss); }

int main()
{
    cin >> N >> M;
    
    P.resize(M + 1);
    cin >> P[0].ff >> P[0].ss >> f.ff >> f.ss;

    rep(i, M) cin >> P[i + 1].ff >> P[i + 1].ss;

    rep(i, M + 1) X.emplace_back(P[i].ff, i);
    rep(i, M + 1) Y.emplace_back(P[i].ss, i);

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    G.resize(M + 2);
    rep(i, M) G[X[i].ss].emplace_back(X[i + 1].ss, inf(X[i].ss, X[i + 1].ss)),
              G[X[i + 1].ss].emplace_back(X[i].ss, inf(X[i].ss, X[i + 1].ss)),
              G[Y[i].ss].emplace_back(Y[i + 1].ss, inf(Y[i].ss, Y[i + 1].ss)),
              G[Y[i + 1].ss].emplace_back(Y[i].ss, inf(Y[i].ss, Y[i + 1].ss)),
              G[M + 1].emplace_back(i, cost(i)),
              G[i].emplace_back(M + 1, cost(i));
    G[M + 1].emplace_back(M, cost(M)),
    G[M].emplace_back(M + 1, cost(M));

    vector<ll> C(M + 2, INF);
    priority_queue<Edge> q;

    q.emplace(0, 0);
    C[0] = 0;
    while (!q.empty())
    {
        int u = q.top().v, w = q.top().w; q.pop();

        if (C[u] < w) continue;

        for (auto e : G[u]) if (C[e.v] > e.w + w)
        {
            C[e.v] = e.w + w;
            q.emplace(e.v, C[e.v]);
        }
    }

    cout << C[M + 1] << '\n';
}