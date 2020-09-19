#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

ll T, X;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> X; X--;

        ll ans = 1, s = 1, b = 1;
        while (X >= 4ll * b + s + 1ll)
        {
            X -= 4ll * b + s + 1ll;
            b = 4ll * b + s + 1ll;
            s = 2ll * s + 1ll;
            ans++;
        }

        cout << ans << '\n';
    }
}