#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

const int MOD = 1e9 + 7;

int N, M, u, v, id; ll num, cost;
vector<vector<int>> G;
vector<int> C, D, L, I; stack<int> S;

void dfs(int u)
{
    D[u] = L[u] = id++, I[u] = 1; S.push(u);
    for (int v : G[u])
    {
        if (D[v] == -1) { dfs(v); L[u] = min(L[v], L[u]); }
        else if (I[v]) L[u] = min(L[v], L[u]);
    }
    if (L[u] == D[u])
    {
        int aux = INT_MAX, c = 0;
        while (1)
        {
            int x = S.top(); S.pop(); I[x] = 0;
            if (C[x] == aux) c++;
            if (C[x] < aux) aux = C[x], c = 1;
            if (x == u) break;
        }
        cost += aux; num = (num * c) % MOD;
    }
}

int main()
{
    cin >> N;

    C.resize(N);
    rep(i, N) cin >> C[i];

    cin >> M;
    G.resize(N);
    while (M--)
    {
        cin >> u >> v; u--, v--;
        G[u].push_back(v);
    }

    D.assign(N, -1); L.resize(N); I.assign(N, 0);
    id = 0, num = 1, cost = 0; rep(u, N) if (D[u] == -1) dfs(u);

    cout << cost << ' ' << num << '\n';
}