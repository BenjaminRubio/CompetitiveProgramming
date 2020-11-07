#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair

const ll INF = 1e10;

typedef ll T; struct P
{
    T x, y;
    P() {} P(T x, T y) : x(x), y(y) {}
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    T operator^(const P &p) const { return x * p.y - y * p.x; }
    bool operator<(const P &p) const { return x < p.x; }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

ll turn(const P &a, const P &b, const P &c) { return (b - a) ^ (c - a); }

struct S
{
    P p, q;
    S() {} S(P p, P q) : p(p), q(q) {}
    bool operator<(const S &s) const
    { return s.p < p ? turn(p, s.q, s.p) > 0 : turn(s.p, q, p) < 0; }
};

int N, C, X, t, i; P p, DP[100010];
vector<S> s; vector<int> V, D, A;

P dp(int u)
{
    if (DP[u].y != -1) return DP[u];
    if (D[u] == -1 && s[u].p.y == s[u].q.y) return DP[u] = P(-1, s[u].p.y);
    if (D[u] == -1 && s[u].p.y > s[u].q.y) return DP[u] = P(s[u].p.x, INF);
    if (D[u] == -1 && s[u].p.y < s[u].q.y) return DP[u] = P(s[u].q.x, INF);

    P ans = dp(D[u]); X = s[u].p.y > s[u].q.y ? s[u].p.x : s[u].q.x;
    if (ans.x == -1) return DP[u] = P(X, ans.y);
    return DP[u] = ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    while (cin >> N >> C)
    {
        s.resize(N); V.resize(C);
        vector<pair<P, pair<int, int>>> E; set<pair<S, int>> ss;
        rep(i, N)
        {
            cin >> s[i].p >> s[i].q; if (s[i].q < s[i].p) swap(s[i].p, s[i].q);
            E.emplace_back(s[i].p, mp(0, i)); E.emplace_back(s[i].q, mp(2, i));
        }
        rep(i, C) { cin >> V[i]; E.emplace_back(P(V[i], 0), mp(1, i)); }

        sort(E.begin(), E.end());

        D.assign(N, -1); A.assign(C, -1);
        for (auto &e : E)
        {
            p = e.first; t = e.second.first; i = e.second.second;
            if (t == 0) ss.emplace(s[i], i);
            if (t == 0 && s[i].p.y > s[i].q.y)
            {
                auto it = ss.upper_bound(mp(s[i], i));
                if (it != ss.end()) D[i] = it->second;
            }
            if (t == 2) ss.erase(mp(s[i], i));
            if (t == 2 && s[i].p.y < s[i].q.y)
            {
                auto it = ss.upper_bound(mp(s[i], i));
                if (it != ss.end()) D[i] = it->second;
            }
            if (t == 1 && !ss.empty()) A[i] = ss.begin()->second;
        }

        rep(i, N) DP[i] = P(-1, -1);
        rep(i, C)
        {
            if (A[i] == -1) { cout << V[i] << '\n'; continue; }
            P ans = dp(A[i]);
            if (ans.x == -1) cout << V[i] << ' ' << ans.y << '\n';
            else if (ans.y == INF) cout << ans.x << '\n';
            else cout << ans.x << ' ' << ans.y << '\n';
        }
    }
}