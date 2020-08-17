#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

ll T, N;
vector<ll> A;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        A.resize(N);
        rep(i, N) cin >> A[i];

        ll ans = 0;
        rep(i, N - 1) ans += max(A[N - i - 2] - A[N - i - 1], 0ll);

        cout << ans << '\n';
    }
}