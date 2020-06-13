#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, u, v, C, S1, S2, u1;
vector<vector<int>> G;
vector<bool> V, A;
vector<int> S;

int size(int u)
{
    V[u] = 1;
    for (int v : G[u]) if (!V[v]) S[u] += size(v);
    return S[u];
}

void find(int u)
{
    V[u] = 1; C = u;
    for (int v : G[u]) if (!V[v] && S[v] > N / 2) find(v);
}

void solve(int u, int i)
{
    V[u] = 1;

    if (N - S[i] <= N / 2) A[u] = 1;
    if (S[u] + (i != u1 ? S1 : S2) >= N - N / 2) A[u] = 1;

    for (int v : G[u]) if (!V[v]) solve(v, i);
}

int main()
{
    cin >> N;

    G.assign(N, {});
    rep(i, N - 1)
    {
        cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    S.assign(N, 1);
    V.assign(N, 0);
    size(0);

    V.assign(N, 0);
    find(0);

    S.assign(N, 1);
    V.assign(N, 0);
    size(C);

    S1 = S2 = -1;
    for (int v : G[C])
    {
        if (S[v] >= S1) S2 = S1, S1 = S[v], u1 = v;
        else if (S[v] > S2) S2 = S[v];
    }

    A.assign(N, 0); A[C] = 1;
    V.assign(N, 0); V[C] = 1;
    for (int v : G[C]) solve(v, v);

    rep(i, N) cout << A[i] << ' ';
    cout << '\n';
}