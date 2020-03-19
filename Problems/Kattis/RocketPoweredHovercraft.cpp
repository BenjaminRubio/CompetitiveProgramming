#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

const double PI = 3.14159265358979323846;

struct Point
{
    double x, y;
    Point operator-(const Point &p) const
    {
        return {x - p.x, y - p.y};
    }
    double norm()
    {
        return sqrt(x * x + y * y);
    }
    double ang()
    {
        double a = atan2(y, x);
        if (a < 0) a += 2.0 * PI;
        return a;
    }
};

double ang(double a)
{
    if (a < 0) return a + 2. * PI;
    if (a >= 2. * PI) return a - 2. * PI;
    return a;
}

double x, y, v, w, R;
Point p;

double calc(double a)
{
    Point c = {R * cos(a + PI / 2.), R * sin(a + PI / 2.)};
    double d = (p - c).norm();
    double b = ang((p - c).ang() - acos(R / d) + PI / 2. - a);
    double x = sin(acos(R / d)) * d;
    if (R > d) return 1e9;
    double a_ = (a > PI) ? 2. * PI - a : a;
    return a_ / w + b / w + x / v;
}

int main()
{
    cin >> x >> y; y = abs(y);
    cin >> v >> w;

    p = {x, y};
    R = v / w;

    double a = p.ang() - PI / 2.;
    double l = a, r = p.ang();

    rep(_, 1000)
    {
        double t = (r - l) / 3.;
        double cl = calc(ang(l + t)), cr = calc(ang(r - t));
        if (cr < cl) l = l + t;
        else if (cl < cr) r = r - t;
        else l = l + t;
    }

    cout.precision(12);
    cout << calc(ang((l + r) / 2.)) << '\n';
}