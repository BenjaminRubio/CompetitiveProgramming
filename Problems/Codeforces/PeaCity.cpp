#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define invrep(i, b, a) for(int i = b; i >= a; i--)
typedef long long ll;

const double PI = 3.14159265358979323846;

double correct_angle(double angle) {
    while (angle < 0.0) angle += 2.0 * PI;
    while (angle > 2.0 * PI) angle -= 2.0 * PI;
    return angle;
}

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
    Point operator*(double c)
    {
        return {c * x, c * y};
    }
    bool operator<(const Point &p) const
    {
        return x < p.x || (x == p.x && y < p.y);
    }
    Point rot() const
    {
        return {y, -x};
    }
    Point rot_() const
    {
        return {-y, x};
    }
    double dot(const Point &p) const
    {
        return x * p.x + y * p.y;
    }
    double ang() const
    {
        return correct_angle(atan2(y, x));
    }
    double norm2() const
    {
        return x * x + y * y;
    }
    double norm() const
    {
        return sqrt(norm2());
    }
};

struct Edge
{
    Point p1, p2;
};

double cross(Point &a, Point &b, Point &c)
{
    double dx0 = b.x - a.x, dy0 = b.y - a.y;
    double dx1 = c.x - a.x, dy1 = c.y - a.y;
    return dx0 * dy1 - dx1 * dy0;
}

vector<Point> upper_hull(vector<Point> &P)
{
    int n = P.size(), k = 0;
    sort(P.begin(), P.end());
    vector<Point> uh(n);
    invrep (i, n - 1, 0) {
        while (k >= 2 && cross(uh[k - 2], uh[k - 1], P[i]) <= 0) k--;
        uh[k++] = P[i];
    }
    uh.resize(k);
    return uh;
}

vector<Point> lower_hull(vector<Point> &P)
{
    int n = P.size(), k = 0;
    sort(P.begin(), P.end());
    vector<Point> lh(n);
    rep (i, n)
    {
        while (k >= 2 && cross(lh[k-2], lh[k-1], P[i]) <= 0) k--;
        lh[k++] = P[i];
    }
    lh.resize(k);
    return lh;
}

vector<Point> convex_hull(vector<Point> &P)
{
    int n = P.size(), k = 0;
    vector<Point> H(2*n);
    sort(P.begin(), P.end());
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    for (int i = n-2, t = k+1; i >= 0; i--) {
        while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }
    H.resize(k-1);
    return H;
}

double N, X, Y;
vector<Point> P;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(8);

    cin >> N;

    P.resize(N);
    rep(i, N)
    {
        cin >> X >> Y;
        P[i] = {X, Y};
    }

    vector<Point> H = convex_hull(P);
    int S = H.size();

    vector<Edge> E;
    for (int i = S - 1, j = 0; j < S; i = j++)
        E.push_back({H[i], H[j]});

    double A = DBL_MAX;
    Point r1, r2, r3, r4;

    rep(i, S)
    {
        Point p1, p2, p3, c1, c2, c3, c4;

        int l = 1, r = S;
        while (l < r)
        {
            int m = (l + r) / 2;
            if ((E[(i + m) % S].p2 - E[(i + m) % S].p1).ang() < (E[i].p2 - E[i].p1).ang())
                if (2.0 * PI - (E[i].p2 - E[i].p1).ang() + (E[(i + m) % S].p2 - E[(i + m) % S].p1).ang() > 0.5 * PI)
                    r = m;
                else l = m + 1;
            else if ((E[(i + m) % S].p2 - E[(i + m) % S].p1).ang() - (E[i].p2 - E[i].p1).ang() > 0.5 * PI)
                r = m;
            else
                l = m + 1;
        }
        p1 = E[(i + l) % S].p1;

        r = S;
        while (l < r)
        {
            int m = (l + r) / 2;
            if ((E[(i + m) % S].p2 - E[(i + m) % S].p1).ang() < (E[i].p2 - E[i].p1).ang())
                if (2.0 * PI - (E[i].p2 - E[i].p1).ang() + (E[(i + m) % S].p2 - E[(i + m) % S].p1).ang() > PI)
                    r = m;
                else l = m + 1;
            else if ((E[(i + m) % S].p2 - E[(i + m) % S].p1).ang() - (E[i].p2 - E[i].p1).ang() > PI)
                r = m;
            else
                l = m + 1;
        }
        p2 = E[(i + l) % S].p1;

        r = S;
        while (l < r)
        {
            int m = (l + r) / 2;
            if ((E[(i + m) % S].p2 - E[(i + m) % S].p1).ang() < (E[i].p2 - E[i].p1).ang())
                if (2.0 * PI - (E[i].p2 - E[i].p1).ang() + (E[(i + m) % S].p2 - E[(i + m) % S].p1).ang() > 1.5 * PI)
                    r = m;
                else l = m + 1;
            else if ((E[(i + m) % S].p2 - E[(i + m) % S].p1).ang() - (E[i].p2 - E[i].p1).ang() > 1.5 * PI)
                r = m;
            else
                l = m + 1;
        }
        p3 = E[(i + l) % S].p1;

        c1 = E[i].p1 + (E[i].p2 - E[i].p1) * ((E[i].p2 - E[i].p1).dot(p1 - E[i].p1) / (E[i].p2 - E[i].p1).norm2());
        c4 = E[i].p2 + (E[i].p1 - E[i].p2) * ((E[i].p1 - E[i].p2).dot(p3 - E[i].p2) / (E[i].p1 - E[i].p2).norm2());
        c2 = c1 + (E[i].p2 - E[i].p1).rot_() * ((E[i].p2 - E[i].p1).rot_().dot(p2 - c1) / (E[i].p2 - E[i].p1).rot_().norm2());
        c3 = c4 + (E[i].p1 - E[i].p2).rot() * ((E[i].p1 - E[i].p2).rot().dot(p2 - c4) / (E[i].p1 - E[i].p2).rot().norm2());

        double a = (c1 - c2).norm() * (c2 - c3).norm();
        if (a < A)
        {
            r1 = c1, r2 = c2, r3 = c3, r4 = c4;
            A = a;
        }
    }

    cout << r1.x << ' ' << r1.y << '\n';
    cout << r2.x << ' ' << r2.y << '\n';
    cout << r3.x << ' ' << r3.y << '\n';
    cout << r4.x << ' ' << r4.y << '\n';
}
