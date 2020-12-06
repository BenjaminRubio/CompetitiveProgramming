#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

ll T, N, P, K, x, y, DP[100010];
vector<bool> A; char a;

ll dp(int i)
{
    if (i >= N) return 0;
    if (DP[i] != -1) return DP[i];

    return DP[i] = (A[i] ? 0ll : x) + dp(i + K);
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> P >> K;

        A.resize(N);
        rep(i, N) { cin >> a; A[i] = (a == '1'); }

        cin >> x >> y;

        memset(DP, -1, sizeof DP);
        ll ans = LLONG_MAX;
        for (ll i = P - 1ll; i < N; i++)
            ans = min(ans, (y * (i - (P - 1ll))) + dp(i));

        cout << ans << '\n';
    }
}