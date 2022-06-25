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

using vvp = vector<vp>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvd = vector<vd>;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define all(x) begin(x), end(x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

int N, M; char c1, c2;
vvi G, C;
string S1, S2;

void dfs(int u, int c)
{
    C[c][u] = 1;
    for (int v : G[u]) if (!C[c][v]) dfs(v, c);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> M >> N;

    G.assign(26, {});
    rep(_, M)
    {
        cin >> c1 >> c2;
        G[c1 - 'a'].pb(c2 - 'a');
    }

    C.assign(26, vi(26, 0));
    rep(i, 26) dfs(i, i);

    rep(_, N)
    {
        cin >> S1 >> S2;

        if (S1.size() != S2.size()) { cout << "no\n"; continue; }

        bool pos = 1;
        rep(i, S1.size()) if (!C[S1[i] - 'a'][S2[i] - 'a']) pos = 0;
        
        cout << (pos ? "yes\n" : "no\n");
    }
}
