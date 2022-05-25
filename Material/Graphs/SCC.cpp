#include "../Template.cpp"

int N, id;
vvi G;  // Directed Graph
vi D, L, I; stack<int> S;

void dfs(int u)
{
    D[u] = L[u] = id++, I[u] = 1; S.push(u);
    for (int v : G[u])
    {
        if (D[v] == -1) { dfs(v); L[u] = min(L[v], L[u]); }
        else if (I[v]) L[u] = min(L[v], L[u]);
    }
    if (L[u] == D[u]) while (1) // SCC FOUND
    {
        int x = S.top(); S.pop(); I[x] = 0;
        if (x == u) break;
    }
}

void find_sccs()
{
    D.assign(N, -1); L.resize(N); I.assign(N, 0);
    id = 0; rep(u, N) if (D[u] == -1) dfs(u);
}
