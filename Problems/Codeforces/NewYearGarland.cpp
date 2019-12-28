#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

long long T, r, g, b;

int main()
{
    cin >> T;
    rep(t, T)
    {
        cin >> r >> g >> b;
        long long m = (r + g + b) - (r + g + b) / 2;

        if (r > m || g > m || b > m)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
}