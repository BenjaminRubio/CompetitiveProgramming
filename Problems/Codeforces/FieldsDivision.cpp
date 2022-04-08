#include <bits/stdc++.h>
using namespace std;

using ul = unsigned long long;
using ll = long long;
using db = double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<db, db>;

using vp = vector<pii>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<db>;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define all(x) begin(x), end(x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

int N, M, u, v;
vi V;
vector<vi> G;

void dfs(int u)
{
    V[u] = 1;
    for (int v : G[u]) if (!V[v]) dfs(v);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    G.assign(N, {});

    rep(_, M)
    {
        cin >> u >> v; u--, v--;
        G[u].pb(v); G[v].pb(u);
    }

    V.assign(N, 0); V[N - 1] = 2;

    dfs(N - 2);

    rep(i, N) cout << (V[i] == 1 ? 'B' : 'A');
    cout << '\n';    
}
