#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

const double EPS = 1e-12;

typedef double T;
struct P
{
    T x, y;
    P() {}
    P(T x, T y) : x(x), y(y) {}

    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator*(const double &c) const { return P(x * c, y * c); }
    P operator/(const double &c) const { return P(x / c, y / c); }

    T norm2() const { return x * x + y * y; }
    double norm() const { return sqrt(norm2()); }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

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

int N;
vector<P> p;
double R;

int main()
{
    while (cin >> N && N)
    {
        p.resize(N);
        rep(i, N) cin >> p[i];

        cin >> R;

        double r = smallestEnclosingCircle(p);

        if (R >= r - EPS) cout << "The polygon can be packed in the circle.\n";
        else cout << "There is no way of packing that polygon.\n";
    }
}