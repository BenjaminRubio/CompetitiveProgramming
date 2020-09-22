#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define mp make_pair
#define ff first
#define ss second

const double PI = acos(-1.0L);

typedef int T;
struct P
{
    T x, y;
    P() {}
    P(T x, T y) : x(x), y(y) {}
    T operator^(const P &p) const { return x * p.y - y * p.x; }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    bool operator<(const P &p) const { return y < p.y || (y == p.y && x < p.x); }
    bool operator==(const P &p) const { return x == p.x && y == p.y; }
    double norm() const { return sqrt(x * x + y * y); }
    double ang()
    {
        double a = atan2(y, x);
        if (a < 0) a += 2. * PI;
        return a;
    }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

struct L
{
    P v; T c;
    L(P p, P q) : v(q - p), c(v ^ p) {}

    T side(P p) { return (v ^ p) - c; }
    double dist(P p) { return abs(side(p) / v.norm()); }
};

int N;
P p[2000], p_[2000];
int I[2000];
vector<pair<double, pair<int, int>>> s;
P a, b;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cout.setf(ios::fixed);
    cout.precision(1);

    while (cin >> N && N)
    {
        s.clear();
        rep(i, N) cin >> p[i];

        sort(p, p + N);
        rep(i, N) I[i] = i, p_[i] = p[i];

        rep(i, N) repx(j, i + 1, N)
            s.emplace_back((p[j] - p[i]).ang(), mp(i, j));

        sort(s.begin(), s.end());

        double m = 1e10, M = 0, base;
        for (auto &e : s)
        {
            int i = e.ss.ff, j = e.ss.ss; a = p_[i], b = p_[j];
            base = (b - a).norm(); L ln(a, b);
            M = max(M, base * ln.dist(p[N - 1]));
            swap(p[I[i]], p[I[j]]); swap(I[i], I[j]);

            int l = I[i];
            while (l >= 0 && (p[l] == a || p[l] == b)) l--;
            if (l >= 0) m = min(m, base * ln.dist(p[l]));
        }

        cout << m * 0.5 << ' ' << M * 0.5 << '\n';
    }
}