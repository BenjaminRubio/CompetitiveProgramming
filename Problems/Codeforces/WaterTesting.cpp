#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

struct Point
{
    ll x, y;
};

ll area(vector<Point> &pol)
{
    int n = pol.size();
    ll area = 0;
    for (int i = n - 1, j = 0; j < n; i = j++)
    {
        area += (pol[i].x + pol[j].x) * (pol[j].y - pol[i].y);
    }
    return abs(area / 2LL);
}

ll n, x, y;
vector<Point> pol;

int main()
{
    cin >> n;
    pol.resize(n);
    rep(i, n)
    {
        cin >> x >> y;
        pol[i] = Point({x, y});
    }

    ll b = 0;
    for (int i = n - 1, j = 0; j < n; i = j++)
    {
        if (pol[i].x == pol[j].x)
            b += abs(pol[i].y - pol[j].y);
        else if (pol[i].y == pol[j].y)
            b += abs(pol[i].x - pol[j].x);
        else
            b += __gcd(abs(pol[i].x - pol[j].x), abs(pol[i].y - pol[j].y));
    }

    ll a = area(pol);

    cout << a - (b / 2LL) + 1LL << '\n';
}