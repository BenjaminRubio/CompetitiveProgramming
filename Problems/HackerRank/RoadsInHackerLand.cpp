#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct Edge
{
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator>(const Edge &e) const { return w > e.w; }
};

const int MAXP = 1e6;

ll N, M, A, B, C;
vector<vector<Edge>> G, T;
vector<bool> V;
vector<int> S;
vector<ll> ans;

int dfs(int u, int p)
{
    for (Edge &e : T[u]) if (e.v != p) S[u] += dfs(e.v, u);
    return ++S[u];
}

void solve(int u, int p)
{
    for (Edge &e : T[u]) if (e.v != p)
        ans[e.w] = S[e.v] * (N - S[e.v]), solve(e.v, u);
}

int main()
{
    cin >> N >> M; T.assign(N, {});

    G.assign(N, {});
    rep(_, M)
    {
        cin >> A >> B >> C; A--, B--;
        G[A].emplace_back(A, B, C);
        G[B].emplace_back(B, A, C);
    }

    V.assign(N, false);

    int cst = 0, c = 1;
    V[0] = true;

    priority_queue<Edge, vector<Edge>, greater<Edge>> q;
    for (Edge &p : G[0]) q.emplace(0, p.v, p.w);

    while (!q.empty())
    {
        Edge edge = q.top(); q.pop();

        if (V[edge.v]) continue;

        int u = edge.u, v = edge.v, w = edge.w;
        V[v] = true;
        cst += w;
        T[u].emplace_back(u, v, w);
        T[v].emplace_back(v, u, w);

        if (++c == N) break;

        for (Edge p : G[v]) if (!V[p.v]) q.emplace(v, p.v, p.w);
    }

    S.assign(N, 0); ans.assign(MAXP, 0);
    dfs(0, -1); solve(0, -1);

    rep(i, MAXP - 1)
    {
        ans[i + 1] += ans[i] / 2ll;
        ans[i] = ans[i] & 1ll;
    }

    bool on = 0;
    rep(i, MAXP)
    {
        if (ans[MAXP - i - 1]) on = 1;
        if (on) cout << ans[MAXP - i - 1];
    }
    cout << '\n';
}