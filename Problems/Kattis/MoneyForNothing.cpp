#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ff first
#define ss second

int M, N;
vector<pair<ll, ll>> p, q;
ll MX, a, b, low;

ll profit(int i, int j)
{
    if (q[j].ff < p[i].ff) return 0;
    return (q[j].ff - p[i].ff) * (q[j].ss - p[i].ss);
}

void compute(int l, int r, int optl, int optr)
{
    if (l > r) return;

    int m = (l + r) / 2;
    pair<ll, int> best = {0, -1};

    repx(k, optl, optr + 1) best = max(best, {profit(m, k), k});

    MX = max(MX, best.ff);

    compute(l, m - 1, optl, best.ss);
    compute(m + 1, r, best.ss, optr);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> M >> N;

    vector<pair<ll, ll>> s;
    rep(i, M)
    {
        cin >> a >> b;
        s.emplace_back(a, b);
    }

    sort(s.begin(), s.end());

    low = LLONG_MAX;
    for (auto e : s) if (e.ss < low)
    {
        p.push_back(e);
        low = e.ss;
    }

    s.clear();
    rep(i, N)
    {
        cin >> a >> b;
        s.emplace_back(1e9 - a, 1e9 - b);
    }

    sort(s.begin(), s.end());

    low = LLONG_MAX;
    for (auto e : s) if (e.ss < low)
    {
        q.emplace_back(1e9 - e.ff, 1e9 - e.ss);
        low = e.ss;
    }
    reverse(q.begin(), q.end());

    MX = 0;
    compute(0, (int)p.size() - 1, 0, (int)q.size() - 1);

    cout << MX << '\n';
}