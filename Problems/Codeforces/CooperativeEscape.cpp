#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

template <class T>
class MCMF
{
    typedef pair<T, T> pTT;
    T INF = numeric_limits<T>::max();
    struct Edge
    {
        int v; T c, w;
        Edge(int v, T c, T w) : v(v), c(c), w(w) {}
    };

    int n;
    vector<vector<int>> E;
    vector<Edge> L;
    vector<int> F;
    vector<T> D, P;
    vector<bool> V;

    bool dij(int s, int t)
    {
        D.assign(n, INF); F.assign(n, -1); V.assign(n, false);
        D[s] = 0;
        rep(_, n)
        {
            int best = -1;
            rep(i, n) if (!V[i] && (best == -1 || D[best] > D[i])) best = i;
            if (D[best] >= INF) break;
            V[best] = true;
            for (int e : E[best])
            {
                Edge ed = L[e];
                if (ed.c == 0) continue;
                T toD = D[best] + ed.w + P[best] - P[ed.v];
                if (toD < D[ed.v]) D[ed.v] = toD, F[ed.v] = e;
            }
        }
        return D[t] < INF;
    }

    pTT augment(int s, int t)
    {
        pTT flow(L[F[t]].c, 0);
        for (int v = t; v != s; v = L[F[v] ^ 1].v)
        {
            flow.ff = min(flow.ff, L[F[v]].c);
            flow.ss += L[F[v]].w;
        }
        for (int v = t; v != s; v = L[F[v] ^ 1].v)
        {
            L[F[v]].c -= flow.ff;
            L[F[v] ^ 1].c += flow.ff;
        }
        return flow;
    }

public:
    MCMF(int n) : n(n)
    {
        E.resize(n); P.assign(n, 0); D.resize(n);
        V.assign(n, false);
    }

    pTT mcmf(int s, int t)
    {
        pTT ans(0, 0);
        if (!dij(s, t)) return ans;
        rep(i, n) if (D[i] < INF) P[i] += D[i];
        while (dij(s, t))
        {
            auto flow = augment(s, t);
            ans.ff += flow.ff, ans.ss += flow.ff * flow.ss;
            rep(i, n) if (D[i] < INF) P[i] += D[i];
        }
        return ans;
    }

    void addEdge(int u, int v, T c, T w)
    {
        E[u].push_back(L.size());
        L.emplace_back(v, c, w);
        E[v].push_back(L.size());
        L.emplace_back(u, 0, -c);
    }
};

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<char>> M(r + 2, vector<char>(c + 2, 'x'));
    int B, C, F;
    MCMF<int> AA(r * c+1);
    rep(i, r)
    {
        rep(j, c)
        {
            cin >> M[i + 1][j + 1];
            int ch = M[i + 1][j + 1];
            if (ch == 'x')
                continue;
            if (ch == 'B')
                B = c * i + j;
            if (ch == 'F')
                F = c * i + j;
            if (ch == 'C')
                C = c * i + j;
            if (M[i][j + 1] != 'x')
            {
                AA.addEdge(c * i + j, c * (i - 1) + j, 1, 1);
                AA.addEdge(c * (i - 1) + j, c * i + j, 1, 1);
            }
            if (M[i + 1][j] != 'x')
            {
                AA.addEdge(c * i + j, c * i + j - 1, 1, 1);
                AA.addEdge(c * i + j - 1, c * i + j, 1, 1);
            }
        }
    }
    cerr << B << ' ' << C << ' ' << F << '\n';
    AA.addEdge(r * c, B, 1, 0);
    AA.addEdge(r * c, C, 1, 0);
    pair<int, int> ans = AA.mcmf(r * c, F);
 
    if (ans.ff < 2) cout << -1 << '\n';
    else
        cout << ans.ss << '\n';
}