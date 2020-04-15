#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, x, n, m;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> x >> n >> m;

        bool pos = false;

        if (x <= 10 * m) pos = true;
        while (n--)
        {
            x = x / 2 + 10;
            if (x <= 10 * m) pos = true;
        }

        if (pos) cout << "YES\n";
        else cout << "NO\n";
    }
}