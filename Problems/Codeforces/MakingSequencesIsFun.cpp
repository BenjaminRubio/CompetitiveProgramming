#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;

ll w, m, k;

int main()
{
    cin >> w >> m >> k;

    ll ans = 0, c = 0; int n = log10(m) + 1;
    while (c + (pow(10, n) - m) * n * k <= w)
    {
        c += (pow(10, n) - m) * n * k;
        ans += pow(10, n) - m;
        m = pow(10, n), n++;
    }
    ans += (w - c) / (n * k);

    cout << ans << '\n';
}