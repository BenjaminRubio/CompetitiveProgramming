#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second
typedef long long ll;

const double PI = 3.141592653589793238462643383279502884L;;
const double EPS = 1e-12;

struct P
{
    double x, y, r;
    P() {}
    P(double x, double y) : x(x), y(y) {}

    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator*(const double &c) const { return P(x * c, y * c); }
    P operator/(const double &c) const { return P(x / c, y / c); }
    double operator^(const P &p) const { return x * p.y - y * p.x; }
    double operator*(const P &p) const { return x * p.x + y * p.y; }
    bool operator==(const P &p) const
    {
        return abs(x - p.x) < EPS and abs(y - p.y) < EPS and r == p.r;
    }
    bool operator<(const P &p) const
    {
        return x - p.x > EPS or (abs(x - p.x) < EPS && y - p.y > EPS);
    }

    double norm() { return sqrt(x * x + y * y); }
    double norm2() { return x * x + y * y; }
    double ang()
    {
        double a = atan2(y, x);
        if (a < 0) a += 2. * PI;
        return a;
    }
    P unit() { return (*this) / (*this).norm(); }
    P rot(P r){ return P((*this) ^ r, (*this) * r); }
    P rot(double a){ return rot(P(sin(a), cos(a))); }
};
P polar(double r, double a) { return P(r * cos(a), r * sin(a)); }
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }
ostream &operator<<(ostream &s, const P &p) { return s << p.x << ' ' << p.y; }

typedef pair<P, P> S;

int n, m;
vector<S> s;
set<P> p;

int main()
{
    cin >> n >> m;

    s.resize(n);
    rep(i, n) cin >> s[i].ff >> s[i].ss;

    P pt;
    rep(i, m) { cin >> pt >> pt.r; p.insert(pt); }

    ll ans = 0;
    for (P c : p) rep(i, n)
    {
        // cerr << "c: " << c << '\n';
        P p1 = s[i].ff, p2 = s[i].ss;
        if ((c - p1) * (p2 - p1) >= 0 and (c - p2) * (p1 - p2) >= 0)
        {
            P p3 = p1 + (p2 - p1).unit() * ((c - p1) * (p2 - p1).unit());
            double d = abs(((c - p1) ^ (p2 - p1).unit()));

            if (d <= c.r) continue;

            P c_ = c + (p3 - c).unit() * 2. * d;
            c_.r = c.r;
            // cerr << "p3: " << p3 << ", c_: " << c_ << '\n';
            if (p.count(c_)) ans++;
        }
    }

    cout << ans / 2 << '\n';
}