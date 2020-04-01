#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ss second
typedef long long ll;

struct P
{
    ll x, y, r;
    P() {}
    P(ll x, ll y) : x(x), y(y) {}

    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator*(const ll &c) const { return P(x * c, y * c); }
    P rot(){ return P(-y, x); }
    ll norm2() { return x * x + y * y; }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

struct HASH
{
    ll a, b, c;
    HASH(const P& p1, const P& p2)
    {
        a = p1.y - p2.y;
        b = p2.x - p1.x;
        c = p1.x * (p2.y - p1.y) - p1.y * (p2.x - p1.x);
        ll sgn = (a < 0 or (a == 0 and b < 0)) ? -1 : 1;
        ll g = __gcd(abs(a), __gcd(abs(b), abs(c))) * sgn;
        a /= g, b /= g, c /= g;
    }
    bool operator<(const HASH &h) const
    {
        return a < h.a or (a == h.a and (b < h.b or (b == h.b and c < h.c)));
    }
};

int N, M;
map<HASH, vector<ll>> Hr, Hl;
P C[1500];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    P p, q;
    rep(i, N)
    {
        cin >> p >> q; p = p * 2; q = q * 2;
        int l = min(p.x, q.x), r = max(p.x, q.x);
        HASH h(p, q);
        Hl[h].push_back(l); Hr[h].push_back(r);
    }

    for (auto &e : Hr) sort(e.ss.begin(), e.ss.end());
    for (auto &e : Hl) sort(e.ss.begin(), e.ss.end());

    rep(i, M) cin >> C[i] >> C[i].r;

    ll ans = 0;
    int l, r;
    rep(i, M) repx(j, i + 1, M)
        if (C[i].r == C[j].r and (C[j] - C[i]).norm2() > 4 * C[i].r * C[i].r)
    {
        P c = C[i] + C[j], d = (C[j] - C[i]).rot();
        HASH h(c, c + d);

        if (!Hr.count(h)) continue;

        ans += Hr[h].size();
        ans -= lower_bound(Hr[h].begin(), Hr[h].end(), c.x) - Hr[h].begin();
        ans -= Hl[h].end() - upper_bound(Hl[h].begin(), Hl[h].end(), c.x);
    }

    cout << ans << '\n';
}