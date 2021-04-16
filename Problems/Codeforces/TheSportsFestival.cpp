#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

ll N;
vector<ll> S;

ll DP[2010][2010];

ll dp(int i, int j)
{
    if (i == j) return 0;
    if (DP[i][j] != -1) return DP[i][j];
    return DP[i][j] = S[j] - S[i] + min(dp(i + 1, j), dp(i, j - 1));
}

int main()
{
    cin >> N;

    S.resize(N);
    rep(i, N) cin >> S[i];

    sort(S.begin(), S.end());

    memset(DP, -1, sizeof DP);

    cout << dp(0, N - 1) << '\n';
}
