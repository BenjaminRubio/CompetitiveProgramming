#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n, x;
vector<int> a, b, c;

int main()
{
    cin >> n;

    a.resize(n);
    rep(i, n) { cin >> x; a[x - 1] = i; }

    b.resize(n);
    rep(i, n) { cin >> x; b[x - 1] = i; }

    c.assign(n, 0);
    rep(i, n) c[(a[i] - b[i] + n) % n]++;

    int ans = -1;
    rep(i, n) ans = max(ans, c[i]);

    cout << ans << '\n';
}