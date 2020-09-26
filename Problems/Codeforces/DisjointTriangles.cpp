#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ff first
#define ss second

struct P
{
    ll x, y;
    P() {}
    P(ll x, ll y) : x(x), y(y) {}

    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    ll operator^(const P &p) const { return x * p.y - y * p.x; }
    bool operator<(const P &p) const { return y < p.y; }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }

bool half(P &p) { return p.y > 0 || (p.y == 0 && p.x > 0); }

int N; ll S;
vector<pair<P, int>> p;
vector<int> I;

int main()
{
    cin >> N;

    p.resize(N);
    rep(i, N) { cin >> p[i].ff; p[i].ss = i; }

    sort(p.begin(), p.end());

    I.resize(N);
    rep(i, N) I[p[i].ss] = i;

    vector<pair<P, pair<int, int>>> S;
    rep(i, N) repx(j, i + 1, N)
        S.emplace_back(p[j].ff - p[i].ff, make_pair(p[i].ss, p[j].ss));

    sort(S.begin(), S.end(), [](auto &p1, auto &p2)
    {
        int h1 = half(p1.ff), h2 = half(p2.ff);
        return h1 != h2 ? h1 > h2 : (p1.ff ^ p2.ff) > 0;
    });

    ll ans = 0;
    for (auto &e : S)
    {
        int i = e.ss.ff, j = e.ss.ss;
        int l = min(I[i], I[j]), r = N - max(I[i], I[j]) - 1;

        ans += ll(l * (l - 1) / 2ll) * ll(r * (r - 1) / 2ll);

        swap(p[I[i]], p[I[j]]); swap(I[i], I[j]);
    }

    cout << ans << '\n';
}