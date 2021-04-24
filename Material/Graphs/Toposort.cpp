
int N; vi V, S;
vector<vi> G;

void dfs(int u)
{
    V[u] = 1;
    for (int v : G[u]) if (!V[v]) dfs(v);
    S.pb(u);
}

void topo_sort()
{  
    V.assign(N, 0); S.clear(); 
    rep(i, N) if (!V[i]) dfs(i);
}
