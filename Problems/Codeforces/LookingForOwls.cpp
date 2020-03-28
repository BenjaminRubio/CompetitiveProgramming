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
typedef pair<P, P> S;

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
};


int N, M;
map<HASH, vector<P>> H;

int main()
{

}