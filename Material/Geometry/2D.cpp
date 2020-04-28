#include <bits/stdc++.h>
using namespace std;

const double PI = 3.141592653589793238462643383279502884L;
const double EPS = 1e-12;

// POINT 2D

struct P
{
    double x, y;
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
        return abs(x - p.x) < EPS and abs(y - p.y) < EPS;
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

double ang(double a)
{
    while (a >= 2. * PI) a -= 2. * PI;
    while (a < 0) a += 2. * PI;
    return a;
}

// Segments

bool parallel(P a, P b, P c, P d) { return abs((a - b) ^ (c - d)) < EPS; }

bool on_segment(P p, P a, P b)
{
    if (parallel(p, a, p, b) && (p - a) * (p - b) < 0) return true;
    return false;
}

bool do_intersect(P a, P b, P c, P d)
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

// Lines

P lines_intersection(P a, P b, P c, P d)
{
    b = b - a; d = c - d; c = c - a;
    assert((b * b) > EPS && (d * d) > EPS);
    return a + b * (c ^ d) / (b ^ d);
}

typedef long long ll;
struct HASH // Hashing for integer coordinates lines
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