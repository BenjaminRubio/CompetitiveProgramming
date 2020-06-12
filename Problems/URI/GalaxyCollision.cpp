#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ff first
#define ss second

int N, X, Y, E, O;
map<pair<int, int>, int> M;
vector<pair<int, int>> C;
vector<vector<int>> G;
vector<bool> V;

void dfs(int u, bool p)
{
    if (p) E++;
    else O++;

    V[u] = 1;
    for (int v : G[u]) if (!V[v]) dfs(v, !p);
}

int main()
{
    cin >> N;

    C.resize(N);
    rep(i, N) { cin >> X >> Y; M[{X, Y}] = i + 1; C[i] = {X, Y}; }

    G.assign(N, {});
    rep(i, N)
    {
        X = C[i].ff, Y = C[i].ss;
        repx(dx, -5, 6) repx(dy, -5, 6)
        {
            int X_ = X + dx, Y_ = Y + dy;
            if (dx * dx + dy * dy <= 25 && M[{X_, Y_}])
                G[i].push_back(M[{X_, Y_}] - 1);
        }
    }

    int ans = 0;
    V.assign(N, false);
    rep(i, N) if (!V[i])
    {
        E = O = 0;
        dfs(i, 0);
        ans += min(E, O);
    }

    cout << ans << '\n';
}