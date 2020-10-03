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
            flow.ff = min(flow.ff, L[F[v]].c), flow.ss += L[F[v]].w;
        for (int v = t; v != s; v = L[F[v] ^ 1].v)
            L[F[v]].c -= flow.ff, L[F[v] ^ 1].c += flow.ff;
        return flow;
    }

public:
    MCMF(int n) : n(n), E(n), D(n), P(n, 0), V(n, 0) {}

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
        L.emplace_back(u, 0, -w);
    }
};

int N, A[100], C[26];
string T, S[100];

int main()
{
    cin >> T >> N;
    rep(i, N) cin >> S[i] >> A[i];
    
    MCMF<int> flow(N + 28);

    rep(i, N)
    {
        flow.addEdge(0, 1 + i, A[i], 0);
        memset(C, 0, sizeof C);
        for (char c : S[i]) C[c - 'a']++;
        rep(j, 26) flow.addEdge(1 + i, 1 + N + j, C[j], i + 1);
    }

    memset(C, 0, sizeof C);
    for (char c : T) C[c - 'a']++;
    rep(j, 26) flow.addEdge(1 + N + j, N + 27, C[j], 0);

    auto ans = flow.mcmf(0, N + 27);

    if (ans.ff == T.size()) cout << ans.ss << '\n';
    else cout << -1 << '\n';
}