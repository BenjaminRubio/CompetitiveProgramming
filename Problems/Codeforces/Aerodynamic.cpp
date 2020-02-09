#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

struct Point
{
    int x, y;
    Point operator+(const Point &p)
    {
        return {x + p.x, y + p.y};
    }
    Point operator-(const Point &p)
    {
        return {x - p.x, y - p.y};
    }
    bool operator!=(const Point &p)
    {
        return (x != p.x) or (y != p.y);
    }
};

int n;
vector<Point> pol;
vector<pair<Point, Point>> edges;

int main()
{
    cin >> n;

    pol.resize(n);
    rep(i, n) cin >> pol[i].x >> pol[i].y;

    if (n % 2)
    {
        cout << "NO\n";
        return 0;
    }

    for (int l = n - 1, r = 0; r < n; l = r++)
        edges.push_back({pol[l], pol[r]});

    bool is = true;
    rep(i, n)
    {
        pair<Point, Point> p1 = edges[i], p2 = edges[(i + n / 2) % n];
        if ((p1.ss - p1.ff) != (p2.ff - p2.ss)) is = false;
    }

    if (is) cout << "YES\n";
    else cout << "NO\n";
}