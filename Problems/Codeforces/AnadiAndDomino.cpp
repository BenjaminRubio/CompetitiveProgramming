#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n, m, a, b;
vector<vector<int>> g;

int main()
{
    cin >> n >> m;

    if (n < 7) { cout << m << '\n'; return 0; }

    g.assign(n, {});
    rep(i, m)
    {
        cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int ans = 0;
    rep(i, n) rep(j, n) if (i != j)
    {
        int M1 = g[i].size(), M2 = g[j].size();

        bool b = 0;
        set<int> to;
        for (int x : g[i])
        {
            if (j == x) b = 1;
            else to.insert(x);
        }
        for (int x : g[j])
        {
            if (i == x) b = 1;
            else to.insert(x);
        }

        ans = max(ans, m - M1 - M2 + 2 * b + (int)to.size());
    }

    cout << ans << '\n';
}