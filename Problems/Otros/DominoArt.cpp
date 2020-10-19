#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

class Dinic
{
    struct Edge { int to, rev, f, c; };
    int n, t_; vector<vector<Edge>> G;
    vector<int> D, q, W;

    bool bfs(int s, int t)
    {
        W.assign(n, 0); D.assign(n, -1); D[s] = 0;
        int f = 0, l = 0; q[l++] = s;
        while (f < l)
        {
            int u = q[f++];
            for (const Edge &e : G[u]) if (D[e.to] == -1 && e.f < e.c)
                D[e.to] = D[u] + 1, q[l++] = e.to;
        }
        return D[t] != -1;
    }
    int dfs(int u, int f)
    {
        if (u == t_) return f;
        for (int &i = W[u]; i < (int)G[u].size(); ++i)
        {
            Edge &e = G[u][i]; int v = e.to;
            if (e.c <= e.f || D[v] != D[u] + 1) continue;
            int df = dfs(v, min(f, e.c - e.f));
            if (df > 0) { e.f += df, G[v][e.rev].f -= df; return df; }
        }
        return 0;
    }

public:
    Dinic(int N) : n(N), G(N), D(N), q(N) {}
    void addEdge(int u, int v, int cap)
    {
        G[u].push_back({v, (int)G[v].size(), 0, cap});
        G[v].push_back({u, (int)G[u].size() - 1, 0, 0});
    }
    int maxFlow(int s, int t)
    {
        t_ = t; int ans = 0;
        while (bfs(s, t)) while (int dl = dfs(s, INT_MAX)) ans += dl;
        return ans;
    }
};

int R, C; char ch;
vector<vector<bool>> M;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool in(int i, int j) { return (i >= 0 && i < R && j >= 0 && j < C); }

int main()
{
    int tt = 1;
    while (cin >> R >> C && R)
    {
        M.assign(R, vector<bool>(C, 0)); int c = 0;
        rep(i, R) rep(j, C) { cin >> ch; M[i][j] = (ch == '#'), c += M[i][j]; }

        Dinic flow(R * C + 2);
        rep(i, R) rep(j, C)
        {
            if (M[i][j] && ((i + j) & 1)) flow.addEdge(0, i * C + j + 1, 1);
            else if (M[i][j]) flow.addEdge(i * C + j + 1, R * C + 1, 1);

            if ((i + j) & 1) rep(k, 4) if (in(i + dx[k], j + dy[k]))
            {
                int i_ = i + dx[k], j_ = j + dy[k];
                flow.addEdge(i * C + j + 1, i_ * C + j_ + 1, 1);
            }
        }

        bool flag = (flow.maxFlow(0, R * C + 1) == c / 2);
        cout << "Case " << tt++ << ": " << (flag ? "Possible" : "Impossible") << '\n';
    }
}