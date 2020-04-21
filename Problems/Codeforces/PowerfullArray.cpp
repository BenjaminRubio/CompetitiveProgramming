#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i< (int)n; i++)
typedef long long ll;

int sq(int x) { return sqrt(x); }

struct Query
{
    int l, r, id;
    Query(int l, int r, int id) : l(l), r(r), id(id) {}
    bool operator<(Query &q)
    {
        return sq(l) < sq(q.l) or (sq(l) == sq(q.l) and sq(r) < sq(q.r));
    }
};

int n, t, l, r;
ll s;
ll a[200010], ans[200010], c[1000010];
vector<Query> q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> t;
    rep(i, n) cin >> a[i];

    rep(i, t)
    {
        cin >> l >> r;
        q.emplace_back(l - 1, r - 1, i);
    }

    sort(q.begin(), q.end());

    l = 0, r = 0, s = a[0], c[a[0]] = 1;
    for (Query e : q)
    {
        while (e.r > r) r++, c[a[r]]++, s += a[r] * (2 * c[a[r]] - 1);
        while (e.r < r) s -= a[r] * (2 * c[a[r]] - 1), c[a[r]]--, r--;
        while (e.l > l) s -= a[l] * (2 * c[a[l]] - 1), c[a[l]]--, l++;
        while (e.l < l) l--, c[a[l]]++, s += a[l] * (2 * c[a[l]] - 1);

        ans[e.id] = s;
    }

    rep(i, t) cout << ans[i] << '\n';
}