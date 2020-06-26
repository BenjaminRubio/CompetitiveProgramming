#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

ll T, a, b, c;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> a >> b >> c;

        if (a < c) cout << 1 << ' ';
        else cout << -1 << ' ';
        if (a * b > c) cout << b << '\n';
        else cout << -1 << '\n';
    }
}