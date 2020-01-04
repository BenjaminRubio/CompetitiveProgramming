#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, x;

int main()
{
    while (cin >> N)
    {
        if (N == 0)
            break;

        int a = 0, b = 0;
        rep(i, N)
        {
            cin >> x;
            if (x % 2 == 0)
                a++;
        }
        rep(i, N)
        {
            cin >> x;
            if (x % 2 == 1)
                b++;
        }

        cout << max(a, b) - min(a, b) << '\n';
    }
}