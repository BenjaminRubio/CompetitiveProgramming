#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define ff first
#define ss second
typedef long long ll;

int n;
vector<ll> H, L, R;
stack<pair<ll, ll>> l, r;

int main()
{
    while (cin >> n)
    {
        if (n == 0) break;

        H.resize(n); L.resize(n); R.resize(n);
        rep(i, n) cin >> H[i];

        l.emplace(-1, -1);
        rep(i, n)
        {
            while (l.top().ff >= H[i]) l.pop();
            L[i] = l.top().ss;
            l.push({H[i], i});
        }

        r.emplace(-1, n);
        rep(i, n)
        {
            while (r.top().ff >= H[n - i - 1]) r.pop();
            R[n - i - 1] = r.top().ss;
            r.push({H[n - i - 1], n - i - 1});
        }

        ll ans = 0;
        rep(i, n) ans = max(ans, H[i] * (R[i] - L[i] - 1));

        cout << ans << '\n';

        while (!l.empty()) l.pop();
        while (!r.empty()) r.pop();
    }    
}