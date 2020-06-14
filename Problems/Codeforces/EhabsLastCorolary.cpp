#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, M, K, u, v;
vector<vector<int>> G;
vector<bool> A;
vector<int> D, P, C;

bool dfs1(int u, int d)
{
    A[u] = 1; D[u] = d;
    bool ans = false;
    for (int v : G[u])
    {
        if (A[v] && D[u] - D[v] <= K - 1 && D[u] - D[v] > 1)
        {
            while (u != v) { C.push_back(u); u = P[u]; }
            C.push_back(u);
            return true;
        }
        if (D[v] == -1)
        {
            P[v] = u;
            ans |= dfs1(v, d + 1);
            if (ans) return ans;
        }
    }
    A[u] = 0;
    return ans;
}

void dfs2(int u, int s, bool d)
{
    if (s == K) return;
    D[u] = d;
    for (int v : G[u]) if (D[v] == -1) dfs2(v, s + 1, !d);
}

int main()
{
    cin >> N >> M >> K;

    G.assign(N, {});
    rep(i, M)
    {
        cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    A.assign(N, 0);
    D.assign(N, -1);
    P.assign(N, -1);
    bool cycle = dfs1(0, 0);

    if (cycle)
    {
        cout << 2 << '\n';
        cout << C.size() << '\n';
        for (int u : C) cout << u + 1 << ' ';
        cout << '\n';
        return 0;
    }

    cout << 1 << '\n';

    D.assign(N, -1);
    dfs2(0, 0, 0);

    int e = 0, o = 0;
    rep(i, N)
    {
        if (D[i] == 0) e++;
        if (D[i] == 1) o++;
    }

    int cnt = 0;
    if (e >= K - K / 2)
    {
        rep(i, N) if (D[i] == 0 && cnt < K - K / 2) { cout << i + 1 << ' '; cnt++; }
    }
    else
    {
        rep(i, N) if (D[i] == 1 && cnt < K - K / 2) { cout << i + 1 << ' '; cnt++; }
    }
    cout << '\n';
}