#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

ll T, P, F, cs, cw, s, w;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> P >> F >> cs >> cw >> s >> w;

        if (s > w) swap(s, w), swap(cs, cw);

        ll ans = 0;
        rep(i, min(cs, P / s) + 1)
        {
            ll wp = (P - i * s) / w, sf = min(cs - i, F / s), wf = min((F - s * sf) / w, cw - wp);
            ans = max(ans, i + wp + sf + wf);
        }

        cout << ans << '\n';
    }
}