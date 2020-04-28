#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

const ll MOD = 1e9 + 7;

int N;
vector<ll> L, R, S;
ll DP[100000][2][2];

ll dp(int i, int a, int b)
{
    if (i == -1) return a == b;
    if (S[i] != -1 and a != S[i]) return 0ll;

    if (DP[i][a][b] != -1ll) return DP[i][a][b];

    ll ans = 0ll;
    bool same = (a == S[i]);
    if ((same || a == 0) && b == 0)
        ans = ans + dp(L[i], 1, 1) * dp(R[i], 1, 1);
    if ((same || a == 0) && b == 1)
        ans = ans + dp(L[i], 1, 0) * dp(R[i], 1, 1) +
                    dp(L[i], 1, 1) * dp(R[i], 1, 0) +
                    dp(L[i], 1, 0) * dp(R[i], 1, 0);
    if ((same || a == 1) && b == 0)
        ans = ans + dp(L[i], 0, 1) * dp(R[i], 0, 1) +
                    dp(L[i], 1, 1) * dp(R[i], 0, 1) +
                    dp(L[i], 0, 1) * dp(R[i], 1, 1);
    if ((same || a == 1) && b == 1)
        ans = ans + dp(L[i], 0, 0) * dp(R[i], 0, 0) +
                    dp(L[i], 0, 0) * dp(R[i], 0, 1) +
                    dp(L[i], 0, 0) * dp(R[i], 1, 0) +
                    dp(L[i], 0, 0) * dp(R[i], 1, 1) +
                    dp(L[i], 0, 1) * dp(R[i], 1, 0) +
                    dp(L[i], 1, 0) * dp(R[i], 0, 1) +
                    dp(L[i], 1, 1) * dp(R[i], 0, 0) +
                    dp(L[i], 1, 0) * dp(R[i], 0, 0) +
                    dp(L[i], 0, 1) * dp(R[i], 0, 0);
    
    return DP[i][a][b] = ans % MOD;
}

int main()
{
    memset(DP, -1ll, sizeof DP);

    cin >> N;

    L.resize(N); R.resize(N); S.resize(N);
    rep(i, N) cin >> L[i] >> R[i] >> S[i];
    rep(i, N) L[i]--, R[i]--;

    ll ans = (dp(0, 0, 1) + dp(0, 1, 0)) % MOD;
    cout << ans << '\n';
}