#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n;
vector<ll> a;

int main()
{
    cin >> n;

    a.resize(n);
    rep(i, n) cin >> a[i];

    ll ans = 0;
    rep(i, n) rep(j, n) rep(k, n) ans = max(ans, a[i] | a[j] | a[k]);

    cout << ans << '\n';
}