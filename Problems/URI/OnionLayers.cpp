#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep_(i, n) for (int i = (int)n - 1; i >= 0; i--)

struct P
{
    int x, y, id;
    P() {}
    bool operator<(const P &p) const
    {
        return x < p.x || (x == p.x && y < p.y);
    }
    bool operator==(const P &p) const
    {
        return x == p.x && y == p.y;
    }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

int cross(P &a, P &b, P &c)
{
    int dx0 = b.x - a.x, dy0 = b.y - a.y;
    int dx1 = c.x - a.x, dy1 = c.y - a.y;
    return dx0 * dy1 - dx1 * dy0;
}

vector<P> convex_hull(vector<P> &p)
{
    int n = p.size(), k = 0;
    vector<P> H(2 * n);
    rep(i, n)
    {
        while (k >= 2 && cross(H[k - 2], H[k - 1], p[i]) < 0) k--;
        H[k++] = p[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; i--)
    {
        while (k >= t && cross(H[k - 2], H[k - 1], p[i]) < 0) k--;
        H[k++] = p[i];
    }
    H.resize(k);
    return H;
}

int N;
vector<P> p;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    while (cin >> N && N)
    {
        p.resize(N);
        rep(i, N) { cin >> p[i]; p[i].id = i; }

        sort(p.begin(), p.end());

        vector<bool> v(N, false);
        int c = 0, rem = N;
        while (p.size())
        {
            vector<P> r = convex_hull(p);
            for (P &i : r) v[i.id] = true;

            vector<P> p_;
            for (P &i : p) if (!v[i.id]) p_.push_back(i);
            p = p_;
            c++;
        }

        if (c & 1) cout << "Take this onion to the lab!\n";
        else cout << "Do not take this onion to the lab!\n";
    }
}