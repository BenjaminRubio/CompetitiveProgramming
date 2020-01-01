#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

struct Point
{
    double x, y;
    Point operator+(const Point &p) const
    {
        return Point({x + p.x, y + p.y});
    }
    Point operator-(const Point &p) const
    {
        return Point({x - p.x, y - p.y});
    }
    Point operator*(double c) const
    {
        return Point({c * x, c * y});
    }
    Point operator/(double c) const
    {
        return Point({x / c, y / c});
    }
    double cross(const Point &p) const
    {
        return x * p.y - y * p.x;
    }
    double norm2()
    {
        return x * x + y * y;
    }
};

int n;
double x, y;
vector<Point> p;

Point bary(const Point &A, const Point &B, const Point &C, double a, double b, double c)
{
    return ((A * a) + (B * b) + (C * c)) / (a + b + c);
}
Point circumcenter(const Point &A, const Point &B, const Point &C)
{
    double a = (B - C).norm2(), b = (C - A).norm2(), c = (A - B).norm2();
    return bary(A, B, C, a * (b + c - a), b * (c + a - b), c * (a + b - c));
}

int main()
{
    while (cin >> n)
    {
        if (n == 0)
            break;

        p.resize(n);
        rep(i, n)
        {
            cin >> x >> y;
            p[i] = Point({x, y});
        }

        int ans = 0;
        rep(i, n) repx(j, i + 1, n) repx(k, j + 1, n)
        {
            if ((p[j] - p[i]).cross(p[k] - p[i]) == 0)
                continue;

            Point c = circumcenter(p[i], p[j], p[k]);
            double dist = (c - p[i]).norm2();

            int counter = 0;
            rep(t, n) if (t != i && t != j && t != k && (c - p[t]).norm2() == dist)
                counter++;
            ans = max(ans, counter + 3);
        }

        int minimum = 1;
        if (n > 1)
            minimum = 2;

        cout << max(ans, minimum) << '\n';
    }
}