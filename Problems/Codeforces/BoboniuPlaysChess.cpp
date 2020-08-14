#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int N, M, x, y;
vector<vector<bool>> B;

int main()
{
    cin >> N >> M >> x >> y; x--, y--;

    cout << x + 1 << ' ' << y + 1 << '\n';
    B.assign(N, vector<bool>(M, 0));
    B[x][y] = 1;

    if (y)
    {
        if (x) { x = 0; cout << x + 1 << ' ' << y + 1 << '\n'; B[x][y] = 1; }
        if (y) { y = 0; cout << x + 1 << ' ' << y + 1 << '\n'; B[x][y] = 1; }

        rep(i, N) rep(j, M)
        {
            x = i, y = ((i & 1) ? M - j - 1 : j);
            if (!B[x][y]) cout << x + 1 << ' ' << y + 1 << '\n';
        }
    }
    else
    {
        if (x) { x = 0; cout << x + 1 << ' ' << y + 1 << '\n'; B[x][y] = 1; }

        rep(i, M) rep(j, N)
        {
            x = ((i & 1) ? N - j - 1 : j), y = i;
            if (!B[x][y]) cout << x + 1 << ' ' << y + 1 << '\n';
        }
    }
}