#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n;

int main()
{
    cin >> T;
    rep(_, T)
    {
        cin >> n;
        if (n == 1) { cout << -1 << '\n'; continue; }
        else
        {
            cout << 2;
            rep(i, n - 1) cout << 3;
            cout << '\n';
        }
    }
}