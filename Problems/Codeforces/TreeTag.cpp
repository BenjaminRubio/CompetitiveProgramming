#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, A, B, da, db, u, v;
vector<vector<int>> G;
int D[100010];

pair<int, int> F_from(int s)
{
    memset(D, -1, sizeof(int) * G.size());
    int F = s;
    queue<int> q;
    q.push(s);
    D[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : G[u]) {
            if (D[v] == -1) {
                D[v] = D[u] + 1;
                q.push(v);
                if (D[v] > D[F]) F = v;
            }
        }
    }
    return {F, D[F]};
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> A >> B >> da >> db;

        G.assign(N, {});
        rep(_, N - 1)
        {
            cin >> u >> v; u--, v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        if (da >= db) { cout << "Alice\n"; continue; }

        pair<int, int> e1 = F_from(A - 1);

        if (D[B - 1] <= da) { cout << "Alice\n"; continue; }

        pair<int, int> e2 = F_from(e1.first);

        if ((min(e2.second, db) + 1) / 2 > da) cout << "Bob\n";
        else cout << "Alice\n";
    }
}