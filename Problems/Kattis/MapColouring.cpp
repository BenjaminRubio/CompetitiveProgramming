#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, C, B, u, v, K;
vector<vector<int>> G;
vector<int> P;

bool solve(int u)
{
    if (u == C) return true;

    set<int> s;
    rep(i, K) s.insert(i + 1);
    for (int v : G[u]) if (P[v]) s.erase(P[v]);
    
    for (int c : s)
    {
        P[u] = c;
        if (solve(u + 1)) return true;
        P[u] = 0;
    }

    return false;
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> C >> B;
        G.assign(C, vector<int>());

        rep(_, B)
        {
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        bool sol = false;
        rep(i, 4) if (!sol)
        {
            P.assign(C, 0); K = i + 1;
            if (solve(0))
            {
                sol = true;
                cout << i + 1 << '\n';
            }
        }
        if (!sol) cout << "many\n";
    }
}