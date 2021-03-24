#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, a, b, c, r;

int main()
{
    cin >> T;
    rep(t, T)
    {
        cin >> a >> b >> c >> r;

        if (a > b) swap(a, b);

        if (c + r < a || c - r > b)
            cout << b - a << '\n';
        else 
            cout << max(0, (c - r) - a) + max(0, b - (c + r)) << '\n';
    }
}