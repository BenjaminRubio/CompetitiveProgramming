#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int n, m, k, x, y;

int main()
{
    cin >> n >> m >> k;

    rep(i, 2 * k) cin >> x, y;

    cout << n * m + n + m - 3 << '\n';
    rep(i, n - 1) cout << 'D';
    rep(i, m - 1) cout << 'L';
    rep(i, n)
    {
        if (i) cout << 'U';
        if (i % 2 == 0) rep(i, m - 1) cout << 'R';
        if (i % 2 == 1) rep(i, m - 1) cout << 'L';
    }
}