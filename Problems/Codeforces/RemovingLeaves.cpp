#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, K, u, v;
vector<vector<int>> G;
vector<int> D, L;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> K;

        G.assign(N, {}); D.assign(N, 0);
        rep(_, N - 1)
        {
            cin >> u >> v; u--, v--;
            G[u].push_back(v), G[v].push_back(u);
            D[u]++, D[v]++;
        }

        if (N == 2)
        {
            cout << 1 << '\n';
            continue;
        }

        L.assign(N, 0);
        rep(u, N) if (D[u] == 1) L[*G[u].begin()]++;

        priority_queue<pair<int, int>> Q;
        rep(u, N) Q.emplace(L[u], u);

        int ans = 0;
        while (!Q.empty())
        {
            int u = Q.top().second; Q.pop();
            if (L[u] >= K)
            {
                int moves = L[u] / K;
                ans += moves;
                L[u] -= moves * K;
                D[u] -= moves * K;

                if (D[u] == 1) for (int v : G[u]) if (D[v] > 1)
                {
                    L[v]++;
                    Q.emplace(L[v], v);
                }
            }
        }

        cout << ans << '\n';
    }
}
