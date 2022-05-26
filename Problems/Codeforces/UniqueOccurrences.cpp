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

struct DSU
{
    vi p; DSU() {} DSU(int N) : p(N, -1) {}
    int get(int x) { return p[x] < 0 ? x : get(p[x]); }
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -p[get(x)]; }
    vvi S;
    void unite(int x, int y)
    {
        if ((x = get(x)) == (y = get(y))) { S.pb({-1}); return; }
        if (p[x] > p[y]) swap(x, y);
        S.pb({x, y, p[x], p[y]});
        p[x] += p[y], p[y] = x;
    }
    void rollback()
    {
        auto a = S.back(); S.pop_back();
        if (a[0] != -1) p[a[0]] = a[2], p[a[1]] = a[3];
    }
};

enum {ADD, QUERY};
struct OP { int t, u, v; };

struct DC
{
    int n; ll ans; DSU D; vector<vector<OP>> t;
    DC(int N) : n(N), D(N), t(2 * N), ans(0) {}
    void upd(int l, int r, OP p) // add edge p to all times in interval [l, r]
    {
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) t[l++].pb(p);
            if (r & 1) t[--r].pb(p);
        }
    }
    void process(int u)
    {
        for (auto &e : t[u]) if (e.t == ADD) D.unite(e.u, e.v);
        if (u >= n)
        {
            for (auto &e : t[u]) if (e.t == QUERY) ans += (ll)D.size(e.u) * (ll)D.size(e.v);
        }
        else process(2 * u), process(2 * u + 1);
        for (auto &e : t[u]) if (e.t == ADD) D.rollback();
    }
};

int N, u, v, x;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    DC dc(N + 1);
    rep(_, N - 1)
    {
        cin >> u >> v >> x; u--, v--;
        dc.upd(0, x, {ADD, u, v});
        dc.upd(x + 1, N + 1, {ADD, u, v});
        dc.upd(x, x + 1, {QUERY, u, v});
    }
    dc.process(1);

    cout << dc.ans << '\n';
}
