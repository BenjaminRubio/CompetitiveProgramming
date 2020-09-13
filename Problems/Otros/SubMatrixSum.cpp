#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ff first
#define ss second

int R, C, X;
vector<vector<ll>> A, S;
vector<ll> P;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> R >> C >> X;

    bool sw = (R > C);

    A.assign(min(R, C), vector<ll>(max(R, C)));
    rep(i, R) rep(j, C)
    {
        if (sw) cin >> A[j][i];
        else cin >> A[i][j];
    } if (sw) swap(R, C);

    int ans = INT_MAX;
    rep(i, R)
    {
        P.assign(C, 0);
        repx(j, i, R)
        {
            ll a = 0;
            vector<pair<ll, int>> V;
            rep(k, C)
            {
                P[k] += A[j][k], a += P[k];

                int l = 0, r = V.size();
                while (l < r)
                {
                    int m = (l + r) / 2;
                    if (V[m].ff > a - X) r = m;
                    else l = m + 1;
                } l--;
                
                if (l >= 0 && V[l].ff <= a - X) ans = min(ans, (j - i + 1) * (k - V[l].ss));
                else if (l == -1 && a >= X) ans = min(ans, (j - i + 1) * (k + 1));

                while (!V.empty() && V.back().ff >= a) V.pop_back();
                V.emplace_back(a, k);
            }
        }
    }
    
    if (ans == INT_MAX) cout << -1 << '\n';
    else cout << ans << '\n';
}