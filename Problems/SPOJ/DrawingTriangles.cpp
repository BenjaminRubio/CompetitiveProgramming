#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

typedef long long ll;

const double PI = 3.14159265358979323846;

struct Point
{
    ll x, y;
    Point operator-(const Point &p) const
    {
        return {x - p.x, y - p.y};
    }
    Point operator+(const Point &p) const
    {
        return {x + p.x, y + p.y};
    }
    ll norm() const
    {
        return x * x + y * y;
    }
    double ang()
    {
        double a = atan2(y, x);
        if (a < 0)
            a += 2.0 * PI;
        return a;
    }
};

int N, x, y;
bool m[201][201];
vector<Point> p;
double a, b, c;
double epsilon = 0.000001;
double dang;

bool evaluate(int i, int j)
{
    double r = (p[i] - p[j]).norm() / (double)a;
    ll a_ = r * (double)a;
    ll b_ = r * (double)b;
    ll c_ = r * (double)c;

    double ang = (p[i] - p[j]).ang();
    double ang1 = ang + dang;
    double ang2 = ang - dang;

    if (ang1 >= 2.0 * PI)
        ang1 -= 2.0 * PI;
    if (ang2 < 0)
        ang2 += 2.0 * PI;

    Point p1 = {(ll)round((double)c_ * cos(ang1)), (ll)round((double)c_ * sin(ang1))};
    Point p2 = {(ll)round((double)c_ * cos(ang2)), (ll)round((double)c_ * sin(ang2))};

    p1 = p[j] + p1;
    p2 = p[j] + p2;

    int i1 = p1.x;
    int j1 = p1.y;
    int i2 = p2.x;
    int j2 = p2.y;

    if (i1 >= -100 && i1 <= 100 && j1 >= -100 && j1 <= 100)
    {
        if (m[i1 + 100][j1 + 100] == true)
        {
            p1 = {i1, j1};
            if ((p[i] - p1).norm() == b_ && (p[j] - p1).norm() == c_)
                return true;
        }
    }

    if (i2 >= -100 && i2 <= 100 && j2 >= -100 && j2 <= 100)
    {
        if (m[i2 + 100][j2 + 100] == true)
        {
            p2 = {i2, j2};
            if ((p[i] - p2).norm() == b_ && (p[j] - p2).norm() == c_)
                return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> N)
    {
        memset(m, false, sizeof m);

        p.resize(N);
        rep(i, N)
        {
            cin >> x >> y;
            p[i] = {x, y};
            m[x + 100][y + 100] = true;
        }

        if (N == 3)
        {
            cout << 1 << '\n';
            continue;
        }

        a = (p[0] - p[1]).norm();
        b = (p[0] - p[2]).norm();
        c = (p[1] - p[2]).norm();
        dang = abs((p[1] - p[0]).ang() - (p[1] - p[2]).ang());

        int counter = 0;
        rep(i, N) repx(j, i + 1, N)
        {
            counter += bool(evaluate(i, j) + evaluate(j, i));
        }

        cout << counter << '\n';
    }
}