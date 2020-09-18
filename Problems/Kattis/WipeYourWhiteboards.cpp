#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

ll gcdext(ll a, ll b, ll& x, ll& y) {
    ll r2, x2, y2, r1, x1, y1, r0, x0, y0, q;
    r2 = a, x2 = 1, y2 = 0, r1 = b, x1 = 0, y1 = 1;
    while (r1) {
        q = r2 / r1, r0 = r2 % r1;
        x0 = x2 - q * x1, y0 = y2 - q * y1;
        r2 = r1, x2 = x1, y2 = y1, r1 = r0, x1 = x0, y1 = y0;        
    }
    ll g = r2; x = x2, y = y2;
    if (g < 0) g = -g, x = -x, y = -y;
    return g;
}

ll T, R, S, Q, X, Y, G, s1, s2, t;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> R >> S >> Q;

        G = gcdext(R, S, X, Y);

        X *= Q / G, Y *= Q / G;

        ll M = R * -S / __gcd(R, -S);

        if (X <= 0 || Y <= 0)
        {
            t = max(-X / (M / R), -Y / (M / -S)) + 1ll;
            X += t * (M / R), Y += t * (M / -S);
        }

        t = min((X - 1ll) / (M / R), (Y - 1ll) / (M / -S));
        X -= t * (M / R), Y -= t * (M / -S);
        
        cout << X << ' ' << Y << '\n';
    }
}