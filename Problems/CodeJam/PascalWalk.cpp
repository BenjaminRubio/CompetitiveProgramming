#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N;

int main()
{
    cin >> T;
    rep(t, T)
    {
        cin >> N;
        cout << "Case #" << t + 1 << ":\n";

        int m = 0;
        while ((1 << m) <= N) m++;
        m--;

        if ((1 << m) == N)
        {
            rep(i, m) rep(j, i + 1) 
                cout << i + 1 << ' ' << ((i % 2) ? (j + 1) : (i - j + 1)) << '\n';
            cout << m + 1 << ' ' << ((m % 2) ? 1 : m + 1) << '\n';
            continue;
        }

        if (((1 << m) + m) >= N)
        {
            rep(i, m) rep(j, i + 1) 
                cout << i + 1 << ' ' << ((i % 2) ? (j + 1) : (i - j + 1)) << '\n';
            rep(i, N - (1 << m) + 1) cout << m + i + 1 << ' ' << ((m % 2) ? 1 : m + i + 1) << '\n';
            continue;
        }
        N -= m;

        int r = 0, p = 0;
        bool l = true;
        rep(i, m + 1) if ((1 << i) & N)
        {
            p++;
            while (r < i)
            {
                r++;
                cout << r << ' ';
                if (l) cout << 1 << '\n';
                else cout << r << '\n';
            }
            rep(j, i + 1) cout << i + 1 << ' ' << (l ? j + 1 : i - j + 1) << '\n';
            r++;
            l = !l;
        }
        rep(i, p - 1)
        {
            r++;
            cout << r << ' ';
            if (l) cout << 1 << '\n';
            else cout << r << '\n';
        }
    }
}