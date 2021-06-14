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

string S;

int DP[1010][2];

int dp(int i, int c)
{
    if (i == -1) return c;
    if (DP[i][c] != -1) return DP[i][c];

    int d = S[i] - '0';
    if ((d == 0 && c == 0) || (d == 9 && c == 1)) return DP[i][c] = dp(i - 1, c);

    d += c;
    return DP[i][c] = min(dp(i - 1, 1) + 10 - d, dp(i - 1, 0) + d);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> S;

    memset(DP, -1, sizeof DP);
    cout << dp(S.size() - 1, 0) << '\n';    
}
