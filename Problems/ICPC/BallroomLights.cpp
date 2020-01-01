#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef vector<int> vi;

const double PI = 3.14159265358979323846;

struct Point
{
    double x, y;
    Point operator-(Point &p)
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
        if (a < 0)
            a += 2.0 * PI;
        return a;
    }
};

struct Circle
{
    Point center;
    double r;
};

int L, C;
double X, Y, x, y, r;
vector<Point> lightbulb, corner;
vector<Circle> column;

double dist(int i, Point &p)
{
    if (i == 0)
        return X - p.x;
    if (i == 1)
        return Y - p.y;
    if (i == 2)
        return p.x;
    return p.y;
}

double pos(double a, Point &p)
{
    double pos = 0;
    vector<double> d1 = {X - p.x, Y - p.y, p.x, p.y};
    vector<double> d2 = {Y - p.y, p.x, p.y, X - p.x};
    rep(i, 4)
    {
        double shift = (double)i * 0.5 * PI;

        if ((corner[i] - p).ang() > a)
        {
            pos += d1[i] * tan(a - shift);
            break;
        }
        pos += d2[i];

        if (PI * 0.5 > a - shift)
        {
            pos += d1[i] - d2[i] * tan(PI * 0.5 - a + shift);
            break;
        }
        pos += d1[i];
    }
    pos += p.y;
    if (pos >= 2.0 * X + 2.0 * Y)
        pos -= 2.0 * X + 2.0 * Y;
    return pos;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(4);

    corner.resize(4);
    while (cin >> L >> C >> X >> Y)
    {
        if (L == 0 && C == 0 && X == 0 && Y == 0)
            break;

        corner[0] = {X, Y};
        corner[1] = {0, Y};
        corner[2] = {0, 0};
        corner[3] = {X, 0};

        lightbulb.resize(L);
        rep(i, L)
        {
            cin >> x >> y;
            lightbulb[i] = {x, y};
        }

        column.resize(C);
        rep(i, C)
        {
            cin >> x >> y >> r;
            column[i] = {{x, y}, r};
        }

        set<int> off;
        set<tuple<double, int, int, int>> events;
        vi counters(L, 0);

        double a, da, al, ar;
        rep(i, L) rep(j, C)
        {
            a = (column[j].center - lightbulb[i]).ang();
            da = asin(column[j].r / (column[j].center - lightbulb[i]).norm());

            al = a - da;
            if (al < 0)
                al += 2.0 * PI;
            ar = a + da;
            if (ar >= 2.0 * PI)
                ar -= 2.0 * PI;

            events.insert({pos(al, lightbulb[i]), 1, i, j});
            events.insert({pos(ar, lightbulb[i]), 0, i, j});

            if (pos(al, lightbulb[i]) > pos(ar, lightbulb[i]))
            {
                off.insert(i);
                counters[i]++;
            }
        }

        double p;
        int t, i, j;
        double last = 0;
        double ans = 0;
        for (auto e : events)
        {
            tie(p, t, i, j) = e;
            if (off.size() == L)
                ans += p - last;
            if (t == 1)
            {
                off.insert(i);
                counters[i]++;
            }
            if (t == 0 && --counters[i] == 0)
                off.erase(i);
            last = p;
        }
        if (off.size() == L)
            ans += 2.0 * X + 2.0 * Y - last;

        cout << 2.0 * X + 2.0 * Y - ans << '\n';
    }
}