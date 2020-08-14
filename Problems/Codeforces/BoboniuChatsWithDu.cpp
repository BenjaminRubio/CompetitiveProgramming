#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

ll N, d, m, a;

int main()
{
    cin >> N >> d >> m;

    priority_queue<ll> q;
    vector<ll> v;
    rep(i, N)
    {
        cin >> a;
        if (a > m) q.push(a);
        else v.push_back(a);
    }

    sort(v.begin(), v.end());

    vector<ll> s(v.size() + 1); s[0] = 0;
    rep(i, v.size()) s[i + 1] = s[i] + v[i];

    int o = q.size(), M = s.size(), c = o ? (o - 1) / (d + 1) + 1 : 0, i = 0;

    ll ans = s[M - 1];
    rep(_, c) { ans += q.top(); q.pop(); }

    cerr << ans << ' ';

    ll aux = ans;
    if (!q.empty() && i < M - (d + 1 - (o - 1) % (d + 1)))
    {
        aux -= s[i + d + 1 - (o - 1) % (d + 1)] - s[i], i += d + 1 - (o - 1) % (d + 1);
        aux += q.top(); q.pop();
        ans = max(ans, aux);
    }
    while (!q.empty() && i < M - d - 1)
    {
        aux -= s[i + d + 1] - s[i], i += d + 1;
        aux += q.top(); q.pop();
        ans = max(ans, aux);
    }

    cout << ans << '\n';
}