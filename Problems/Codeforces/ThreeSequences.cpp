#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

ll N, Q, l, r, x;
vector<ll> A, D;

int main()
{
    cin >> N;

    A.resize(N);
    rep(i, N) cin >> A[i];

    D.assign(N + 1, 0); ll U = 0;
    rep(i, N - 1) { D[i + 1] = A[i + 1] - A[i]; if (D[i + 1] > 0) U += D[i + 1]; }

    cout << (U + A[0] + ((U + A[0] > 0) ? 1ll : 0)) / 2ll << '\n';
    
    cin >> Q;
    rep(_, Q)
    {
        cin >> l >> r >> x; l--, r--;
        if (l && D[l] > 0) U -= D[l];
        D[l] += x;
        if (l && D[l] > 0) U += D[l];

        if (r < N - 1 && D[r + 1] > 0) U -= D[r + 1];
        D[r + 1] -= x;
        if (r < N - 1 && D[r + 1] > 0) U += D[r + 1];

        if (l == 0) A[0] += x;

        cout << (U + A[0] + ((U + A[0] > 0) ? 1ll : 0)) / 2ll << '\n';
    }
}