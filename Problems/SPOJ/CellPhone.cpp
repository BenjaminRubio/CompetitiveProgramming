#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

const double PI = acos(-1.0L);

typedef double T;
struct P
{
    T x, y;
    P() {}
    P(T x, T y) : x(x), y(y) {}
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }

    T norm2() const { return x * x + y * y; }
    double norm() const { return sqrt(norm2()); }
    double ang()
    {
        double a = atan2(y, x);
        if (a < 0) a += 2. * PI;
        return a;
    }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

double ang(double a)
{
    while (a >= 2. * PI) a -= 2. * PI;
    while (a < 0) a += 2. * PI;
    return a;
}

int N; double R;
vector<P> p;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    while (cin >> N >> R && N)
    {
        p.resize(N);
        rep(i, N) cin >> p[i];

        int ans = 1;
        rep(i, N)
        {
            int aux = 0;
            vector<pair<double, int>> s;
            rep(j, N)
            {
                double d = (p[j] - p[i]).norm();
                if (d <= 2. * R)
                {
                    double a = (p[j] - p[i]).ang();
                    double b = acos(d / (2. * R));
                    double a1 = ang(a - b), a2 = ang(a + b);
                    s.emplace_back(a1, 0); s.emplace_back(a2, 1);
                    if (a1 > a2) aux++;
                }
            }

            sort(s.begin(), s.end());
            for (auto &e : s)
            {
                if (e.ss == 1) aux--;
                if (e.ss == 0) aux++;
                ans = max(ans, aux);
            }
        }

        cout << "It is possible to cover " << ans << " points.\n";
    }
}