#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct Point
{
    int x, y;
    Point operator-(Point &p)
    {
        return Point({x - p.x, y - p.y});
    }
    double dot(Point &p)
    {
        return x * p.x + y * p.y;
    }
    double norm()
    {
        return x * x + y * y;
    }
};

int n, x_r, y_r, x, y;
Point orig;
vector<Point> polygon;

int main()
{
    cout.setf(ios::fixed); cout.precision(3);

    while (cin >> n)
    {
        cin >> x_r >> y_r;
        orig = Point({x_r, y_r});

        polygon.resize(n);
        rep(i, n)
        {
            cin >> x >> y;
            polygon[i] = Point({x, y});
        }
        polygon.push_back(polygon[0]);

        double min_r = DBL_MAX;
        rep(i, n)
        {
            
            Point p1 = polygon[i];
            Point p2 = polygon[i + 1];
            Point aux = p2 - p1;
            double dot = (orig - p1).dot(aux) / sqrt(aux.norm());

            if (dot <= 0 || dot * dot >= aux.norm())
                min_r = min({min_r, sqrt((p1 - orig).norm()), sqrt((p2 - orig).norm())});
            else
                min_r = min(min_r, sqrt((orig - p1).norm() - dot * dot));
        }

        cout << min_r << '\n';
    }
}