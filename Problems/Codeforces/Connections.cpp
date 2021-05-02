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

int T, N, M, u, v;
vector<vi> G, R;
vi V; vp E; set<pii> S;

void dfs1(int u)
{
    V[u] = 1;
    for (int v : G[u]) if (!V[v]) { S.emplace(u, v); dfs1(v); }
}

void dfs2(int u)
{
    V[u] = 1;
    for (int v : R[u]) if (!V[v]) { S.emplace(v, u); dfs2(v); }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    while (T--)
    {
        S.clear(); E.clear();
        cin >> N >> M;

        G.assign(N, {}), R.assign(N, {});
        rep(_, M)
        {
            cin >> u >> v; u--, v--;
            E.eb(u, v);
            G[u].pb(v), R[v].pb(u);
        }

        V.assign(N, 0); dfs1(0);
        V.assign(N, 0); dfs2(0);

        int ans = 0;
        for (auto &e : E)
        {
            if (ans == (M - 2 * N)) break;
            if (!S.count(e)) { cout << e.ff + 1 << ' ' << e.ss + 1 << '\n'; ans++; }
        }
    }
}
