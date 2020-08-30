#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repx(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)

ll N;
vector<ll> A, S;

int main()
{
    cin >> N;

    A.resize(N);
    rep(i, N) cin >> A[i];

    S.assign(N, 1);
    rep(i, N) if (A[i] < 0) S[i] = -1, A[i] = -1ll * A[i];

    if (N == 1)
    {
        cout << 1 << ' ' << 1 << '\n';
        cout << 0 << '\n';
        cout << 1 << ' ' << 1 << '\n';
        cout << 0 << '\n';
        cout << 1 << ' ' << 1 << '\n';
        cout << -1ll * S[0] * A[0] << '\n';
        return 0;
    }

    cout << 1 << ' ' << 1 << '\n';
    cout << S[0] * (N - A[0] % N) << '\n';
    A[0] += N - A[0] % N;

    cout << 2 << ' ' << N << '\n';
    repx(i, 1, N)
    {
        cout << S[i] * (N - 1ll) * (A[i] % N) << ' ';
        A[i] += (N - 1ll) * (A[i] % N);
    }
    cout << '\n';

    cout << 1 << ' ' << N << '\n';
    rep(i, N) cout << -1ll * S[i] * A[i] << ' ';
}