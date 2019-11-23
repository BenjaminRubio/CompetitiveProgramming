#include <bits/stdc++.h>
using namespace std;

struct Point
{
    double x, y;
    Point operator+(const Point &p) const
    {
        return {x + p.x, y + p.y};
    }
    Point operator-(const Point &p) const
    {
        return {x - p.x, y - p.y};
    }
    Point operator*(double c) const
    {
        return {x * c, y * c};
    }
    Point rot()
    {
        return {y, -1.0 * x};
    }
    Point unit()
    {
        return {x / norm(), y / norm()};
    }
    double norm()
    {
        return sqrt(x * x + y * y);
    }
};

double px, py, vx, vy, a, b, c, d;
Point p, v, v_, aux;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(12);

    cin >> px >> py >> vx >> vy >> a >> b >> c >> d;

    p = {px, py};
    v = {vx, vy};
    v = v.unit();
    v_ = v.rot();

    aux = p + (v * b);
    cout << aux.x << ' ' << aux.y << '\n';

    aux = p - (v_ * (a * 0.5));
    cout << aux.x << ' ' << aux.y << '\n';

    aux = p - (v_ * (c * 0.5));
    cout << aux.x << ' ' << aux.y << '\n';

    aux = p - (v_ * (c * 0.5)) - v * d;
    cout << aux.x << ' ' << aux.y << '\n';

    aux = p + (v_ * (c * 0.5)) - v * d;
    cout << aux.x << ' ' << aux.y << '\n';

    aux = p + (v_ * (c * 0.5));
    cout << aux.x << ' ' << aux.y << '\n';

    aux = p + (v_ * (a * 0.5));
    cout << aux.x << ' ' << aux.y << '\n';
}