#include "../Template.cpp"

vvi B, T;

bool get_TD2(vvi &G, int N)
{
    B.assign(N, {}), T.assign(N, {});

    vector<set<int>> S(N);
    rep(u, N) for (int v : G[u]) S[u].insert(v);

    vp P(N);
    vi O(N, -1);
    queue<int> Q;
    rep(u, N) if (S[u].size() <= 2) Q.push(u);

    int id = 0, r = -1;
    while (!Q.empty())
    {
        int u = Q.front(); Q.pop();
        if (O[u] != -1) continue;

        O[u] = id++, B[u].pb(u);
        for (int v : S[u]) B[u].pb(v);
        if (S[u].empty())
        {
            P[u] = {r, r};
            if (r == -1) r = u;
            continue;
        }

        int v = *S[u].begin();
        S[u].erase(v), S[v].erase(u);
        P[u] = {v, v};
        if (!S[u].empty())
        {
            int w = *S[u].begin();
            S[u].erase(w), S[w].erase(u);
            S[v].insert(w), S[w].insert(v);
            P[u].ss = w;
            if (S[w].size() <= 2) Q.push(w);
        }
        if (S[v].size() <= 2) Q.push(v);
    }

    if (id != N) return 0;
    rep(u, N) if (u != r)
    {
        int p = O[P[u].ff] < O[P[u].ss] ? P[u].ff : P[u].ss;
        T[u].pb(p), T[p].pb(u);
    }
    return 1;
}
