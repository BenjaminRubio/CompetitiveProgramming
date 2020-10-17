#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, a, b, c, d;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> a >> b >> c >> d;

        if (a == c || b == d) cout << abs(a - c) + abs(b - d) << '\n';
        else cout << abs(a - c) + abs(b - d) + 2 << '\n';
    }
}