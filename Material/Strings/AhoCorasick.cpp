#include "../Template.cpp"

struct AC
{
    int c = 0, ec = 0, M, A;
    vvi N, G; vi L, E;

    AC (int M, int A) : M(M), A(A), N(M, vi(A, 0)), E(M, 0), L(M, 0) {}
    int add(string s)
    {
        int p = 0;
        for (char l : s)
        {
            int t = l - 'a';
            if (!N[p][t]) N[p][t] = ++c;
            p = N[p][t];
        } E[p]++; return p;
    }
    void init()
    {
        G.assign(M, {});
        queue<int> q; q.push(0); L[0] = -1;
        while (!q.empty())
        {
            int p = q.front(); q.pop();
            rep(c, A)
            {
                int u = N[p][c]; if (!u) continue;
                L[u] = L[p] == -1 ? 0 : N[L[p]][c], q.push(u);
                G[L[u]].pb(u);
            }
            if (p) rep(c, A) if (!N[p][c]) N[p][c] = N[L[p]][c];
        }
    }
};
