#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

int main()
{
    ll ans, N = LLONG_MAX;

    rep(i, 10000) rep(j, 10000) if (i && j)
    {
        ll aux = abs(2000000ll - ((i * (i + 1ll)) / 2ll) * ((j * (j + 1ll)) / 2ll));
        if (aux < N) ans = i * j, N = aux;
    }

    cout << ans << '\n';
    cout << N << '\n';
}