#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct Point
{
    double x, y;
    Point operator-(const Point &p) const
    {
        return {x - p.x, y - p.y};
    }
    Point operator+(const Point &p) const
    {
        return {x + p.x, y + p.y};
    }
    Point operator*(double c) const
    {
        return {x * c, y * c};
    }
    Point unit() const
    {
        return {x / norm(), y / norm()};
    }
    double norm() const
    {
        return sqrt(x * x + y * y);
    }
};

int n, m;
double x, y;
vector<Point> w1, w2;

double ternary_search(double l, double r, Point &p1, Point &p2, Point &d1, Point &d2)
{
    rep(t, 100)
    {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = -1.0 * ((p2 + (d2 * m1)) - (p1 + (d1 * m1))).norm();
        double f2 = -1.0 * ((p2 + (d2 * m2)) - (p1 + (d1 * m2))).norm();
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return ((p2 + (d2 * l)) - (p1 + (d1 * l))).norm();
}

int main()
{
    cin >> n;
    w1.resize(n);
    rep(i, n)
    {
        cin >> x >> y;
        w1[i] = {x, y};
    }

    cin >> m;
    w2.resize(m);
    rep(i, m)
    {
        cin >> x >> y;
        w2[i] = {x, y};
    }

    int i = 1;
    int j = 1;
    Point p1 = w1[0];
    Point p2 = w2[0];
    double ans = DBL_MAX;
    while (i < n && j < m)
    {
        double n1 = (w1[i] - p1).norm();
        double n2 = (w2[j] - p2).norm();
        Point d1 = (w1[i] - p1).unit();
        Point d2 = (w2[j] - p2).unit();
        ans = min(ans, ternary_search(0, min(n1, n2), p1, p2, d1, d2));
        if (n1 > n2)
        {
            p2 = w2[j++];
            p1 = (p1 + (d1 * n2));
        }
        else if (n2 > n1)
        {
            p1 = w1[i++];
            p2 = (p2 + (d2 * n1));
        }
        else
        {
            p1 = w1[i++];
            p2 = w2[j++];
        }
    }

    cout << ans << '\n';
}