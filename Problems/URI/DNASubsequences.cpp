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

struct RH
{
    int B = 1777771, M[2] = {999727999, 1070777777}, P[2] = {325255434, 10018302};
    vi H[2], I[2];
    RH() {}
    RH(string &s)
    {
        int N = s.size(); rep(k, 2)
        {
            H[k].resize(N + 1), I[k].resize(N + 1);
            H[k][0] = 0, I[k][0] = 1; ll b = 1;
            rep(i, N + 1) if (i)
            {
                H[k][i] = (H[k][i - 1] + b * s[i - 1]) % M[k];
                I[k][i] = (1LL * I[k][i - 1] * P[k]) % M[k];
                b = (b * B) % M[k];
            }
        }
    }
    ll get(int l, int r)  // inclusive - exclusive
    {
        ll h0 = (H[0][r] - H[0][l] + M[0]) % M[0];
        h0 = (1LL * h0 * I[0][l]) % M[0];
        ll h1 = (H[1][r] - H[1][r] + M[1]) % M[1];
        h1 = (1LL * h1 * I[1][l]) % M[1];
        return (h0 << 32) | h1;
    }
};

int K, N, M;
string A, B;
RH rha, rhb;

int DP[1010][1010][2];

int dp(int i, int j, int t)
{
    if (i >= N || j >= M) return 0;
    if (t && (i > N - K || j > M - K)) return 0;
    if (DP[i][j][t] != -1) return DP[i][j][t];

    int ans = max(dp(i + 1, j, 1), dp(i, j + 1, 1));
    if (t && rha.get(i, i + K) == rhb.get(j, j + K)) ans = max(ans, dp(i + K, j + K, 0) + K);
    else if (!t && A[i] == B[j]) ans = max(ans, dp(i + 1, j + 1, 0) + 1);
    return DP[i][j][t] = ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    while (cin >> K && K)
    {
        cin >> A >> B;
        N = A.size(), M = B.size();

        rha = RH(A), rhb = RH(B);
        memset(DP, -1, sizeof DP);
        cout << dp(0, 0, 1) << '\n';
    }
}
