#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N;
char ch;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        int v1 = -1, v2 = -1, v3 = -1, v4 = -1;
        rep(i, N) rep(j, N)
        {
            cin >> ch;
            if (i + j == 1)
            {
                if (v1 != -1) v2 = ch - '0';
                else v1 = ch - '0';
            }
            if (i + j == 2 * N - 3)
            {
                if (v3 != -1) v4 = ch - '0';
                else v3 = ch - '0';
            }
        }

        if (v1 == v2 && v3 == v4 && v1 != v4) { cout << 0 << '\n'; continue; }
        if (v1 != v2 && v3 == v4 && v1 != v3)
        { cout << 1 << '\n' << 2 << ' ' << 1 << '\n'; continue; }
        if (v1 != v2 && v3 == v4 && v2 != v3)
        { cout << 1 << '\n' << 1 << ' ' << 2 << '\n'; continue; }
        if (v1 == v2 && v3 != v4 && v1 != v3)
        { cout << 1 << '\n' << N << ' ' << N - 1 << '\n'; continue; }
        if (v1 == v2 && v3 != v4 && v1 != v4)
        { cout << 1 << '\n' << N - 1 << ' ' << N << '\n'; continue; }
        if (v1 == v2 && v3 == v4)
        { cout << 2 << '\n' << 1 << ' ' << 2 << '\n' << 2 << ' ' << 1 << '\n'; continue; }
        if (v1 == v3)
        { cout << 2 << '\n' << 1 << ' ' << 2 << '\n' << N << ' ' << N - 1 << '\n'; continue; }
        if (v2 == v3)
        { cout << 2 << '\n' << 2 << ' ' << 1 << '\n' << N << ' ' << N - 1 << '\n'; continue; }
    }
}