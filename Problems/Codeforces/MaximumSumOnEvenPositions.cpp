#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0ll; i < (ll)n; i++)

ll T, N;
vector<ll> a;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        a.resize(N); ll ans = 0;
        rep(i, N) cin >> a[i];
        rep(i, N) if (i % 2 == 0) ans += a[i];

        vector<ll> b1, b2;

        ll i = 0ll;
        while (i < N - 1ll)
        {
            b1.push_back(a[i + 1ll] - a[i]);
            i += 2ll;
        }

        ll M = 0, m = 0ll;
        rep(i, b1.size())
        { 
            m += b1[i]; 
            M = max(m, M);
            m = max(m, 0ll);
        }
        
        ll aux = M;

        i = 1ll;
        while (i < N - 1ll)
        {
            b2.push_back(a[i] - a[i + 1ll]);
            i += 2ll;
        }

        M = 0, m = 0ll;
        rep(i, b2.size())
        { 
            m += b2[i]; 
            M = max(m, M);
            m = max(m, 0ll);
        }
        ans += max(aux, M);

        cout << ans << '\n';
    }
}