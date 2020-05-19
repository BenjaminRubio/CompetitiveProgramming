#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

const double PI = acos(-1.0L);
const double EPS = 1e-12;

struct P
{
    double x, y, z;
    P() {}
    P(double x, double y, double z) : x(x), y(y), z(z) {}

    P operator+(const P &p) const { return P(x + p.x, y + p.y, z + p.z); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y, z - p.z); }
    P operator*(const double &c) const { return P(x * c, y * c, z * c); }
    P operator/(const double &c) const { return P(x / c, y / c, z / c); }
    double operator*(const P &p) const { return x * p.x + y * p.y + z * p.z; }

    double norm() const { return sqrt(norm2()); }
    double norm2() const { return x * x + y * y + z * z; }
    P unit() { return (*this) / norm(); }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y >> p.z; }

P bary(P &A, P &B, P &C, double a, double b, double c)
{
    return (A * a + B * b + C * c) / (a + b + c);
}

P circum(P &A, P &B, P &C)
{
    double a = (B - C).norm2(), b = (C - A).norm2(), c = (A - B).norm2();
    return bary(A, B, C, a * (b + c - a), b * (c + a - b), c * (a + b - c));
}

double smallestEnclosingCircle(vector<P> &p)
{
    random_shuffle(p.begin(), p.end());
    P c = p[0]; double r = 0;
    int N = p.size();
    rep(i, N) if (i && (p[i] - c).norm() > r + EPS)
    {
        c = p[i]; r = 0;
        rep(j, i) if ((p[j] - c).norm() > r + EPS)
        {
            c = (p[i] + p[j]) * 0.5;
            r = (p[i] - c).norm();
            rep(k, j) if ((p[k] - c).norm() > r + EPS)
            {
                c = circum(p[i], p[j], p[k]);
                r = (p[k] - c).norm();
            }
        }
    }

    return r;
}

int N, M;
vector<P> c;
P n;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(10);

    cin >> N >> M;

    c.resize(N);
    rep(i, N) cin >> c[i];

    double ans = 0;
    rep(_, M)
    {
        cin >> n;

        vector<P> v;
        rep(i, N) v.push_back(c[i] - n.unit() * (n.unit() * c[i]));

        cout << smallestEnclosingCircle(v) << '\n';
    }
}