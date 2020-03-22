#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep_(i, n) for (int i = (int)n - 1; i >= 0; i--)
typedef long long int ll;

struct P
{
    ll x, y;
    bool operator<(const P &p) const
    {
        return x < p.x || (x == p.x && y < p.y);
    }
};

ll cross(P &a, P &b, P &c)
{
    ll dx0 = b.x - a.x, dy0 = b.y - a.y;
    ll dx1 = c.x - a.x, dy1 = c.y - a.y;
    return dx0 * dy1 - dx1 * dy0;
}

vector<P> convex_hull(vector<P> &p)
{
    int n = p.size(), k = 0;
    vector<P> H(2 * n);
    sort(p.begin(), p.end());
    rep(i, n)
    {
        while (k >= 2 && cross(H[k - 2], H[k - 1], p[i]) <= 0) k--;
        H[k++] = p[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; i--)
    {
        while (k >= t && cross(H[k - 2], H[k - 1], p[i]) <= 0) k--;
        H[k++] = p[i];
    }
    H.resize(k - 1);
    return H;
}