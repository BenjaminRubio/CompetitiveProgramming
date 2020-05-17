#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repx(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
typedef long long ll;

ll A, B, C, D;

int main()
{
    cin >> A >> B >> C >> D;

    ll R = (B - A + 1ll) * (C - B + 1ll);

    ll ans = 0;
    repx(c, C, D + 1ll) 
    {
        if (c - B >= A && c - B <= C)
        {
            ll x = c - B - A + 1ll;
            if (c - B >= B)
            {
                x = C - (c - B);
                ans += x * (x + 1ll) / 2ll;
                if (B - A < C - B && x > B - A)
                {
                    x -= (B - A + 1ll);
                    ans -= x * (x + 1ll) / 2ll;
                }
            }
            else
            {
                ans += R - x * (x + 1ll) / 2ll;
                if (B - A > C - B && x > C - B + 1ll)
                {
                    x -= (C - B + 1ll);
                    ans += x * (x + 1ll) / 2ll;
                }
            }
        }
        else if (c - B < A) ans += R;
        // cerr << ans << '\n';
    }

    cout << ans << '\n';
}