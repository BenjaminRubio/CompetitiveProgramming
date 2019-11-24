#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll A, B, X;

ll digits(ll x)
{
    ll ans = 0;
    while (x > 0)
    {
        x /= 10;
        ans++;
    }
    return ans;
}

int main()
{
    cin >> A >> B >> X;

    ll i = 0;
    ll j = 1e9 + 1;

    while (i < j)
    {
        ll m = (i + j) >> 1;
        if (A * m + B * digits(m) > X)
            j = m;
        else
            i = m + 1;
    }

    cout << i - 1 << '\n';
}