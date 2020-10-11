#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N;
vector<ll> A, S, S1, S2;

int main()
{
    cin >> N;

    A.resize(N);
    rep(i, N) cin >> A[i];

    S.assign(N + 1, 0);
    rep(i, N) S[i + 1] = S[i] + A[i];

    if (S[N] % 3ll) { cout << 0 << '\n'; return 0; }
    ll T = S[N] / 3;

    ll p = 0; S1.resize(N); S2.resize(N);
    rep(i, N)
    {
        S1[i] = p + (S[i + 1] == T);
        S2[N - i - 1] = (S[N] - S[N - i] == T);

        p = S1[i];
    }
    
    ll ans = 0;
    rep(i, N - 1) if (i && S2[i]) ans += S1[i - 1];

    cout << ans << '\n';
}