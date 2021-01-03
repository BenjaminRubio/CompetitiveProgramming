#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct DSU
{
    vector<int> p;
    DSU(int N) : p(N, -1) {}
    int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); } 
    bool sameSet(int a, int b) { return get(a) == get(b); }
    void unite(int x, int y)
    {
        if ((x = get(x)) == (y = get(y))) return;
        if (p[x] > p[y]) swap(x,y);
        p[x] += p[y], p[y] = x;
    }
};

const ll MOD = 1e9 + 7;

int N, M, K, X;
vector<vector<int>> G;

int main()
{
    cin >> N >> M;

    G.resize(N);
    rep(i, N)
    {
        cin >> K;
        rep(_, K)
        {
            cin >> X; X--;
            G[i].push_back(X);
        }
        if (K == 1) G[i].push_back(M);
    }

    DSU dsu(M + 1);

    vector<int> ans;
    rep(i, N) if (!dsu.sameSet(G[i][0], G[i][1]))
    {
        ans.push_back(i);
        dsu.unite(G[i][0], G[i][1]);
    }

    ll p = 1;
    rep(i, ans.size()) p = (p * 2) % MOD;

    cout << p << ' ' << ans.size() << '\n';
    for (int x : ans) cout << x + 1 << ' ';
    cout << '\n';
}