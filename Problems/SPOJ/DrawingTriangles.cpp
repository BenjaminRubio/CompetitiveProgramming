#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

const double EPS = 1e-10;
const double PI = 3.141592653589793238462643383279502884L;

struct P
{
    double x, y;
    P() {}
    P(const P &p) : x(p.x), y(p.y) {}
    P(double x, double y) : x(x), y(y) {}
    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator*(const double &c) const { return P(x * c, y * c); }
    double operator^(const P &p) const { return x * p.y - y * p.x; }
    double operator*(const P &p) const { return x * p.x + y * p.y; }
    P rot(P r){ return P((*this) ^ r, (*this) * r); }
    double norm() { return sqrt(x * x + y * y); }
    double ang() { return atan2(y, x); }
    bool operator<(const P &p) const
    {
        return x - p.x > EPS or (abs(x - p.x) < EPS && y - p.y > EPS);
    }
};
P polar(double r, double a) { return P(r * cos(a), r * sin(a)); }
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

int N, x, y;
vector<P> p(1000);
set<P> s;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    while (cin >> N)
    {
        s.clear();

        rep(i, N)
        {
            cin >> p[i];
            s.insert(p[i]);
        }

        double L0 = (p[1] - p[0]).norm();
        double L1 = (p[2] - p[0]).norm();
        double L2 = (p[2] - p[1]).norm();
        double A = (p[2] - p[0]).ang() - (p[1] - p[0]).ang();
        P rA(sin(A), cos(A));      // rotate vector  A
		P rA_(sin(-A), cos(-A));   // rotate vector -A
        double r = L1 / L0;

        int ans = 0;
        rep(i, N) rep(j, N) if (i != j)
        {
            double l = (p[j] - p[i]).norm();

            ans += s.count((p[j] - p[i]).rot(rA) * r + p[i]);
            ans += s.count((p[j] - p[i]).rot(rA_) * r + p[i]);
        }

        if (abs(L0 - L1) < EPS || abs(L1 - L2) < EPS || abs(L2 - L0) < EPS)
            cout << ans / 2 << '\n';
        else cout << ans << '\n';
    }
}