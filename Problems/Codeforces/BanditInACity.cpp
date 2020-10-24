#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, u;
vector<vector<int>> G;
vector<ll> A, M, S, L;

void dfs(int u)
{
    if (G[u].empty()) { L[u] = 0; S[u] = 1; M[u] = A[u]; return; }

    ll m = 0, l = 0;
    for (int v : G[u]) dfs(v), m = max(m, M[v]), S[u] += S[v];
    for (int v : G[u]) l += S[v] * (m - M[v]) + L[v];
    L[u] = max(0ll, l - A[u]); A[u] = max(0ll, A[u] - l);
    if (A[u])
    {
        M[u] = m + (A[u] / S[u]) + ll(bool(A[u] % S[u]));
        L[u] = (S[u] - (A[u] % S[u])) % S[u];
    }
    else M[u] = m;
}

int main()
{
    cin >> N;

    G.resize(N);
    rep(i, N - 1) { cin >> u; G[u - 1].push_back(i + 1); }

    A.resize(N);
    rep(i, N) cin >> A[i];

    M.resize(N), S.assign(N, 0), L.resize(N); dfs(0);

    cout << M[0] << '\n';
}