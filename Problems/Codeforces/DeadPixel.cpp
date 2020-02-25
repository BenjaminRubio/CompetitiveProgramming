#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, a, b, x, y;

int main()
{
    cin >> T;
    rep(_, T)
    {
        cin >> a >> b >> x >> y;

        cout << max({x * b, y * a, (a - x - 1) * b, (b - y - 1) * a}) << '\n';
    }
}