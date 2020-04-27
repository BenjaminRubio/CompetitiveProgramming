#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

ll T, x, y, a, b;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> x >> y >> a >> b;

        ll ans = a * x + a * y;
        ans = min(ans, b * min(x, y) + a * abs(x - y));
        cout << ans << '\n';
    }
}