#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

#define ff first
#define ss second

const double PI = 3.141592653589793238462643383279502884L;;
const double EPS = 1e-20;

struct P
{
    double x, y, r;
    P() {}
    P(const P &p) : x(p.x), y(p.y), r(p.r) {}
    P(double x, double y) : x(x), y(y) {}

    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    bool operator==(const P &p) const { return (P(*this) - p).norm() < EPS; }
    bool operator<(const P &p) const
    {
        return x - p.x > EPS or (abs(x - p.x) < EPS && y - p.y > EPS);
    }

    double norm() { return sqrt(x * x + y * y); }
    double ang()
    {
        double a = atan2(y, x);
        if (a < 0) a += 2. * PI;
        return a;
    }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y >> p.r; }

int N;
map<P, P> m;

double ang(double a)
{
    while (a < 0) a += 2. * PI;
    while (a >= 2. * PI) a -= 2. * PI;
    return a;
}

bool crash(P &p, P &q)
{
    double d = (p - q).norm();
    if (d > 4.) return false;
    if (d <= 2.) return true;

    double A = acos(d / 4.);
    double pi = ang(p.r - (q - p).ang() - A);
    double qi = ang(q.r - (p - q).ang() - A);

    if (ang(abs(pi - qi)) <= 2. * A) return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    P p, p_;
    rep(i, N)
    {
        cin >> p; p.x *= 2, p.y *= 2;
        p_ = P((int)p.x, (int)p.y);
        if (m.count(p_))
        {
            cout << "crash\n"; return 0;
        }
        else m[p_] = p;
    }

    for (auto e : m) rep(dx, 7) rep(dy, 7) if (dx != 3 || dy != 3)
    {
        P c_ = P(e.ff.x + dx - 3, e.ff.y + dy - 3);
        if (m.count(c_) and crash(e.ss, m[c_]))
        {
            cout << "crash\n"; return 0;
        }
    }

    cout << "ok\n";
}