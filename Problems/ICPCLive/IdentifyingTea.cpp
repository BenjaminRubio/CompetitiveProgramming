#include <bits/stdc++.h>
using namespace std;

int T, x;

int main()
{
    while (cin >> T)
    {
        int ans = 0;
        for (int i = 0; i < 5; i++)
        {
            cin >> x;
            if (x == T)
                ans++;
        }

        cout << ans << '\n';
    }
}