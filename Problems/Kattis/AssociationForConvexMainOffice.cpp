#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

struct Point
{
    int x, y;
    Point operator+(const Point &p) const
    {
        return {x + p.x, y + p.y};
    }
    Point reduce() const
    {
        return {x / __gcd(x, y), y / __gcd(x, y)};
    }
    Point rotate() const
    {
        return {-y, x};
    }
    Point rotate_times(int t) const
    {
        Point ans = {x, y};
        while (t--)
            ans = ans.rotate();
        return ans;
    }
    double slope() const
    {
        return (double)y / (double)x;
    }
    bool operator<(const Point &p) const
    {
        return slope() < p.slope();
    }
};

int N;
set<Point> s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    repx(i, 1, 580) repx(j, 1, 580 - i + 2)
    {
        s.insert(Point({i, j}).reduce());
        s.insert(Point({j, i}).reduce());
    }

    while (s.size() >= 100000)
    {
        s.erase(*s.begin());
        s.erase(*--s.end());
    }
    cerr << s.size() << '\n';

    int sum = 0;

    cin >> N;

    Point p = {20000000, 0};

    set<Point>::iterator iter = s.begin();
    int rot = 0;
    rep(i, N)
    {
        if (iter++ == s.end())
        {
            iter = s.begin();
            rot++;
        }
        cout << p.x << ' ' << p.y << '\n';
        p = p + (*iter).rotate_times(rot);
        sum += (*iter).rotate_times(rot).x;
    }
    cout << p.x << ' ' << p.y << '\n';

    cerr << sum << '\n';
}