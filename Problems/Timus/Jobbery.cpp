#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, u, v, id;
vector<vector<int>> G;
vector<int> D, V, L, I, A; stack<int> S;

int size(int u)
{
    V[u] = 1; int ans = 1;
    for (int v : G[u]) if (!V[v]) ans += size(v);
    return ans;
}

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
        V.assign(N, 0);
        bool in = (size(u) == N);
        while (1)
        {
            int x = S.top(); S.pop(); I[x] = 0;
            if (in) A.push_back(x);
            if (x == u) break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    G.assign(N, {});
    rep(u, N) while (cin >> v && v--) G[u].push_back(v);

    D.assign(N, -1); L.resize(N); I.assign(N, 0);
    id = 0; rep(u, N) if (D[u] == -1) dfs(u);

    sort(A.begin(), A.end());

    for (int a : A) cout << a + 1 << ' ';
    cout << 0 << '\n';
}