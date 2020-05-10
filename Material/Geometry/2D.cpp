#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

const double PI = 3.141592653589793238462643383279502884L;
const double EPS = 1e-12;

// POINT 2D

typedef double T;  // can be integer
struct P
{
    T x, y;
    P() {}
    P(T x, T y) : x(x), y(y) {}

    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator*(const double &c) const { return P(x * c, y * c); }
    P operator/(const double &c) const { return P(x / c, y / c); }
    T operator^(const P &p) const { return x * p.y - y * p.x; }
    T operator*(const P &p) const { return x * p.x + y * p.y; }
    bool operator==(const P &p) const
    {
        return abs(x - p.x) + abs(y - p.y) < EPS;
    }
    bool operator<(const P &p) const
    {
        return x - p.x > EPS or (abs(x - p.x) < EPS && y - p.y > EPS);
    }

    T norm2() const { return x * x + y * y; }
    double norm() const { return sqrt(norm2()); }
    double ang()
    {
        double a = atan2(y, x);
        if (a < 0) a += 2. * PI;
        return a;
    }
    P unit() { return (*this) / (*this).norm(); }
    P perp() { return P(-y, x); }
    P rot(P r) { return P((*this) ^ r, (*this) * r); }
    P rot(double a){ return rot(P(sin(a), cos(a))); }
};
P polar(double r, double a) { return P(r * cos(a), r * sin(a)); }
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }
ostream &operator<<(ostream &s, const P &p)
{
    return s << '(' << p.x << ", " << p.y << ')';
}

double ang(double a)
{
    while (a >= 2. * PI) a -= 2. * PI;
    while (a < 0) a += 2. * PI;
    return a;
}

int sgn(T x) { return (0 < x) - (x < 0); }

int turn(P &a, P &b, P &c) { return sgn((b - a) ^ (c - a)); }

bool isConvex(vector<P> p)
{
    int n = p.size();
    bool hasPos = false, hasNeg = false, hasCol = false;
    rep(i, n)
    {
        int o = turn(p[i], p[(i + 1) % n], p[(i + 2) % n]);
        if (o > 0) hasPos = true;
        if (o < 0) hasNeg = true;
        if (o == 0) hasCol = true;
    }
    return !(hasPos && hasNeg) && !hasCol;
}

bool half(P &p) { return p.y > 0 || (p.y == 0 && p.x > 0); }

void polarSort(vector<P> &v)
{
    sort(v.begin(), v.end(), [](P &p1, P &p2)
    {
        int h1 = half(p1), h2 = half(p2);
        return h1 != h2 ? h1 > h2 : (p1 ^ p2) > 0;
    });
}

// LINE

struct L
{
    P v; T c;
    L(P v, T c) : v(v), c(c) {}
    L(T a, T b, T c) : v(P(b, -a)), c(c) {}
    L(P p, P q) : v(q - p), c(v ^ p) {}

    T side(P p) { return (v ^ p) - c; }
    double dist(P p) { return abs(side(p) / v.norm()); }
    double dist2(P p) { return side(p) * side(p) / (double)v.norm2(); }
    L perp(P p) { return L(p, p + v.perp()); }
    L translate(P t) { return L(v, c + (v ^ t)); }
    P proj(P p) { return p - v.perp() * side(p) / v.norm2(); }
    P refl(P p) { return p - v.perp() * 2 * side(p) / v.norm2(); }
};

bool parallel(L l1, L l2) {return !(l1.v ^ l2.v); }

// only if not parallel
P inter(L l1, L l2) { return (l2.v * l1.c - l1.v * l2.c) / (l1.v ^ l2.v); }

L bisector(L l1, L l2, bool in)
{
    double sign = in ? 1 : -1;
    return L(l2.v / l2.v.norm() + l1.v / l1.v.norm() * sign,
             l2.c / l2.v.norm() + l1.c / l1.v.norm() * sign);
}

typedef long long ll;
struct HASH // Hashing for integer coordinates lines
{
    ll a, b, c;
    HASH(const P &p1, const P &p2)
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

// SEGMENT

bool parallel(P &a, P &b, P &c, P &d) { return abs((a - b) ^ (c - d)) < EPS; }

bool on_segment(P &p, P &a, P &b)
{
    if (parallel(p, a, p, b) && (p - a) * (p - b) < 0) return true;
    return false;
}

bool do_intersect(P &a, P &b, P &c, P &d)
{
    if (a == c || a == d || b == c || b == d) return true;
    if (a == b && c == d) return false;
    if (a == b) return on_segment(a, c, d);
    if (c == d) return on_segment(c, a, b);
    if (parallel(a, b, c, d) && parallel(a, c, b, d) && parallel(a, d, b, c))
    {
        if (on_segment(a, c, d) || on_segment(b, c, d) ||
            on_segment(c, a, b) || on_segment(d, a, b)) return true;
        return false;
    }
    if (((a - b) ^ (a - c)) * ((a - b) ^ (a - d)) > 0) return false;
    if (((c - d) ^ (c - a)) * ((c - d) ^ (c - b)) > 0) return false;
    return true;
}
