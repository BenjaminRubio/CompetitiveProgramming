#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

ll T, a, K;

ll step(ll a)
{
    ll x = a;
    ll m = 10, M = 0;
    while (x)
    {
        ll d = x % 10;
        m = min(m, d); M = max(M, d);
        x /= 10;
    }
    return m * M;
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> a >> K; K--;

        while (K--)
        {
            ll s = step(a);
            if (s == 0) break;
            a = a + step(a);
        }

        cout << a << '\n';
    }
}