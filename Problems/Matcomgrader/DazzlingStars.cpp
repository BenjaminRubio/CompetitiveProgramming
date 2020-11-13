#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
const double PI = acos(-1LL);

template <typename T>
struct Point
{
    T x, y, b;

    Point<T> operator-(const Point<T> &p) const { return {x - p.x, y - p.y}; }

    double angle()
    {
        double angle = atan2(y, x);
        if (angle < 0)
            angle += 2 * PI;
        return angle;
    }
};

int n, x, y, b;
vector<Point<ll>> stars;

int main()
{
    cin >> n;
    rep(i, n)
    {
        cin >> x >> y >> b;
        stars.pb({x, y, b});
    }

    vector<pair<double, int>> sweep;
    int c = 0;
    int n_ = 0;

    rep(i, n) repx(j, i, n)
    {
        if (stars[i].b == stars[j].b)
            continue;

        n_++;

        Point<ll> aux;
        if (stars[i].b > stars[j].b)
            aux = stars[j] - stars[i];
        else
            aux = stars[i] - stars[j];

        double left = aux.angle() + PI / 2;
        double right = aux.angle() - PI / 2;
        if (left >= 2 * PI)
            left -= 2 * PI;
        if (right < 0)
            right += 2 * PI;

        if (left < right)
            c++;

        sweep.pb({left, 1});
        sweep.pb({right, 0});
    }

    sort(sweep.begin(), sweep.end());

    if (!n_)
    {
        cout << "Y\n";
        return 0;
    }

    for (auto e : sweep)
    {
        if (c >= n_)
        {
            cout << "Y\n";
            return 0;
        }
        if (e.second) c--;
        else c++;
    }

    cout << "N\n";
}