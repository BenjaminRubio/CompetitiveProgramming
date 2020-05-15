#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
typedef long long ll;

ll N;
vector<ll> C, T;

int main()
{
    cin >> N;

    C.resize(N); T.resize(N);
    rep(i, N - 1) cin >> C[i];
    rep(i, N) cin >> T[i];

    ll ans = 0, m = 1e9, t = 0;
    rep(i, N)
    {
        ans += C[i];
        while (T[i] - t > 0) { t += 2; ans += 2ll * m; }
        m = min(m, C[i]); t++;
    }

    cout << ans << '\n';
}