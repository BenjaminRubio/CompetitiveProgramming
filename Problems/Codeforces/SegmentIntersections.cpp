#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

ll T, N, K, l1, r1, l2, r2;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> K >> l1 >> r1 >> l2 >> r2;
        if (l1 > l2) swap(l1, l2), swap(r1, r2);

        ll off = max(0ll, l2 - r1), on = max(r1, r2) - l1 - max(min(r1, r2) - l2, 0ll);
        ll aux = max(0ll, min(r1, r2) - l2) * N, ans = 0;

        if (aux >= K) { cout << 0 << '\n'; continue; }
        if (aux + on >= K) { cout << off + K - aux << '\n'; continue; }

        aux += on, ans += on + off;
        ll d = min(N - 1, (K - aux) / on);
        aux += d * on, ans += d * (on + off);
        if (d < N - 1) ans += min(2ll * (K - aux), off + (K - aux));
        else ans += 2ll * (K - aux);

        cout << ans << '\n';
    }
}