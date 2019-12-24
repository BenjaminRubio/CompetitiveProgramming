#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n;
vector<int> a, r, l;

int main()
{
    cin >> n;

    a.resize(n);
    rep(i, n) cin >> a[i];

    r.assign(n, 1);
    rep(i, n) if (i > 0 && a[i] > a[i - 1]) r[i] += r[i - 1];

    l.assign(n, 1);
    rep(i, n) if (i > 0 && a[n - i - 1] < a[n - i]) l[n - i - 1] += l[n - i];

    int ans = 0;

    rep(i, n)
    { 
        ans = max({ans, r[i], l[i]});
        if (i > 0 && i < n - 1)
        {
            if (a[i - 1] < a[i + 1])
                ans = max(ans, r[i - 1] + l[i + 1]);
        }
    }

    cout << ans << '\n';
}