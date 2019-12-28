#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n, m;
vector<int> a, b, order;

int main()
{
    cin >> T;
    rep(t, T)
    {
        cin >> n >> m;

        a.resize(n);
        rep(i, n) cin >> a[i];

        order.resize(n + 1);
        rep(i, n) order[a[i]] = i;

        b.resize(m);
        rep(i, m) cin >> b[i];

        long long ans = 0;
        int last = -1;
        rep(i, m)
        {
            if (order[b[i]] > last)
            {
                ans += 2 * (order[b[i]] - (i - 1)) - 1;
                last = order[b[i]];
            }
            else
                ans += 1;
        }

        cout << ans << '\n';
    }
}