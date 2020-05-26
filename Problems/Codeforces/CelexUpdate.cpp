#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

long long T, x, y, x_, y_;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> x >> y >> x_ >> y_;

        cout << (x_ - x) * (y_ - y) + 1ll << '\n';
    }
}