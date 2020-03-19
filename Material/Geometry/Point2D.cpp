#include <bits/stdc++.h>
using namespace std;

const double PI = 3.14159265358979323846;

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
    Point operator*(const double &c) const
    {
        return {c * x, c * y};
    }
    double operator%(const Point &p) const
    {
        return x * p.y - y * p.x;
    }
    double norm()
    {
        return sqrt(x * x + y * y);
    }
    double norm2()
    {
        return x * x + y * y;
    }
    double ang()
    {
        double a = atan2(y, x);
        if (a < 0) a += 2.0 * PI;
        return a;
    }
};