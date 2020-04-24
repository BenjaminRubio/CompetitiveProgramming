#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n, p;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        int m = INT_MAX, l;
        bool pos = true;
        rep(i, n)
        {
            cin >> p;
            if (p > m and p != l + 1) pos = false;
            if (p <= l and p >= m) pos = false;
            l = p; m = min(m, p);
        }

        if (pos) cout << "Yes\n";
        else cout << "No\n";
    }
}