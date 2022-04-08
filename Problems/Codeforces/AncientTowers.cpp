#include <bits/stdc++.h>
using namespace std;

using ul = unsigned long long;
using ll = long long;
using db = double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<db, db>;

using vp = vector<pii>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<db>;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define all(x) begin(x), end(x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

// POINT 2D

typedef ll T; struct P
{
    T x, y;
    P() {} P(T x, T y) : x(x), y(y) {}

    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    T operator^(const P &p) const { return x * p.y - y * p.x; }
    bool operator==(const P &p) const { return x == p.x && y == p.y; }
    bool operator!=(const P &p) const { return x != p.x || y != p.y; }
    bool operator<(const P &p) const { return x != p.x ? p.x > x : p.y > y;  }

    T norm2() const { return x * x + y * y; }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }
ostream &operator<<(ostream &s, const P &p)
{
    return s << '(' << p.x << ", " << p.y << ')';
}

T turn(P &a, P &b, P &c) { return (b - a) ^ (c - a); }

bool half(P &p) { return p.y > 0 || (p.y == 0 && p.x > 0); }

template <class T>
class FT2D
{
    vector<vector<T>> t;
    int n, m;

public:
    FT2D() {}
    FT2D(int n, int m) : n(n), m(m) { t.assign(n, vector<T>(m, 0)); }

    void add(int r, int c, T value)
    {
        for (int i = r; i < n; i |= i + 1)
            for (int j = c; j < m; j |= j + 1)
                t[i][j] += value;
    }

    T sum(int r, int c)
    {
        T res = 0;
        for (int i = r; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = c; j >= 0; j = (j & (j + 1)) - 1)
                res += t[i][j];
        return res;
    }

    T sum(int r1, int c1, int r2, int c2)
    {
        return sum(r2, c2) - sum(r1 - 1, c2) - sum(r2, c1 - 1) +
               sum(r1 - 1, c1 - 1);
    }
};

ll S, N;
vector<P> p;
P a, b;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> S >> N; S *= 2ll;
    p.resize(N); rep(i, N) cin >> p[i];

    FT2D<int> ft(N, N);

    ll ans = 0;

    rep(i, N) repx(j, i + 1, N)
    {
        a = p[i], b = p[j];

        vector<pair<db, P>> l, r; r.eb(0, a + (a - b));
        for (P &c : p) if (c != a && c != b)
        {
            ll t = turn(a, b, c);
            if (t > 0) l.eb(t, c);
            else r.eb(-t, c);
        }

        sort(l.rbegin(), l.rend());
        sort(r.begin(), r.end());

        int n = l.size(), m = r.size();

        vector<pair<P, int>> R;
        rep(i, m) R.eb(r[i].ss, i);

        vector<pii> C(m);
        
        sort(R.begin(), R.end(), [](pair<P, int> &p1, pair<P, int> &p2)
        {
            P pp1 = (p1.ff - a), pp2 = (p2.ff - a);
            int h1 = half(pp1), h2 = half(pp2);
            return h1 != h2 ? h1 > h2 : (pp1 ^ pp2) > 0;
        });

        vi I1;
        rep(i, m) if (R[i].ff == (a + (a - b)))
        {
            repx(j, i + 1, i + m) I1.pb(R[j % m].ss);
            break;
        }
        rep(i, m - 1) C[I1[i]].ff = i;

        sort(R.begin(), R.end(), [](pair<P, int> &p1, pair<P, int> &p2)
        {
            P pp1 = (p1.ff - b), pp2 = (p2.ff - b);
            int h1 = half(pp1), h2 = half(pp2);
            return h1 != h2 ? h1 > h2 : (pp1 ^ pp2) > 0;
        });

        vi I2;
        rep(i, m) if (R[i].ff == (a + (a - b)))
        {
            repx(j, i + 1, i + m) I2.pb(R[j % m].ss);
            break;
        }
        rep(i, m - 1) C[I2[i]].ss = i;

        repx(i, 1, m) ft.add(C[i].ff, C[i].ss, 1);

        int pos = 1;
        for (auto &e : l)
        {
            while (pos < m && (e.ff + r[pos].ff) < S)
            {
                ft.add(C[pos].ff, C[pos].ss, -1);
                pos++;
            }
            if (pos == m) break;

            int l1 = 0, r1 = m - 1;
            while (l1 < r1)
            {
                int m1 = (l1 + r1) / 2;
                if (turn(e.ss, a, r[I1[m1]].ss) > 0) r1 = m1;
                else l1 = m1 + 1;
            }

            int l2 = 0, r2 = m - 1;
            while (l2 < r2)
            {
                int m2 = (l2 + r2) / 2;
                if (turn(e.ss, b, r[I2[m2]].ss) > 0) r2 = m2;
                else l2 = m2 + 1;
            }

            int conv = (l2 ? ft.sum(l1, 0, m, l2 - 1) : 0);

            ans += conv;
            ans += 2 * (m - pos - conv);
        }

        while (pos < m) { ft.add(C[pos].ff, C[pos].ss, -1); pos++; }
    }

    cout << ans / 2ll << '\n';
}
