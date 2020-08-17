#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

ll T, N, K;
vector<ll> A;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> K;

        ll m = LLONG_MAX, M = LLONG_MIN;
        A.resize(N);
        rep(i, N) { cin >> A[i]; m = min(m, A[i]), M = max(M, A[i]); }

        if (K & 1ll) rep(i, N) cout << M - A[i] << ' ';
        else rep(i, N) cout << A[i] - m << ' ';
        cout << '\n';
    }
}