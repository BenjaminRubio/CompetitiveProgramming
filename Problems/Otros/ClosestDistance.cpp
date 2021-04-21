#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

typedef double T; struct P
{
    T x, y;
    P() {} P(T x, T y) : x(x), y(y) {}
    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator*(const double &c) const { return P(x * c, y * c); }

    T norm2() const { return x * x + y * y; }
    double norm() const { return sqrt(norm2()); }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

int tt;
P A, B, C, D;

double f(double t)
{
    P p1 = A * (1 - t) + B * t;
    P p2 = C * (1 - t) + D * t;
    return (p2 - p1).norm();
}

int main()
{
    cout.setf(ios::fixed);
    cout.precision(10);

    cin >> tt;
    rep(t, tt)
    {
        cout << "Case " << t + 1 << ": ";

        cin >> A >> B >> C >> D;

        double l = 0, r = 1;
        rep(_, 100)
        {
            double t = (r - l) / 3, m1 = l + t, m2 = r - t;
            double f1 = f(m1), f2 = f(m2);
            if (f1 <= f2) r = m2;
            if (f1 >= f2) l = m1;
        }

        cout << f((l + r) / 2) << '\n';
    }
}