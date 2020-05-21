#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

const double EPS = 1e-6;

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
    T operator^(const P &p) const { return x * p.y - y * p.x; }
    T operator*(const P &p) const { return x * p.x + y * p.y; }
    bool operator<(const P &p) const
    {
        return p.x - x > EPS or (abs(x - p.x) < EPS && p.y - y > EPS);
    }

    T norm2() const { return x * x + y * y; }
    double norm() const { return sqrt(norm2()); }
    P unit() { return (*this) / norm(); }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }
ostream &operator<<(ostream &s, const P &p)
{
    return s << '(' << p.x << ", " << p.y << ')';
}

double turn(P &a, P &b, P &c) { return (b - a) ^ (c - a); }

double areaPolygonUnion(vector<vector<P>> &pol)
{
    double area = 0;
    rep(i, pol.size()) rep(j, pol[i].size())
    {
        int m = pol[i].size();
        P p1 = pol[i][j], p2 = pol[i][(j + 1) % m];

        vector<pair<double, int>> s; s.emplace_back(1., 0);

        rep(ii, pol.size()) if (ii != i) rep(jj, pol[ii].size())
        {
            int mm = pol[ii].size();
            P p3 = pol[ii][jj], p4 = pol[ii][(jj + 1) % mm];

            double t1 = turn(p1, p2, p3), t2 = turn(p1, p2, p4),
                   t3 = turn(p3, p4, p1), t4 = turn(p3, p4, p2);
            if (!t1 && !t2 && (p2 - p1) * (p4 - p3) > 0 && i < ii)
            {
                s.emplace_back((p3 - p1) * (p2 - p1) / (p2 - p1).norm2(), 1);
                s.emplace_back((p4 - p1) * (p2 - p1) / (p2 - p1).norm2(), -1);
            }
            if (t1 >= 0 && t2 < 0) s.emplace_back(t3 / (t3 - t4), 1);
            if (t1 < 0 && t2 >= 0) s.emplace_back(t3 / (t3 - t4), -1);
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
    
    return area * 0.125;
}

int N, M, K, Q, l, r, lev, x, y;
vector<P> p;
vector<vector<P>> pol;
double q, off, now;

void clipped(int i, int n, int m, int r, vector<P> &v)
{
    P p1 = p[i] + P(-1, -1) * (2 * r - 1), p2 = p[i] + P(-1, 1) * (2 * r - 1);
    P p3 = p[i] + P(1, -1) * (2 * r - 1), p4 = p[i] + P(1, 1) * (2 * r - 1);
    v[0] = P(max(0., min(2. * n, p2.x)), max(0., min(2. * m, p2.y)));
    v[1] = P(max(0., min(2. * n, p1.x)), max(0., min(2. * m, p1.y)));
    v[2] = P(max(0., min(2. * n, p3.x)), max(0., min(2. * m, p3.y)));
    v[3] = P(max(0., min(2. * n, p4.x)), max(0., min(2. * m, p4.y)));
}

int main()
{
    ios::sync_with_stdio(0);
    while (cin >> N >> M >> K && N)
    {
        p.resize(K);
        rep(i, K) cin >> p[i], p[i] = p[i] * 2 - P(1, 1);

        cin >> Q;
        pol.assign(K, vector<P>(4));
        rep(_, Q)
        {
            cin >> q;

            l = 2, r = 1e9;
            while (l < r)
            {
                int m = (l + r) / 2;

                rep(i, K) clipped(i, N, M, m, pol[i]);

                if (areaPolygonUnion(pol) - K > q - EPS) r = m;
                else l = m + 1;
            } lev = l;

            rep(i, K) clipped(i, N, M, lev - 1, pol[i]);
            off = areaPolygonUnion(pol) - K;
            // cerr << off << ' ';

            l = 1, r = N;
            while (l < r)
            {
                int m = (l + r) / 2;

                rep(i, K) clipped(i, m, M, lev, pol[i]);
                now = areaPolygonUnion(pol);
                rep(i, K) clipped(i, m, M, lev - 1, pol[i]);
                now -= areaPolygonUnion(pol);

                if (now + off > q - EPS) r = m;
                else l = m + 1;
            } x = l;

            rep(i, K) clipped(i, x - 1, M, lev, pol[i]);
            now = areaPolygonUnion(pol);
            rep(i, K) clipped(i, x - 1, M, lev - 1, pol[i]);
            now -= areaPolygonUnion(pol);
            off += now;
            // cerr << off << '\n';

            l = 1, r = M;
            while (l < r)
            {
                int m = (l + r) / 2;

                rep(i, K) clipped(i, x, m, lev, pol[i]);
                now = areaPolygonUnion(pol);
                rep(i, K) clipped(i, x - 1, m, lev, pol[i]);
                now -= areaPolygonUnion(pol);
                rep(i, K) clipped(i, x, m, lev - 1, pol[i]);
                now -= areaPolygonUnion(pol);
                rep(i, K) clipped(i, x - 1, m, lev - 1, pol[i]);
                now += areaPolygonUnion(pol);

                if (now + off > q - EPS) r = m;
                else l = m + 1;
            } y = l;

            cout << x << ' ' << y << '\n';
        }
        cout << "-\n";
    }
}