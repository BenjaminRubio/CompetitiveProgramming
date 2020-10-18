#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N;
vector<vector<ll>> C;

int main()
{
    cin >> T;
    rep(tt, T)
    {
        cout << "Case #" << tt + 1 << ": ";

        cin >> N;

        C.assign(N, vector<ll>(N));
        rep(i, N) rep(j, N) cin >> C[i][j];

        ll ans = 0;
        rep(i, N)
        {
            ll aux = 0;
            rep(j, N) if (i + j < N) aux += C[i + j][j];

            ans = max(ans, aux);

            aux = 0;
            rep(j, N) if (i + j < N) aux += C[j][i + j];

            ans = max(ans, aux);
        }

        cout << ans << '\n';
    }
}