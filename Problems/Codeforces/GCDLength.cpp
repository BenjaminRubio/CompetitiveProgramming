#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)

ll T, a, b, c;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> a >> b >> c;

        ll gcd = 1;
        rep(_, c - 1) gcd *= 10ll;

        ll A = gcd, B = gcd;
        while (((int)log10(A) + 1) < a) A *= 2ll;
        while (((int)log10(B) + 1) < b) B *= 3ll;

        cout << A << ' ' << B << '\n';
    }
}