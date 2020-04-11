#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

int n, m;
vector<int> p;

ll calc(int x)
{
    ll ans = 0;
    for (int i = 0; i < x; i += m) ans += 2ll * (p[x] - p[i]);
    for (int i = n - 1; i >= x; i -= m) ans += 2ll * (p[i] - p[x]);
    return ans;
}

int main()
{
    cin >> n >> m;

    p.resize(n);
    rep(i, n) cin >> p[i];

    int l = 0, r = n - 1;
    while (r - l > 2)
    {
        int m1 = (2 * l + r) / 3;
        int m2 = (l + 2 * r) / 3;

        if (calc(m1) > calc(m2)) l = m1;
        else if (calc(m2) > calc(m1)) r = m2;
        else l = m1, r = m2;
    }
    cout << min(calc(l), calc(r)) << '\n';
}