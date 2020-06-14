#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, X, a;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> X;

        int d = INT_MAX, s = 0;
        rep(i, N)
        {
            cin >> a;
            s += a;
            if (a % X) d = min({d, i, N - i - 1});
        }
        if (s % X == 0)
        {
            if (d == INT_MAX) cout << -1 << '\n';
            else cout << N - d - 1 << '\n';
        }
        else cout << N << '\n';
    }
}