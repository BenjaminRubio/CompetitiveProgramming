#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct Point
{
    double x, y;
    Point operator+(const Point &p) const
    {
        return {x + p.x, y + p.y};
    }
};

struct Polygon
{
    vector<Point> point = {};
    bool in(const Point &p) const
    {
        int c = 0;
        for (int i = point.size() - 1, j = 0; j < point.size(); i = j++)
        {
            double m = (point[j].x - point[i].x) / (point[j].y - point[i].y);
            if (point[i].y <= p.y && point[j].y > p.y)
                if (point[i].x + (p.y - point[i].y) * m >= p.x)
                    c++;
            if (point[i].y > p.y && point[j].y <= p.y)
                if (point[i].x + -1.0 * (point[i].y - p.y) * m >= p.x)
                    c++;
        }
        return c % 2;
    }
};

vector<vector<char>> m;
int R, C, N, k, r, c;
char ch;
Point d[8] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
string line;
vector<char> path;

void process_instance()
{
    Point p = {(double)r, (double)c};
    Polygon pol;
    rep(i, k + 1)
    {
        if (p.x < 0 || p.x >= R || p.y < 0 || p.y >= C)
        {
            cout << "REGION " << ch << " GOES OUTSIDE THE ARRAY\n";
            return;
        }
        if (m[p.x][p.y] != '.')
        {
            cout << "REGION " << ch << " BOUNDARY INTERSECTS REGION " << m[p.x][p.y] << '\n';
            return;
        }
        pol.point.push_back(p);
        if (i < k)
            p = p + d[path[i] - 'A'];
    }

    if (p.x != r || p.y != c)
    {
        cout << "REGION " << ch << " BOUNDARY IS NOT CLOSED\n";
        return;
    }

    p = {(double)r, (double)c};
    rep(i, k)
    {
        m[p.x][p.y] = ch;
        p = p + d[path[i] - 'A'];
    }

    rep(i, R) rep(j, C) if (m[i][j] != ch && pol.in({(double)i, (double)j}))
        m[i][j] = ch;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> R >> C >> N)
    {
        if (R == 0)
            break;

        m.assign(R, vector<char>(C, '.'));

        rep(i, N)
        {
            cin >> ch >> r >> c >> k;
            path.resize(k);
            rep(j, k) cin >> path[j];
            r--;
            c--;
            process_instance();
        }

        rep(i, R)
        {
            rep(j, C) cout << m[i][j];
            cout << '\n';
        }
        cout << '\n';
    }
}