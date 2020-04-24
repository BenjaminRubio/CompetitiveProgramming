#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n, a, b, c, d;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> a >> b >> c >> d;
        if (n * (a + b) >= c - d and n * (a + b) <= c + d) cout << "Yes\n";
        else if (n * (a - b) <= c + d and n * (a + b) >= c - d) cout << "Yes\n";
        else cout << "No\n";
    }
}