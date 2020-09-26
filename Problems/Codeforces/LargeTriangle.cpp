#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

struct P
{
    ll x, y;
    P() {}
    P(ll x, ll y) : x(x), y(y) {}

    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    ll operator^(const P &p) const { return x * p.y - y * p.x; }
    bool operator<(const P &p) const { return y < p.y; }
    double norm() const { return sqrt(x * x + y * y); }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }
ostream &operator<<(ostream &s, const P &p)
{
    return s << p.x << ' ' << p.y << '\n';
}

bool half(P &p) { return p.y > 0 || (p.y == 0 && p.x > 0); }

struct L
{
    P v; ll c;
    L(P p, P q) : v(q - p), c(v ^ p) {}
    ll side(P p) { return (v ^ p) - c; }
    double dist(P p) { return abs(side(p) / v.norm()); }
};

int N; ll S;
vector<pair<P, int>> p;
vector<int> I;
P a, b, c;

int main()
{
    cin >> N >> S; S *= 2ll;

    p.resize(N);
    rep(i, N) { cin >> p[i].ff; p[i].ss = i; }

    sort(p.begin(), p.end());

    I.resize(N);
    rep(i, N) I[p[i].ss] = i;

    vector<pair<P, pair<int, int>>> s;
    rep(i, N) rep(j, N) if (i != j)
        s.emplace_back(p[j].ff - p[i].ff, make_pair(p[i].ss, p[j].ss));

    sort(s.begin(), s.end(), [](auto &p1, auto &p2)
    {
        int h1 = half(p1.ff), h2 = half(p2.ff);
        return h1 != h2 ? h1 > h2 : (p1.ff ^ p2.ff) > 0;
    });

    bool flag = 0;
    for (auto &e : s)
    {
        int i = e.ss.ff, j = e.ss.ss;

        double B = e.ff.norm(); L ln(p[I[i]].ff, p[I[j]].ff);
        int l = max(I[i], I[j]) + 1, r = N;
        while (l < r)
        {
            int m = (l + r) >> 1;
            if (ln.dist(p[m].ff) > (S / B)) r = m;
            else l = m + 1;
        } l--;

        if (B * ln.dist(p[l].ff) == S)
        {
            a = p[I[i]].ff, b = p[I[j]].ff, c = p[l].ff;
            flag = 1; break;
        }

        swap(p[I[i]], p[I[j]]); swap(I[i], I[j]);
    }

    if (flag) cout << "Yes\n" << a << b << c;
    else cout << "No\n";
}