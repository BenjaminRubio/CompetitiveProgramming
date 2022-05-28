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
    int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); } 
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -p[get(x)]; }
    void unite(int x, int y)
    {
        if ((x = get(x)) == (y = get(y))) return;
        if (p[x] > p[y]) swap(x,y);
        p[x] += p[y], p[y] = x;
    }
};

const ll M[2] = {1000000007, 1070777777}, b = 1777771;
ll B0[200010], B1[200010];

int N, K, u, v;
vector<vvi> T;

map<pii, ll> DP1, DP2;
map<ll, int> HH[200010];

ll dp2(int i, int u, int p)
{
    if (DP2.count(mp(u, p))) return DP2[mp(u, p)];

    ll ans = 1;
    for (int v : T[i][u]) if (v != p) ans += dp2(i, v, u);

    return DP2[mp(u, p)] = ans;
}

ll dp1(int i, int u, int p)
{
    if (DP1.count(mp(u, p))) return DP1[mp(u, p)];

    vector<pll> h;
    for (int v : T[i][u]) if (v != p) h.eb(dp1(i, v, u), dp2(i, v, u));

    sort(h.begin(), h.end());

    ll H0 = 'a', H1 = 'a', s = 1;
    for (auto &e : h)
    {
        H0 = (H0 + (e.ff * B0[s]) % M[0]) % M[0];
        H1 = (H1 + (e.ff * B1[s]) % M[1]) % M[1];
        s += e.ss;
    }
    H0 = (H0 + ('z' * B0[s]) % M[0]) % M[0];
    H1 = (H1 + ('z' * B1[s]) % M[1]) % M[1];

    return DP1[mp(u, p)] = (H0 << 32) | H1;
}

int global;
DSU dsu;

pair<ll, int> dfs(int i, int u, int p, int k)
{
    int s = 1;
    vector<pll> h;
    for (int v : T[i][u]) if (v != p)
    {
        auto x = dfs(i, v, u, k);
        if (x.ss == -1) return mp(-1, -1);
        s += x.ss;
        if (x.ss) h.eb(x);
    }

    if (s > k) return mp(-1, -1);

    sort(h.begin(), h.end());

    ll H0 = 'a', H1 = 'a', ss = 1;
    for (auto &e : h)
    {
        H0 = (H0 + (e.ff * B0[ss]) % M[0]) % M[0];
        H1 = (H1 + (e.ff * B1[ss]) % M[1]) % M[1];
        ss += e.ss;
    }
    H0 = (H0 + ('z' * B0[ss]) % M[0]) % M[0];
    H1 = (H1 + ('z' * B1[ss]) % M[1]) % M[1];

    ll H = (H0 << 32) | H1;

    if (s == k)
    {
        if (HH[k].count(H))
        {
            int aux = dsu.get(HH[k][H]);
            if (global == -1) global = aux;
            else if (global != aux) return mp(-1, -1);
            return mp(0, 0);
        }
        return mp(-1, -1);
    }
    return mp(H, s);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    B0[0] = 1, B1[0] = 1;
    rep(k, 200010) if (k) B0[k] = (B0[k - 1] * b) % M[0], B1[k] = (B1[k - 1] * b) % M[1];

    cin >> N;

    dsu = DSU(N);

    T.resize(N);

    vp E;
    rep(i, N)
    {
        cin >> K;

        T[i].assign(K, {});
        rep(_, K - 1)
        {
            cin >> u >> v; u--, v--;
            T[i][u].pb(v), T[i][v].pb(u);
        }
        E.eb(K, i);
    }

    sort(E.begin(), E.end());

    vi ans(N, 0);
    for (auto &e : E)
    {
        int i; tie(K, i) = e;

        DP1.clear(), DP2.clear();
        rep(u, K)
        {
            ll h = dp1(i, u, -1);
            if (HH[K].count(h)) dsu.unite(HH[K][h], i);
            else HH[K][h] = i;
            // cerr << i << ' ' << h << '\n';
        }

        // int r;
        // rep(u, K) if (T[i][u].size() == 1) r = u;

        rep(d, int(sqrt(K)) + 1) if (d > 1 && d < K && K % d == 0)
        {
            global = -1;
            auto e1 = dfs(i, 0, -1, d);
            // cerr << i << ' ' << d << ' ' << e1.ff << ' ' << e1.ss << ' ' << global << '\n';
            if (e1.ss != -1 && e1.ss == 0 && global != -1) ans[i] += dsu.size(global);

            if (d * d == K) break;

            global = -1;
            auto e2 = dfs(i, 0, -1, K / d);
            // cerr << i << ' ' << K / d << ' ' << e2.ff << ' ' << e2.ss << ' ' << global << '\n';
            if (e2.ss != -1 && e2.ss == 0 && global != -1) ans[i] += dsu.size(global);
        }
    }

    rep(i, N - 1) cout << ans[i] + dsu.size(i) - 1 << ' ';
    cout << ans[N - 1] + dsu.size(N - 1) - 1 << '\n';
}
