#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, x;

int main()
{
    cin >> T;
    rep(_, T)
    {
        cin >> x;
        cout << 1 << ' ' << x - 1 << '\n';
    }
}