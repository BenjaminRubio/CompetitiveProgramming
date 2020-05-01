#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, n;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        int a = 0, b = 0;
        rep(i, n)
        {
            if (i < (n / 2 - 1)) a += (1 << (i + 1));
            else if (i < n - 1) b += (1 << (i + 1));
            else a += (1 << (i + 1));
        }
        cout << a - b << '\n';
    }
}