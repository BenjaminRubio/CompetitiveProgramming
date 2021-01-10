#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

ll const MOD = 1e9 + 7;

inline ll mul(ll x, ll y) { return (x * y) % MOD; }
inline ll add(ll x, ll y) { return (x + y) % MOD; }

int N, K, Q, i, x;
vector<ll> A;

ll DP[5010][5010];

ll dp(ll i, ll k)
{
    if (k == 0) return 1;

    if (DP[i][k] != -1) return DP[i][k];
    
    ll ans;
    if (i == 0) ans = dp(i + 1, k - 1);
    else if (i == N - 1) ans = dp(i - 1, k - 1);
    else ans = add(dp(i - 1, k - 1), dp(i + 1, k - 1));
    return DP[i][k] = ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K >> Q; K++;

    A.resize(N); rep(i, N) cin >> A[i];

    memset(DP, -1, sizeof DP);

    vector<ll> T(N, 0), C(N, 1), P(N, 1);
    rep(_, K)
    {
        rep(i, N) T[i] = add(T[i], mul(dp(i, K - _ - 1), P[i]));

        rep(i, N)
        {
            ll aux = 0;
            if (i) aux = add(aux, P[i - 1]);
            if (i < N - 1) aux = add(aux, P[i + 1]);
            C[i] = aux;
        }

        swap(C, P);
    }

    ll ans = 0;
    rep(i, N) ans = add(ans, mul(T[i], A[i]));

    while (Q--)
    {
        cin >> i >> x; i--;
        ans = add(ans, mul(-1, mul(A[i], T[i])));

        A[i] = x;
        ans = add(ans, mul(A[i], T[i]));

        if (ans < 0) ans += MOD;

        cout << ans << '\n';
    }
}