#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, a;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        int o = 0, c = 0;
        rep(i, N)
        {
            cin >> a;
            if (a == 1) o++;
            if (a == 0) c++;
        }

        if (N == 2)
        {
            if (!c) cout << 2 << '\n' << 1 << ' ' << 1 << '\n';
            else cout << 1 << '\n' << 0 << '\n';
            continue;
        }

        if (o > c || c > o)
        {
            cout << (2 * (max(o, c) / 2)) << '\n';
            rep(i, 2 * (max(o, c) / 2)) cout << (o >= c ? 1 : 0) << ' ';
            cout << '\n';
        }
        else
        {
            cout << N / 2 << '\n';
            rep(i, N / 2) cout << 0 << ' ';
            cout << '\n';
        }
    }
}