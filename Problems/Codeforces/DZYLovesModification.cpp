#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
typedef long long ll;

ll N, M, K, P, aux;
vector<vector<ll>> a;
priority_queue<ll> qr, qc;
vector<ll> R, C;

int main()
{
    cin >> N >> M >> K >> P;

    a.assign(N, vector<ll>(M));
    rep(i, N) rep(j, M) cin >> a[i][j];

    rep(i, N)
    {
        ll s = 0;
        rep(j, M) s += a[i][j];
        qr.push(s);
    }
    rep(j, M)
    {
        ll s = 0;
        rep(i, N) s += a[i][j];
        qc.push(s);
    }

    R.assign(K + 1, 0); C.assign(K + 1, 0);
    rep(i, K)
    {
        aux = qr.top(); qr.pop();
        R[i + 1] = aux + R[i];
        qr.push(aux - M * P);

        aux = qc.top(); qc.pop();
        C[i + 1] = aux + C[i];
        qc.push(aux - N * P);
    }

    ll ans = LLONG_MIN;
    rep(i, K + 1) ans = max(ans, R[i] + C[K - i] - i * (K - i) * P);

    cout << ans << '\n';
}