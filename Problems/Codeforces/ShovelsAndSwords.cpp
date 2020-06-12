#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

ll T, a, b;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> a >> b;

        if (a > b) swap(a, b);
        if (b > 2 * a) { cout << a << '\n'; continue; }
        ll ans = (b - a);
        a -= ans;
        ans += (2 * (a / 3) + (a % 3 > 1));
        cout << ans << '\n';
    }
}