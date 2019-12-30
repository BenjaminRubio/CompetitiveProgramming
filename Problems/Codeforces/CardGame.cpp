#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n, k1, k2, x;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> k1 >> k2;

        bool first = false;
        rep(i, k1)
        {
            cin >> x;
            if (x == n)
                first = true;
        }

        rep(i, k2) cin >> x;

        if (first)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}