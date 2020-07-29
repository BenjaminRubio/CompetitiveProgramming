#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T;
ll l, r;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> l >> r;

        if (l * (l + 1) <= r) cout << l << ' ' << l + 1ll << '\n';
        else if (2ll * l <= r) cout << l << ' ' << 2ll * l << '\n';
        else cout << -1 << ' ' << -1 << '\n';
    }
}