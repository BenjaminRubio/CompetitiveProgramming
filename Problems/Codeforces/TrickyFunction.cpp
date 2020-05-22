#pragma GCC optimize("Ofast", "unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

typedef ll T;
struct P
{
    T x, y;
    P() {}
    P(T x, T y) : x(x), y(y) {}

    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    bool operator<(const P &p) const
    {
        return x != p.x ? x < p.x : y < p.y;
    }

    T norm2() const { return x * x + y * y; }
};

const int MAXN = 1000010;

int n;
T mindist;
P a[MAXN], t[MAXN];

T sq(T x) { return x * x; }

bool cmpY(P & a, P & b) { return a.y < b.y; }

void closest(int l, int r)
{
    if (r - l <= 3)
    {
        repx(i, l, r) repx(j, i + 1, r)
            mindist = min(mindist, (a[i] - a[j]).norm2());
        sort(a + l, a + r, cmpY);
        return;
    }

    int m = (l + r) >> 1;
    int xm = a[m].x;
    closest(l, m); closest(m, r);

    merge(a + l, a + m, a + m, a + r, t, cmpY);
    copy(t, t + r - l, a + l);

    int tsz = 0;
    repx(i, l, r)  if (sq(a[i].x - xm) < mindist)
    {
        for (int j = tsz - 1; j >= 0 && sq(a[i].y - t[j].y) < mindist; --j)
            mindist = min(mindist, (a[i] - t[j]).norm2());
        t[tsz++] = a[i];
    }
}

vector<ll> x;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    x.resize(n);
    rep(i, n) cin >> x[i];

    ll s = 0;
    rep(i, n) s += x[i], a[i] = P(i, s);

    sort(a, a + n);
    mindist = LLONG_MAX;
    closest(0, n);

    cout << mindist << '\n';
}