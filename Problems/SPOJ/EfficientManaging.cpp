#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

struct TrieXOR
{
    int N[10000000][2] = {0}, S[10000000] = {0}, c = 0;
    TrieXOR() {}
    void add(int x, int a = 1)
    {
        int p = 0; S[p] += a;
        rep(i, 31)
        {
            int t = (x >> (30 - i)) & 1;
            if (!N[p][t]) N[p][t] = ++c;
            S[p = N[p][t]] += a;
        }
    }
    int get(int x)
    {
        if (!S[0]) return -1;
        int p = 0; rep(i, 31)
        {
            int t = ((x >> (30 - i)) & 1) ^ 1;
            if (!N[p][t] || !S[N[p][t]]) t ^= 1;
            p = N[p][t]; if (t) x ^= (1 << (30 - i));
        }
        return x;
    }
};

int N, u, v, c;
vector<vector<pair<int, int>>> G;
vector<int> V;

void dfs(int u, int p, int x)
{
    V[u] = x;
    for (auto &e : G[u]) if (e.ff != p) dfs(e.ff, u, x ^ e.ss);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    while (cin >> N)
    {
        G.assign(N, {});
        rep(_, N - 1)
        {
            cin >> u >> v >> c; u--, v--;
            G[u].emplace_back(v, c);
            G[v].emplace_back(u, c);
        }

        V.resize(N); dfs(0, -1, 0);

        TrieXOR T;
        rep(i, N) T.add(V[i]);

        rep(i, N) cout << T.get(V[i]) << '\n';
    }
}