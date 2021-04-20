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
    P operator/(const double &c) const { return P(x / c, y / c); }

    T norm2() const { return x * x + y * y; }
    double norm() const { return sqrt(norm2()); }
    P unit() { return (*this) / norm(); }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

const double EPS = 1e-10;

int N, M;
vector<P> U, V;

double f(P A, P B, P C, P D, double t)
{
    P p1 = A * (1 - t) + B * t;
    P p2 = C * (1 - t) + D * t;
    return (p2 - p1).norm();
}

int main()
{
    cout.setf(ios::fixed);
    cout.precision(10);

    cin >> N;
    U.resize(N); rep(i, N) cin >> U[i];
    cin >> M;
    V.resize(M); rep(i, M) cin >> V[i];

    double ans = DBL_MAX;
    int i = 0, j = 0;
    while (i < (N - 1) && j < (M - 1))
    {
        P A = U[i], B = U[i + 1], C = V[j], D = V[j + 1];

        double M = min((B - A).norm(), (D - C).norm());
        B = A + (B - A).unit() * M;
        D = C + (D - C).unit() * M;

        double l = 0, r = 1;
        rep(_, 100)
        {
            double t = (r - l) / 3, m1 = l + t, m2 = r - t;
            double f1 = f(A, B, C, D, m1), f2 = f(A, B, C, D, m2);

            if (f1 <= f2) r = m2;
            if (f1 >= f2) l = m1;
        }

        ans = min(ans, f(A, B, C, D, (l + r) / 2));

        i++, j++;
        if ((U[i] - B).norm() > EPS) U[--i] = B;
        if ((V[j] - D).norm() > EPS) V[--j] = D;
    }

    cout << ans << '\n';
}