#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n, m;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> m;

        cout << n * m / 2 + bool((n * m) % 2) << '\n';
    }
}