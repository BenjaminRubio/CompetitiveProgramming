#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-12;

struct P
{
    double x, y;
    P() {}
    P(const P &p) : x(p.x), y(p.y) {}
    P(double x, double y) : x(x), y(y) {}
    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator*(const double &c) const { return P(x * c, y * c); }
    P operator/(const double &c) const { return P(x / c, y / c); }
    double operator^(const P &p) const { return x * p.y - y * p.x; }
    double operator*(const P &p) const { return x * p.x + y * p.y; }
    bool operator==(const P &p) const { return (P(*this) - p).norm() < EPS; }
    bool operator<(const P &p) const
    {
        return x < p.x or (x == p.x and y < p.y);
    }
    double norm() { return sqrt(x * x + y * y); }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }
ostream &operator<<(ostream &s, const P &p) { return s << p.x << ' ' << p.y; }

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

P lines_intersection(P a, P b, P c, P d)
{
    b = b - a; d = c - d; c = c - a;
    assert((b * b) > EPS && (d * d) > EPS);
    return a + b * (c ^ d) / (b ^ d);
}

int n;
P a, b, c, d;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);

    cin >> n;
    while (n--)
    {
        cin >> a >> b >> c >> d;
        if (!do_intersect(a, b, c, d)) cout << "none" << '\n';
        else if (parallel(a, b, c, d))
        {
            if (a == b) cout << a << '\n';
            else if (c == d) cout << c << '\n';
            else
            {
                vector<P> v = {a, b, c, d}; sort(v.begin(), v.end());
                if (v[1] == v[2]) cout << v[1] << '\n';
                else cout << v[1] << ' ' << v[2] << '\n';
            }
        }
        else cout << lines_intersection(a, b, c, d) << '\n';
    }
}