#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)

struct Point
{
    double x, y;

    Point operator-(Point &p)
    {
        return Point({x - p.x, y - p.y});
    }

    double cross(Point &p)
    {
        return x * p.y - y * p.x;
    }
};

int n;
double x_1, y_1, x_2, y_2;
vector<pair<Point, Point>> segments;

int sign(double x)
{
    if (x > 0)
        return 1;
    if (x < 0)
        return -1;
    return 0;
}

bool intersects(pair<Point, Point> &s1, pair<Point, Point> &s2)
{
    Point aux1 = s2.first - s1.first;
    Point aux2 = s2.second - s1.first;
    Point aux3 = s1.first - s2.first;
    Point aux4 = s1.second - s2.first;
    if (sign((s1.second - s1.first).cross(aux1)) != sign((s1.second - s1.first).cross(aux2)) &&
        sign((s2.second - s2.first).cross(aux3)) != sign((s2.second - s2.first).cross(aux4)))
        return true;
    return false;
}

int main()
{
    while (cin >> n)
    {
        if (n == 0)
            break;

        segments.resize(n);
        rep(i, n)
        {
            cin >> x_1 >> y_1 >> x_2 >> y_2;
            segments[i] = make_pair(Point({x_1, y_1}), Point({x_2, y_2}));
        }

        int count = 0;

        rep(i, n) repx(j, i + 1, n) repx(k, j + 1, n)
        {
            if (intersects(segments[i], segments[j]) &&
                intersects(segments[j], segments[k]) &&
                intersects(segments[i], segments[k]))
                count++;
        }

        cout << count << '\n';
    }
}