#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

ll T, n, g, b;

int main()
{
    cin >> T;
    rep(t, T)
    {
        cin >> n >> g >> b;

        ll m = n - n / 2;
        ll c = m / g;
        ll r = m % g;
        ll aux = c * g + (c - 1) * b + bool(r) * b + r;
        if (aux < n) aux = n;

        cout << aux << '\n';
    }
}