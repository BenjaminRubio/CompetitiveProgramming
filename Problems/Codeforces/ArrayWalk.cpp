#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

ll T, N, K, Z;
vector<ll> A;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> K >> Z;

        A.resize(N);
        rep(i, N) cin >> A[i];

        ll ans = 0;
        rep(z, Z + 1)
        {
            ll aux1 = A[0], aux2 = A[0], M = 0;
            if (K >= 2 * z)
            {
                rep(i, K - 2 * z) aux1 += A[i + 1], M = max(M, A[i] + A[i + 1]);
                aux1 += z * M, M = 0;
            }
            if (z && K > 2 * (z - 1) + 1)
            {
                rep(i, K - 2 * (z - 1) - 1) aux2 += A[i + 1], M = max(M, A[i] + A[i + 1]);
                aux2 += (z - 1) * M + A[K - 2 * (z - 1) - 2];
            }
            ans = max({ans, aux1, aux2});
        }

        cout << ans << '\n';
    }
}