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

int N, X, Y, Z;
char c;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    int ans = 0;

    int S = 0;
    cin >> c >> X >> c >> Y;
    S += 100 * X + Y;
    rep(_, N)
    {
        cin >> c >> X >> c >> Y;
        S += 100 * X + Y;

        if (S % 100) ans++;
    }    

    cout << ans << '\n';
}
