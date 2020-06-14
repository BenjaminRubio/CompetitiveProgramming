#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
template <typename T, typename Comparator = less<T>>
using ordered_set = tree<T, null_type, Comparator, rb_tree_tag,
                         tree_order_statistics_node_update>;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, K;
vector<int> X;

int main()
{
    cin >> N >> K;

    multiset<int> rest;
    X.resize(N);
    rep(i, N) { cin >> X[i]; rest.insert(X[i]); }

    set<int> set;
    stack<int> stk;
    rep(i, N)
    {
        auto it = rest.find(X[i]);
        rest.erase(it);
        if (set.count(X[i])) continue;
        set.insert(X[i]);

        if (stk.empty()) stk.push(X[i]);
        else
        {
            while (!stk.empty())
            {
                if (X[i] > stk.top()) { stk.push(X[i]); break; }
                else
                {
                    if (rest.count(stk.top())) { set.erase(stk.top()); stk.pop(); }
                    else { stk.push(X[i]); break; }
                }
            }
            if (stk.empty()) stk.push(X[i]);
        }
    }

    stack<int> ans;
    while (!stk.empty()) { ans.push(stk.top()); stk.pop(); }
    cout << ans.top(); ans.pop();
    while (!ans.empty()) { cout << ' ' << ans.top(); ans.pop(); }
    cout << '\n';
}