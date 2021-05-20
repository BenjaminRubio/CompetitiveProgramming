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

vector<vector<int>> D;

int DP[1000010];

int dp(int r)
{
    if (r == 0) return 0;
    if (DP[r] != -1) return DP[r];

    int ans = 0;
    for (int d : D[r]) ans = max(ans, dp(r / d - 1) + 1);

    return DP[r] = ans;
}

void test_case()
{
    int N; cin >> N;
    
    int ans = 0;
    for (int d : D[N]) if (d > 2)
    {
        // cerr << d << ' ' << dp(N / d - 1) + 1 << endl;
        ans = max(ans, dp(N / d - 1) + 1);
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    D.assign(1000001, {});
    for (int i = 2; i <= 1000000; i++)
    {
        int d = i;
        while (d <= 1000000)
        {
            D[d].pb(i);
            d += i;
        }
    }

    memset(DP, -1, sizeof DP);

    int num_tests; cin >> num_tests;
    rep(test, num_tests)
    {
        cout << "Case #" << test + 1 << ": ";
        test_case();
    }
}
