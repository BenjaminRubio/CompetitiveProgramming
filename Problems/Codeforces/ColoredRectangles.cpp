#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

ll R, G, B;
vector<ll> r, g, b;

ll DP[201][201][201];

ll dp(int i, int j, int k)
{
    if (DP[i][j][k] != -1) return DP[i][j][k];

    ll ans = 0;
    if (i < R && j < G) ans = max(ans, r[i] * g[j] + dp(i + 1, j + 1, k));
    if (i < R && k < B) ans = max(ans, r[i] * b[k] + dp(i + 1, j, k + 1));
    if (j < G && k < B) ans = max(ans, g[j] * b[k] + dp(i, j + 1, k + 1));

    return DP[i][j][k] = ans;
}

int main()
{
    cin >> R >> G >> B;

    r.resize(R); rep(i, R) cin >> r[i];
    g.resize(G); rep(i, G) cin >> g[i];
    b.resize(B); rep(i, B) cin >> b[i];

    sort(r.rbegin(), r.rend());
    sort(g.rbegin(), g.rend());
    sort(b.rbegin(), b.rend());

    memset(DP, -1, sizeof DP);

    cout << dp(0, 0, 0) << '\n';
}