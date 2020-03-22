#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ff first
#define ss second

const long double PI = 3.141592653589793238462643383279502884L;

struct P
{
    long double x, y;
    P() {}
    P(long double x, long double y) : x(x), y(y) {}
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    long double norm() { return sqrt(x * x + y * y); }
    long double ang()
    {
        long double a = atan2(y, x);
        if (a < 0) a += 2.0 * PI;
        return a;
    }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

int N;
vector<P> c;
vector<long double> r;
vector<pair<long double, bool>> v;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(12);

    cin >> N;

    c.resize(N); r.resize(N);
    rep(i, N) cin >> c[i] >> r[i];

    int t = 0;
    rep(i, N) rep(j, N) if (i != j)
    {
        long double a = (c[j] - c[i]).ang();
        long double d = asin((r[j] + r[i]) / (c[j] - c[i]).norm());

        if (a + d >= 2. * PI)
        {
            t++;
            v.emplace_back(a - d, 1);
            v.emplace_back(a + d - 2. * PI, 0);
        }
        else if (a - d < 0)
        {
            t++;
            v.emplace_back(a - d + 2. * PI, 1);
            v.emplace_back(a + d, 0);
        }
        else 
        {
            v.emplace_back(a - d, 1);
            v.emplace_back(a + d, 0);
        }
    }

    sort(v.begin(), v.end());

    long double l = 0, ans = 0;
    for (auto e : v)
    {
        if (t == 0) ans = max(ans, e.ff - l);
        if (e.ss) t++;
        else t--;
        l = e.ff;
    }

    cout << ans << '\n';
}