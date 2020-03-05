#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n, m, x, a;

int main()
{
    cin >> T;
    rep(_, T)
    {
        cin >> n >> m;

        cin >> x;

        int s = 0;
        rep(i, n - 1)
        {
            cin >> a;
            s += a;
        }

        cout << min(x + s, m) << '\n';
    }
}