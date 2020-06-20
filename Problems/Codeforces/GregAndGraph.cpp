#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

const ll INF = 1e15;

ll N, u;
vector<vector<ll>> D, D_;

int main()
{
    cin >> N;

    D.resize(N, vector<ll>(N));
    rep(i, N) rep(j, N) cin >> D[i][j];

    D_.assign(N, vector<ll>(N, INF));

    stack<ll> s;
    rep(_, N) { cin >> u; u--; s.push(u); }

    ll sum = 0;
    vector<ll> a;
    stack<ll> ans;
    rep(k, N)
    {
        u = s.top(); s.pop(); D_[u][u] = 0;

        rep(i, k)
        {
            ll m = D[u][a[i]];
            rep(j, k) m = min(m, D[u][a[j]] + D_[a[j]][a[i]]);
            D_[u][a[i]] = m, sum += m;

            m = D[a[i]][u];
            rep(j, k) m = min(m, D_[a[i]][a[j]] + D[a[j]][u]);
            D_[a[i]][u] = m, sum += m;
        }

        rep(i, k) rep(j, k) if (i != j)
        {
            ll aux = D_[a[i]][u] + D_[u][a[j]];
            if (D_[a[i]][a[j]] > aux)
                sum += aux - D_[a[i]][a[j]], D_[a[i]][a[j]] = aux;
        }

        ans.push(sum);
        a.push_back(u);
    }
    
    rep(_, N) { cout << ans.top() << ' '; ans.pop(); }
    cout << '\n';
}