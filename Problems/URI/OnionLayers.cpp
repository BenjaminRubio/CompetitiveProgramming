#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define rep_(i, n) for (int i = (int)n - 1; i >= 0; i--)

struct P
{
    int x, y;
    P() {}
    bool operator<(const P &p) const
    {
        return x < p.x || (x == p.x && y < p.y);
    }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

int cross(P &a, P &b, P &c)
{
    int dx0 = b.x - a.x, dy0 = b.y - a.y;
    int dx1 = c.x - a.x, dy1 = c.y - a.y;
    return dx0 * dy1 - dx1 * dy0;
}

vector<int> convex_hull(vector<P> &p)
{
    int n = p.size(), k = 0;
    vector<P> H(2 * n);
    vector<int> r(2 * n);
    sort(p.begin(), p.end());
    rep(i, n)
    {
        while (k >= 2 && cross(H[k - 2], H[k - 1], p[i]) <= 0) k--;
        H[k++] = p[i]; r[k - 1] = i;
    }
    for (int i = n - 2, t = k + 1; i >= 0; i--)
    {
        while (k >= t && cross(H[k - 2], H[k - 1], p[i]) <= 0) k--;
        H[k++] = p[i]; r[k - 1] = i;
    }
    r.resize(k - 1);
    return r;
}

int N;
vector<P> p;

int main()
{
    while (cin >> N)
    {
        if (N == 0) break;

        p.resize(N);
        rep(i, N) cin >> p[i];

        vector<bool> v(N, false);
        vector<P> p_;
        vector<int> m(N);
        int c = 0, rem = N;
        while (rem)
        {
            p_.clear();
            rep(i, N) if (!v[i])
            {
                p_.push_back(p[i]);
                m[p_.size() - 1] = i;
            }
            vector<int> r = convex_hull(p_);

            for (int i : r) v[m[i]] = true;
            rem -= r.size();
            c++;
        }

        if (c & 1) cout << "Take this onion to the lab!\n";
        else cout << "Do not take this onion to the lab!\n";
    }
}