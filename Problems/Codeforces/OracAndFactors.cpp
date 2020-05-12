#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
typedef long long ll;

int T;
ll n, k;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> k;

        rep(i, n) if (i && n % (i + 1ll) == 0ll)
        {
            n += (i + 1ll);
            break;
        }

        n += (k - 1ll) * 2ll;

        cout << n << '\n';
    }
}