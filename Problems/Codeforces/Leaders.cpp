#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, M, Q, u, v, id;
vector<set<int>> G;
vector<int> D, L, P, C1, C2;
stack<pair<int, int>> S, O;

bool dfs(int u, int p, int d, int c)
{
    D[u] = L[u] = d;
    P[u] = c; bool ans = 0;
    for(int v : G[u]) if (v != p)
    {
        if (D[v] == -1)
        {
            S.emplace(u, v);
            bool odd = dfs(v, u, d + 1, c ^ 1);
            if (p == -1 or L[v] >= d) while (1)
            {
                auto e = S.top(); S.pop();
                if (odd) O.push(e);
                if (e == make_pair(u, v)) break;
            }
            else ans |= odd;
            L[u] = min(L[u], L[v]); 
        }
        else if (D[v] < d)
        {
            S.emplace(u, v); L[u] = min(L[u], D[v]);
            if (P[u] == P[v]) ans = 1;
        }
    }
    return ans;
}

void dfs(int u, vector<int> &C)
{
    C[u] = id;
    for (int v : G[u]) if (C[v] == -1) dfs(v, C);
}

int main()
{
    cin >> N >> M;

    G.resize(N);
    rep(_, M)
    {
        cin >> u >> v; u--, v--;
        G[u].insert(v); G[v].insert(u);
    }

    C1.assign(N, -1); id = 0;
    rep(u, N) if (C1[u] == -1) dfs(u, C1), id++;

    D.assign(N, -1); L.resize(N); P.resize(N);
    rep(u, N) if (D[u] == -1) dfs(u, -1, 0, 0);

    while (!O.empty())
    {
        tie(u, v) = O.top(); O.pop();
        G[u].erase(v); G[v].erase(u);
    }

    C2.assign(N, -1); id = 0;
    rep(u, N) if (C2[u] == -1) dfs(u, C2), id++;

    cin >> Q;
    while (Q--)
    {
        cin >> u >> v; u--, v--;
        if (C1[u] != C1[v]) cout << "No\n";
        else if (C2[u] != C2[v]) cout << "Yes\n";
        else if (P[u] != P[v]) cout << "Yes\n";
        else cout << "No\n";
    }
}