#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

ll N;
vector<ll> A, B, A_;
vector<vector<ll>> G;
vector<bool> V;
vector<int> sorted;

void dfs(int u)
{
    V[u] = true;
    for (ll v : G[u]) if (!V[v]) dfs(v);
    sorted.push_back(u);
}

int main()
{
    cin >> N;

    A.resize(N); B.resize(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    G.assign(N, {});
    rep(i, N) if (B[i] != -1) G[i].push_back(B[i] - 1);

    V.assign(N, 0);
    sorted.clear(); 
    rep(i, N) if (!V[i]) dfs(i);

    reverse(sorted.begin(), sorted.end());

    ll M = 0;
    queue<ll> ans;
    stack<ll> q;
    for (int i : sorted)
    {
        M += A[i];
        if (A[i] < 0) q.push(i + 1);
        else { if (B[i] != -1) A[B[i] - 1] += A[i]; ans.push(i + 1); }
    }
    while (!q.empty()) ans.push(q.top()), q.pop();

    cout << M << '\n';
    while (!ans.empty()) { cout << ans.front() << ' '; ans.pop(); }
    cout << '\n';
}