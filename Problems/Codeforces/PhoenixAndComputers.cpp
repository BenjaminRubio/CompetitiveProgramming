#include <bits/stdc++.h>
using namespace std;

using ul = unsigned long long;
using ll = long long;
using db = double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<db, db>;

using vp = vector<pii>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<db>;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define all(x) begin(x), end(x)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

ll N, M;
ll P[410], C[410][410], DP[410][410];

inline ll add(ll x, ll y) { return (x + y) % M; }
inline ll mul(ll x, ll y) { return (x * y) % M; }

ll dp(ll s, ll k)
{
    if (s < 0) return k == 0;
    if (s == 0) return 0;
    if (k > s) return 0;

    if (DP[s][k] != -1) return DP[s][k];

    ll ans = 0;
    rep(j, k + 1) if (j)
    {
        ll aux = mul(dp(s - j - 1, k - j), mul(C[k][j], P[j - 1]));
        ans = add(ans, aux);
    }
    return DP[s][k] = ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    rep(m, 400 + 1) if (m)
    {
        C[m][0] = C[m][m] = 1;
        rep(k, m) if (k) C[m][k] = add(C[m - 1][k], C[m - 1][k - 1]);
    }
    P[0] = 1; rep(i, 400) P[i + 1] = mul(P[i], 2);

    memset(DP, -1, sizeof DP);

    ll ans = 0;
    rep(i, N + 1) ans = add(ans, dp(N, i));

    cout << ans << '\n';
}
