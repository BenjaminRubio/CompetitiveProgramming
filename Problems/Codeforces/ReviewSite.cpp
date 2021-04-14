#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, r;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        int ans = 0;
        rep(_, N)
        {
            cin >> r;
            if (r != 2) ans++;
        }

        cout << ans << '\n';
    }
}