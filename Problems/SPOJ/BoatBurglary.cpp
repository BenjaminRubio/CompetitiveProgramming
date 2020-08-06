#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define ff first
#define ss second

ll T, N, D;
vector<ll> W;

int main()
{
    cin >> T;
    rep(t, T)
    {
        cout << "Case #" << t + 1 << ": ";

        cin >> N >> D;

        W.resize(N);
        rep(i, N) cin >> W[i];

        map<ll, set<ll>> m1, m2;
        rep(i, 1ll << min(15ll, N))
        {
            ll c = 0; ll s = 0;
            rep(j, min(15ll, N)) if (i & (1ll << j)) s += W[j], c++;
            m1[s].insert(c);
        }
        rep(i, 1ll << max(N - 15ll, 0ll))
        {
            ll c = 0; ll s = 0;
            rep(j, N - 15ll) if (i & (1ll << j)) s += W[j + 15], c++;
            m2[s].insert(c);
        }

        ll ans;
        if (m1[D].size() > 1 || m2[D].size() > 1) { cout << "AMBIGIOUS\n"; goto next; }
        if (!m1[D].empty() && !m2[D].empty() && m1[D] != m2[D]) { cout << "AMBIGIOUS\n"; goto next; }

        ans = (!m1[D].empty() ? *m1[D].begin() : (!m2[D].empty() ? *m2[D].begin() : -1));
        for (auto &e : m1)
        {
            if (e.ff < D && !e.ss.empty() && !m2[D - e.ff].empty())
            {
                if (e.ss.size() > 1 || m2[D - e.ff].size() > 1) { cout << "AMBIGIOUS\n"; goto next; }
                int c1 = *e.ss.begin(), c2 = *m2[D - e.ff].begin();
                if (ans == -1) ans = c1 + c2;
                else if (ans != c1 + c2) { cout << "AMBIGIOUS\n"; goto next; }
            }
        }

        if (ans == -1) cout << "IMPOSSIBLE\n";
        else cout << ans << '\n';

        next:
        continue;
    }
}