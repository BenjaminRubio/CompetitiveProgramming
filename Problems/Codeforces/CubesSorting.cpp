#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, a, p;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        p = INT_MAX;
        bool ans = 0;
        rep(i, N)
        {
            cin >> a;
            if (a >= p) ans = 1;
            p = a;
        }

        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }
}