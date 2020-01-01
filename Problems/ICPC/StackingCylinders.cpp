#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct Point
{
    double x, y;

    double dist(Point &p)
    {
        double d2 = (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
        return sqrt(d2);
    }
};

Point combine(Point &p1, Point &p2)
{
    double dx, dy;
    double ang = acos(p1.dist(p2) / 4.0);
    double h = 2.0 * sin(ang);
    ang = atan2(abs(p1.y - p2.y), abs(p1.x - p2.x));

    if (p1.y == p2.y)
    {
        dx = 0.0;
        dy = h;
    }
    else if (p1.y > p2.y)
    {
        dx = h * sin(ang);
        dy = h * cos(ang);
    }
    else
    {
        dx = -1.0 * h * sin(ang);
        dy = h * cos(ang);
    }

    return Point({(p1.x + p2.x) / 2.0 + dx, (p1.y + p2.y) / 2.0 + dy});
}

int n;
double x, y;
vector<double> xs;
vector<vector<Point>> floors;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(4);

    while (cin >> n)
    {
        floors.clear();
        xs.clear();
        if (n == 0)
            break;

        floors.resize(n);
        xs.resize(n);
        rep(i, n) cin >> xs[i];
        sort(xs.begin(), xs.end());
        rep(i, n)
            floors[0]
                .push_back(Point({xs[i], 1.0}));

        rep(i, n - 1) rep(j, n - i - 1)
            floors[i + 1]
                .push_back(combine(floors[i][j], floors[i][j + 1]));

        cout << floors[n - 1][0].x << ' ' << floors[n - 1][0].y << '\n';
    }
}