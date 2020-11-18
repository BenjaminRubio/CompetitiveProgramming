#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ff first
#define ss second

typedef ll T; struct P
{
    T x, y;
    P() {} P(T x, T y) : x(x), y(y) {}
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    T operator^(const P &p) const { return x * p.y - y * p.x; }
    bool half() const { return y > 0 || (y == 0 && x > 0); }
    bool operator<(const P &p) const
    {
        int h1 = half(), h2 = p.half();
        return h1 != h2 ? h1 > h2 : ((*this) ^ p) > 0;
    }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

ll turn(const P &a, const P &b, const P &c) { return (b - a) ^ (c - a); }

struct S
{
    P p, q; int t; S() : t(0) {}
    void sw() { swap(p, q); }
    bool operator<(const S &s) const
    {
        if (t == s.t || p.half() == s.p.half())
            return s.p < p ? turn(p, s.q, s.p) < 0 : turn(s.p, q, p) > 0;
        return p < s.q ? turn(p, s.q, s.p) < 0 : turn(s.p, q, p) > 0;
    }
};

int K, N, M;
vector<P> p;
vector<pair<P, P>> w;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    while (cin >> K >> N >> M)
    {
        p.resize(N);
        rep(i, N) cin >> p[i];

        w.resize(M);
        rep(i, M) cin >> w[i].ff >> w[i].ss;

        rep(i, K)
        {
            vector<pair<pair<P, int>, int>> E;
            rep(j, N) if (i != j) E.emplace_back(mp(p[j] - p[i], 1), j);
            
            vector<S> ww(M); set<S> s;
            rep(j, M)
            {
                ww[j].p = w[j].ff - p[i], ww[j].q = w[j].ss - p[i];
                if (turn(w[j].ff, w[j].ss, p[i]) < 0) ww[j].sw();
                if (ww[j].q < ww[j].p) ww[j].t = 1, s.insert(ww[j]);
                E.emplace_back(mp(ww[j].p, 0), j); E.emplace_back(mp(ww[j].q, 2), j);
            }

            sort(E.begin(), E.end());

            int ans = 0;
            for (auto &e : E)
            {
                if (e.ff.ss == 0) s.insert(ww[e.ss]);
                if (e.ff.ss == 2) s.erase(ww[e.ss]);
                if (e.ff.ss == 1)
                {
                    if (s.empty()) ans++;
                    else 
                    {
                        S a = *s.begin();
                        if (turn(a.p, a.q, e.ff.ff) > 0) ans++;
                    }
                }
            }

            cout << ans << '\n';
        }
    }
}