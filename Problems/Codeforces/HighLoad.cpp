#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n, k;

int main()
{
    cin >> n >> k;

    int d = (n - k - 1) / k;
    int r = (n - k - 1) % k;
    if (r) cout << 2 * (d + 1) + 1 << '\n';
    else cout << 2 * (d + 1) << '\n';
    d++;

    int l = 1;
    rep(i, k)
    {
        cout << 1 << ' ' << ++l << '\n';
        rep(_, d - 1 + bool(r)) cout << l << ' ' << ++l << '\n';
        if (r) r--;
    }
}