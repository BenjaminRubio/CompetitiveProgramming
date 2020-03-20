#include <bits/stdc++.h>
using namespace std;

const double PI = 3.14159265358979323846;

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
    bool operator==(const P &p) const { return x == p.x && y == p.y; }
    bool operator<(const P &p) const
    {
        return x < p.x or (x == p.x and y < p.y);
    }
    double norm() { return sqrt(x * x + y * y); }
    double norm2() { return x * x + y * y; }
    double ang()
    {
        double a = atan2(y, x);
        if (a < 0) a += 2.0 * PI;
        return a;
    }
};
P polar(double r, double a) { return P(r * cos(a), r * sin(a)); }
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }
ostream &operator<<(ostream &s, P &p) { return s << p.x << ' ' << p.y; }

// Segments

double point_seg_dist(P &p, P &a, P &b)
{
    if ((p - a) * (b - a) >= 0 && (p - b) * (a - b) >= 0)
        return abs(p ^ (b - a));
    return min((p - a).norm(), (p - b).norm());
}

int sgn(double x) { return (x < 0) ? -1 : ((x > 0) ? 1 : 0); }
bool intersect(P &a, P &b, P &c, P &d) // seg seg intersection
{
    return sgn((c - a) ^ (b - a)) * sgn((d - a) ^ (b - a)) <= 0 &&
           sgn((a - c) ^ (d - c)) * sgn((b - c) ^ (d - c)) <= 0;
}

double seg_seg_dist(P &a, P &b, P &c, P &d)
{
    if (intersect(a, b, c, d)) return 0;
    return min({(a - c).norm(), (a - d).norm(), 
                (b - c).norm(), (b - d).norm()});
}

double point_line_dist(P &p, P &a, P &b)
{
    return (abs((b - a) ^ (p - a))) / (b - a).norm();
}