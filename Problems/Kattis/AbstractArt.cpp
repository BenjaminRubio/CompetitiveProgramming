#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

typedef double T;  // can be integer
struct P
{
    T x, y;
    P() {}
    P(T x, T y) : x(x), y(y) {}

    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator*(const double &c) const { return P(x * c, y * c); }
    P operator/(const double &c) const { return P(x / c, y / c); }
    T operator^(const P &p) const { return x * p.y - y * p.x; }
    T operator*(const P &p) const { return x * p.x + y * p.y; }

    T norm2() const { return x * x + y * y; }
    double norm() const { return sqrt(norm2()); }

    P unit() { return (*this) / (*this).norm(); }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

double areaPolygon(vector<P> &p)
{
    double ans = 0; int n = p.size();
    rep(i, n) ans += p[i] ^ p[(i + 1) % n];
    return ans / 2.;
}

double turn(P &a, P &b, P &c) { return (b - a) ^ (c - a); }

int N, m, mm;
vector<vector<P>> pol;
P p1, p2, p3, p4;
double t1, t2, t3, t4;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(10);

    cin >> N;

    double paint = 0;

    pol.resize(N);
    rep(i, N)
    {
        cin >> m;
        pol[i].resize(m);
        rep(j, m) cin >> pol[i][j];

        double a = areaPolygon(pol[i]);
        if (a < 0) reverse(pol[i].begin(), pol[i].end());
        paint += abs(a);
    }

    double area = 0;
    rep(i, N) rep(j, pol[i].size())
    {
        m = pol[i].size();
        p1 = pol[i][j], p2 = pol[i][(j + 1) % m];

        vector<pair<double, int>> s; s.emplace_back(1., 0);

        rep(ii, N) if (ii != i) rep(jj, pol[ii].size())
        {
            mm = pol[ii].size();
            p3 = pol[ii][jj], p4 = pol[ii][(jj + 1) % mm];

            t1 = turn(p1, p2, p3), t2 = turn(p1, p2, p4);
            t3 = turn(p3, p4, p1), t4 = turn(p3, p4, p2);
            if (!t1 && !t2 && (p2 - p1) * (p4 - p3) > 0 && i > ii)
            {
                s.emplace_back((p3 - p1) * (p2 - p1).unit(), 1);
                s.emplace_back((p4 - p1) * (p2 - p1).unit(), -1);
            }
            else if (t1 >= 0 && t2 < 0) s.emplace_back(t3 / (t3 - t4), 1);
            else if (t1 < 0 && t2 >= 0) s.emplace_back(t3 / (t3 - t4), -1);
        }

        sort(s.begin(), s.end());

        int c = 0;
        double last = 0, f = 0;
        for (auto e : s)
        {
            double now = min(1., max(0., e.ff));
            if (c == 0) f += now - last;
            c += e.ss, last = now;
        }

        area += (p1 ^ p2) * f;
    }

    cout << paint << ' ' << area / 2. << '\n';
}