#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, u, v;
vector<vector<int>> G;
vector<int> S, D;

int sz(int u, int p)
{
    for (int v : G[u]) if (v != p) S[u] += sz(v, u);
    return S[u];
}

void dfs(int u, int d, int p)
{
    D[u] = d;
    for (int v : G[u]) if (v != p && D[v] == -1) dfs(v, d + 1, p);
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        G.assign(N, {});
        rep(i, N - 1)
        {
            cin >> u >> v; u--, v--;
            G[u].push_back(v); G[v].push_back(u);
        }

        S.assign(N, 1); sz(0, -1);

        int m = INT_MAX;
        vector<vector<int>> C(N);
        rep(i, N)
        {
            int M = 0;
            for (int v : G[i])
            {
                if (S[v] > S[i]) M = max(M, N - S[i]);
                else M = max(M, S[v]);
            }
            
            m = min(m, M);
            C[M].push_back(i);
        }

        if (C[m].size() == 1)
        {
            cout << 1 << ' ' << G[0][0] + 1 << '\n';
            cout << 1 << ' ' << G[0][0] + 1 << '\n';
        }
        else
        {
            u = C[m][0], v = C[m][1];

            int d = 0, j;

            d = 0;
            D.assign(N, -1); dfs(v, 0, u);
            rep(k, N) if (D[k] > d) d = D[k], j = k;

            cout << j + 1 << ' ' << G[j][0] + 1 << '\n';
            cout << u + 1 << ' ' << j + 1 << '\n';
        }
    }
}