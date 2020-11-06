#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

const long double EPS = 1e-15;

typedef long double T;
struct P
{
    T x, y;
    P() {}
    P(T x, T y) : x(x), y(y) {}

    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator*(const double &c) const { return P(x * c, y * c); }
    T operator^(const P &p) const { return x * p.y - y * p.x; }
    T operator*(const P &p) const { return x * p.x + y * p.y; }

    T norm2() const { return x * x + y * y; }
    P perp() { return P(y, -x); }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }
ostream &operator<<(ostream &s, const P &p)
{
    return s << '(' << p.x << ", " << p.y << ')';
}

double turn(P &a, P &b, P &c) { return (b - a) ^ (c - a); }

bool inDisk(P &a, P &b, P &p) { return (a - p) * (b - p) <= 0; }

bool onSeg(P &a, P &b, P &p)
{
    return abs(turn(a, b, p)) < EPS && inDisk(a, b, p); 
}

bool propInt(P &a, P &b, P &c, P &d)
{
    double ta = turn(c, d, a), tb = turn(c, d, b),
           tc = turn(a, b, c), td = turn(a, b, d);
    return (ta * tb < 0 && tc * td < 0);
}

bool inter(P &a, P &b, P &c, P &d)
{
    if (propInt(a, b, c, d) || onSeg(c, d, a) || onSeg(c, d, b) || 
        onSeg(a, b, c)|| onSeg(a, b, d)) return 1;
    return 0;
}

int N, M; P t, a, b;
vector<pair<P, P>> W, X;

int main()
{
    cin >> M >> N >> t;

    W.resize(M); X.resize(N);
    rep(i, M) cin >> W[i].ff >> W[i].ss;
    rep(i, N) cin >> X[i].ff >> X[i].ss;

    rep(i, N)
    {
        a = X[i].ff, b = X[i].ss;
        b = a + (b - a).perp();

        bool vis = (turn(a, b, t) > -EPS && (t - a).norm2() <= (b - a).norm2() + EPS);
        if (vis) rep(j, M) if (inter(a, t, W[j].ff, W[j].ss)) vis = 0;
        if (vis) rep(j, N) if (i != j && onSeg(a, t, X[j].ff)) vis = 0;
        
        if (vis) cout << "visible\n";
        else cout << "not visible\n";
    }
}