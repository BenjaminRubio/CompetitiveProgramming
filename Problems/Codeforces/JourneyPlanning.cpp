#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

ll n, x;
vector<ll> b;
map<ll, ll> cnt;

int main()
{
    cin >> n;

    b.resize(n);
    rep(i, n)
    {
        cin >> x; x -= i;
        b[i] = x;
        if (cnt.find(x) != cnt.end()) cnt[x] += x + i;
        else cnt[x] = x + i;
    }

    ll ans = 0;
    rep(i, n) ans = max(ans, cnt[b[i]]);

    cout << ans << '\n';
}