#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

struct P
{
    int x, y;
    P(int x, int y) : x(x), y(y) {}
    P rot() { return P(-y, x); }
    P reduce() { return P(x / __gcd(x, y), y / __gcd(x, y)); }
    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    bool operator<(const P &p) const { return y * p.x < p.y * x; }
};

int N;
set<P> s;

int main()
{
    bool done = false;
    rep(i, 575) rep(j, i) if (!done)
    {
        s.insert(P(j + 1, i - j).reduce());
        if (s.size() == 100000) done = true;
    }

    vector<P> v;
    for (P p : s) v.push_back(p);
    rep(i, 300000) v.push_back(v[i].rot());

    cin >> N;

    int i = 0;
    P p(20000000, 0);
    while (i < N)
    {
        cout << p.x << ' ' << p.y << '\n';
        p = p + v[i++];
    }
}