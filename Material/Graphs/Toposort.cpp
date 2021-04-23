#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N;
vector<vector<int>> G;
vector<int> V, S;

void dfs(int u)
{
    V[u] = 1;
    for (int v : G[u]) if (!V[v]) dfs(v);
    S.push_back(u);
}

void topo_sort()
{  
    V.assign(N, 0); S.clear(); 
    rep(i, N) if (!V[i]) dfs(i);
}
