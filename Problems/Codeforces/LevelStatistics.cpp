#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;

        bool pos = true;
        int p, c, lp = 0, lc = 0;
        rep(i, n)
        {
            cin >> p >> c;
            if (p < lp or c < lc) pos  = false;
            if (p - lp < c - lc) pos = false;
            if (c > p) pos = false; 
            lp = p; lc = c;
        }

        if (pos) cout << "YES\n";
        else cout << "NO\n";
    }
}