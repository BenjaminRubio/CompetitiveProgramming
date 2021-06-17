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

const db PI = acos(-1.0);
const db EPS = 1e-8;

typedef ll T; struct P
{
    T x, y;
    P() {} P(T x, T y) : x(x), y(y) {}
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }

    T norm2() const { return x * x + y * y; }
    db norm() const { return sqrt(norm2()); }
    db ang()
    {
        db a = atan2(y, x);
        while (a < 0) a += 2. * PI;
        return a;
    }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

struct Event
{
    db a; ll d; int t, id;
    Event(db a, ll d, int t, int id) : a(a), d(d), t(t), id(id) {}
    bool operator<(const Event &e)
    {
        if (abs(a - e.a) > EPS) return a < e.a;
        if (t != e.t) return t < e.t;
        return d < e.d;
    }
};

int G, H;
vector<P> g;
vector<pair<P, ll>> h;

set<int> ans;
vector<vi> GG;
vi V, D, L, AP;

int rc = 0;
void dfs(int u, int p, int d)
{
    D[u] = L[u] = d;
    for (int v : GG[u]) if (v != p)
    {
        if (D[v] == -1)
        {
            dfs(v, u, d + 1);
            if ((p == -1 && ++rc == 2) || (p != -1 && L[v] >= d)) AP[u] = 1;
            L[u] = min(L[u], L[v]); 
        }
        else if (D[v] < d) L[u] = min(L[u], D[v]);
    }
}

void dfs_(int u, int p)
{
    V[u] = 1; ans.insert(u);
    if (!AP[u]) for (int v : GG[u]) if (v != p && !V[v]) dfs_(v, u);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> G >> H;

    g.resize(G);
    rep(i, G) cin >> g[i];

    h.resize(H);
    rep(i, H) cin >> h[i].ff >> h[i].ss;

    GG.assign(G, {});
    rep(i, G)
    {
        vector<Event> E;
        rep(j, G) if (i != j)
        {
            db a = (g[j] - g[i]).ang(); ll d = (g[j] - g[i]).norm2();
            E.eb(a, d, 1, j);
        }

        multiset<ll> ss;
        rep(j, H)
        {
            db a = (h[j].ff - g[i]).ang(); ll d = (h[j].ff - g[i]).norm2();
            db da = asin(h[j].ss / sqrt(d));
            d -= h[j].ss * h[j].ss;

            db a1 = a - da, a2 = a + da;
            while (a1 < 0) a1 += 2. * PI;
            while (a2 >= 2 * PI) a2 -= 2. * PI;

            if (a1 - EPS > a2) ss.insert(d);
            E.eb(a1, d, 0, j), E.eb(a2, d, 2, j);
        }

        sort(E.begin(), E.end());

        db al = -1;
        for (auto &e : E)
        {
            if (e.t == 0) ss.insert(e.d);
            if (e.t == 2) ss.erase(ss.find(e.d));
            if (e.t == 1 && abs(al - e.a) > EPS)
            {
                if (ss.empty() || *ss.begin() > e.d) GG[i].pb(e.id);
                al = e.a;
            }
        }
    }

    D.assign(G, -1), L.assign(G, -1), AP.assign(G, 0);
    dfs(G - 1, -1, 0);

    ans = {}; V.assign(G, 0); V[G - 1] = 1;
    for (int v : GG[G - 1]) dfs_(v, -G - 1);

    bool first = 1;
    for (int x : ans)
    {
        if (!first) cout << ' ';
        cout << x + 1; first = 0;
    }
    cout << '\n';
}
