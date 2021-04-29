#include <bits/stdc++.h>
using namespace std;

using ul = unsigned long long;
using ll = long long;
using db = double;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;

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

int N;
vl A, B, S;

ll DP[5010][5010];

ll dp(int i, int j)
{
    if (i <= j) return j < i ? 0 : A[i] * B[i];
    if (DP[i][j] != -1) return DP[i][j];
    return DP[i][j] = A[i] * B[j] + A[j] * B[i] + dp(i + 1, j - 1);
}

int main()
{
    cin >> N;

    A.resize(N), B.resize(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    S.assign(N + 1, 0);
    rep(i, N) S[i + 1] = S[i] + A[i] * B[i];

    memset(DP, -1, sizeof DP);

    ll ans = S[N];
    rep(i, N) rep(j, N) if (j >= i)
        ans = max(ans, S[N] + dp(i, j) - (S[j + 1] - S[i]));

    cout << ans << '\n';
}
