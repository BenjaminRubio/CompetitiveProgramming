#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

const double PI = 3.14159265358979323846;

struct Point
{
    int x, y;
    double norm()
    {
        return sqrt(x * x + y * y);
    }
    double ang()
    {
        double a = atan2(y, x);
        if (a < 0)
            a += 2.0 * PI;
        return a;
    }
};

int x, y;
double v, w;

int main()
{
    cin >> x >> y;
    cin >> v >> w;

    Point p = {x, y};
    double R = v / w;

    if (p.ang() && p.norm() > R)
    {
        double ang = PI * 0.5 - acos(R / p.norm()) + p.ang();
        cerr << ang << '\n';
        double d_ = sqrt(p.norm() * p.norm() - R * R);
        cout << d_ / v + ang / w << '\n';
    }
    else
    {
        double ang = PI * 0.5 - acos(p.norm() / R * 0.5);

        if (ang <= p.ang())
            cout << (p.ang() + ang) / w << '\n';
        else
            cout << 2.0 * p.ang() / w + (p.norm() - 2.0 * R * cos(PI * 0.5 - p.ang())) / v << '\n';
    }
}