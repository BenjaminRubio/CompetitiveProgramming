#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0ll; i < (ll)n; i++)

ll T, r, g, b, w;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> r >> g >> b >> w;

        if ((r + g + b + w) % 2ll == 1ll)
        {
            ll s = (r % 2ll) + (g % 2ll) + (b % 2ll) + (w % 2ll);
            if (s == 1ll || (min({r, g, b}) > 0 && s == 3ll)) { cout << "Yes\n"; continue; }
        }
        else
        {
            ll s = (r % 2ll) + (g % 2ll) + (b % 2ll) + (w % 2ll);
            if (s == 0ll || (min({r, g, b}) > 0 && s == 4ll)) { cout << "Yes\n"; continue; }
        }
        cout << "No" << '\n';
    }
}