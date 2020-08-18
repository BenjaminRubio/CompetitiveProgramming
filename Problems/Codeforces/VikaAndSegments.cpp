#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ff first
#define ss second

template <typename T, typename Comparator = less<T>>
using super_set = tree<T, null_type, Comparator, rb_tree_tag,
                       tree_order_statistics_node_update>;

int N, x, y, x_, y_;
vector<pair<int, pair<int, int>>> H;
vector<pair<pair<int, int>, pair<int, int>>> E;

int main()
{
    cin >> N;

    rep(i, N)
    {
        cin >> x >> y >> x_ >> y_;

        if (x > x_) swap(x, x_);
        if (y > y_) swap(y, y_);

        if (x == x_) E.emplace_back(mp(x, 1), mp(y, y_));
        else if (y == y_) H.emplace_back(y, mp(x, x_));
    }

    sort(H.begin(), H.end());

    long long ans = 0;

    int ll = INT_MIN, lr = INT_MIN, lp = INT_MIN;
    for (auto &e : H)
    {
        int p = e.ff, l = e.ss.ff, r = e.ss.ss;
        if (p != lp)
        {
            if (lp != INT_MIN)
            {
                E.emplace_back(mp(ll, 0), mp(lp, 0));
                E.emplace_back(mp(lr, 2), mp(lp, 0));
                ans += lr - ll + 1;
            }
            ll = l, lr = r;
        }
        else if (l > lr)
        {
            E.emplace_back(mp(ll, 0), mp(lp, 0));
            E.emplace_back(mp(lr, 2), mp(lp, 0));
            ans += lr - ll + 1;
            ll = l, lr = r;
        }
        else lr = max(lr, r);
        lp = p;
    }
    E.emplace_back(mp(ll, 0), mp(lp, 0));
    E.emplace_back(mp(lr, 2), mp(lp, 0));
    if (!H.empty()) ans += lr - ll + 1;

    sort(E.begin(), E.end());

    super_set<int> ss;
    lr = INT_MIN, lp = INT_MIN;
    for (auto &e : E)
    {
        if (e.ff.ss == 0) ss.insert(e.ss.ff);
        if (e.ff.ss == 2) ss.erase(e.ss.ff);
        if (e.ff.ss == 1)
        {
            int p = e.ff.ff, l = e.ss.ff, r = e.ss.ss;
            if (p != lp || l > lr)
            {
                int rep = ss.order_of_key(r + 1) - ss.order_of_key(l);
                ans += r - l + 1 - rep, lr = r;
            }
            else if (l > lr)
            {
                int rep = ss.order_of_key(r + 1) - ss.order_of_key(l);
                ans += r - l + 1 - rep, lr = r;
            }
            else
            {
                if (r > lr)
                {
                    int rep = ss.order_of_key(r + 1) - ss.order_of_key(lr + 1);
                    ans += r - lr - rep;
                }
                lr = max(lr, r);
            }
            lp = p;
        }
    }

    cout << ans << '\n';
}