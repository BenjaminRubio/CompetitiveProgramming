#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

const double PI = 3.141592653589793238462643383279502884L;;
const double EPS = 1e-12;

struct P
{
    double x, y;
    P() {}
    P(double x, double y) : x(x), y(y) {}
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    double norm() { return sqrt(x * x + y * y); }
    double norm2() { return x * x + y * y; }
    double ang() { return atan2(y, x); }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

double ang(double a)
{
    while (a >= 2. * PI) a -= 2. * PI;
    while (a < 0) a += 2. * PI;
    return a;
}

int N;
P p;
double R, T, v;
vector<P> C;
vector<double> r;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(10);

    cin >> p >> v >> T;
    R = v * T;

    cin >> N;
    C.resize(N); r.resize(N);
    rep(i, N) cin >> C[i] >> r[i];
    rep(i, N) C[i] = C[i] - p;

    int cnt = 0;
    bool done = false;
    vector<pair<double, bool>> v;
    rep(i, N)
    {
        double a = C[i].ang(), d;
        if (C[i].norm() > R + r[i]) continue;
        if (r[i] > C[i].norm() - EPS) done = true;
        if (C[i].norm2() <= R * R + r[i] * r[i])
            d = asin(r[i] / C[i].norm());
        else d = acos((R * R + C[i].norm2() - r[i] * r[i]) / (2 * R * C[i].norm()));
        if (ang(a - d) > ang(a + d)) cnt++;
        v.emplace_back(ang(a - d), 0);
        v.emplace_back(ang(a + d), 1);
    }
    if (done) { cout << 1. << '\n'; return 0; }

    sort(v.begin(), v.end());

    double ans = 0, l = 0;
    for (auto &e : v)
    {
        if (cnt) ans += e.first - l;
        if (e.second) cnt--;
        else cnt++;
        l = e.first;
    }
    if (cnt) ans += 2. * PI - l;

    cout << ans / (2. * PI) << '\n';
}