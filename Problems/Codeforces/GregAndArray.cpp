#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

ll N, M, K, x, y;
vector<ll> A, C, U, L, R, D;

int main()
{
    cin >> N >> M >> K;

    A.resize(N);
    rep(i, N) cin >> A[i];

    L.resize(M); R.resize(M); D.resize(M);
    rep(i, M) { cin >> L[i] >> R[i] >> D[i]; L[i]--; }

    U.assign(M + 1, 0);
    rep(i, K)
    {
        cin >> x >> y; x--;
        U[x]++, U[y]--;
    }

    ll c = 0;
    C.assign(N + 1, 0);
    rep(i, M)
    {
        c += U[i];
        C[L[i]] += D[i] * c, C[R[i]] -= D[i] * c;
    }

    c = 0;
    rep(i, N)
    {
        c += C[i];
        cout << A[i] + c << ' ';
    }
    cout << '\n';
}