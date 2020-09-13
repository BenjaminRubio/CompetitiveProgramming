#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int T, N;
vector<int> A;

ll K, F[51], DP[51], INF = LLONG_MAX;

ll add(ll &a, const ll &b) { return (a > INF - b) ? INF : a + b; }
ll mul(ll &a, const ll &b) { return (a > INF / b) ? INF : a * b; }

ll dp(int i)
{
    if (DP[i] != -1) return DP[i];

    ll ans = 0;
    repx(j, i, N) ans += dp(j);
    return DP[i] = ans;
}

int main()
{
    F[0] = 1; rep(i, 50) F[i + 1] = mul(F[i], i + 1);

    // cin >> T;
    // while (T--)
    // {
    //     cin >> N >> K;

    //     A.resize(N); int i = 0;
    //     while ()
    // }
}