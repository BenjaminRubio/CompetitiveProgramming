#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct P
{
    double x, y;
    P() {}
    P(double x, double y) : x(x), y(y) {}
    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator*(const double c) const { return P(x * c, y * c); }
    double operator^(const P &p) const { return x * p.y - y * p.x; }
    double operator*(const P &p) const { return x * p.x + y * p.y; }
    double norm2() { return x * x + y * y; }
    double norm() { return sqrt(x * x + y * y); }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }
ostream &operator<<(ostream &s, const P &p) { return s << p.x << '\n' << p.y; }

int N;
P a, b, c;

P calc(P a, P b, P c)
{
    if ((c - a) * (b - a) >= 0 && (c - b) * (a - b) >= 0)
        return a + (b - a) * (((b - a) * (c - a)) / (b - a).norm2());
    if ((c - a).norm() < (c - b).norm()) return a;
    return b;
}

int main()
{
    cout.setf(ios::fixed);
    cout.precision(4);

    while (cin >> c)
    {
        cin >> N;

        P ans; double m = DBL_MAX;
        cin >> b;
        rep(_, N)
        {
            a = b;
            cin >> b;

            P aux = calc(a, b, c);
            if ((c - aux).norm() < m)
            {
                m = (c - aux).norm();
                ans = aux;
            }
        }

        cout << ans << '\n';
    }
}