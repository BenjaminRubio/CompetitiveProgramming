#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

int N, C, K, X;
int t[101];

int main()
{
    while (cin >> N >> C >> K)
    {
        if (N == 0)
            break;

        memset(t, 0, sizeof t);

        rep(i, N) rep(j, C)
        {
            cin >> X;
            t[X]++;
        }

        int m = 1e9;
        repx(i, 1, K + 1) m = min(m, t[i]);

        int c = 0;
        repx(i, 1, K + 1) if (t[i] == m) c++;

        int c_ = 0;
        repx(i, 1, K + 1)
        {
            if (t[i] == m)
            {
                if (c_ < c - 1)
                    cout << i << ' ';
                else
                    cout << i;
                c_++;
            }
        }
        cout << '\n';
    }
}