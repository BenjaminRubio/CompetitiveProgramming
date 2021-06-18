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

const ll MOD = 1e9 + 7;

ll add(ll x, ll y) { return (x + y) % MOD; }
ll mul(ll x, ll y) { return (x * y) % MOD; }

int T, X, Y;

ll DP[32][2][2][2];
ll dp(int i, int f1, int f2, int o)
{
    if (i == -1) return 1;
    if (DP[i][f1][f2][o] != -1) return DP[i][f1][f2][o];

    int x_ = f1 ? ((X >> i) & 1) : 1;
    int y_ = f2 ? ((Y >> i) & 1) : 1;

    ll ans = 0;
    rep(x, x_ + 1) rep(y, y_ + 1) if (x + y < 2)
    {
        if (o == 0 && max(x, y) == 1) ans = add(ans, mul(i + 1, dp(i - 1, f1 & (x == x_), f2 & (y == y_), 1)));
        else if (o == 0) ans = add(ans, dp(i - 1, f1 & (x == x_), f2 & (y == y_), 0));
        else ans = add(ans, dp(i - 1, f1 & (x == x_), f2 & (y == y_), 1));
    }
    return DP[i][f1][f2][o] = ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> X >> Y;

        memset(DP, -1, sizeof DP);
        cout << add(dp(31, 1, 1, 0), MOD - 1) << '\n';
    }   
}
