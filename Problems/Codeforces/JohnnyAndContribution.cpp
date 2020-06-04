#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T, typename Comparator = less<T>>
using ordered_set = tree<T, null_type, Comparator, rb_tree_tag,
                         tree_order_statistics_node_update>;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second

int N, M, u, v;
vector<pair<int, int>> p;
vector<int> t;
vector<ordered_set<int>> c;

int main()
{
    cin >> N >> M;

    rep(i, M)
    {
        cin >> u >> v; u--, v--;
        p.emplace_back(u, v);
    }

    t.resize(N);
    rep(i, N) cin >> t[i];

    c.assign(N, {});
    rep(i, M)
    {
        u = p[i].ff, v = p[i].ss;
        c[u].insert(t[v]); c[v].insert(t[u]);
    }

    bool flag = false;
    rep(i, N)
    {
        int pos = c[i].order_of_key(t[i]);

        if (pos != t[i] - 1) flag = true;
        if (*(c[i].find_by_order(pos)) == t[i]) flag = true;
    }

    if (flag) { cout << -1 << '\n'; return 0; }

    vector<pair<int, int>> order(N);
    rep(i, N) order[i] = make_pair(t[i], i);

    sort(order.begin(), order.end());

    rep(i, N) cout << order[i].ss + 1 << ' ';
    cout << '\n';
}