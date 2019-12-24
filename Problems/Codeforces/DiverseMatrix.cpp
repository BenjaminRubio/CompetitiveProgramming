#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int r, c;

int main()
{
    cin >> r >> c;
    if (r == 1 && c == 1)
    {
        cout << 0 << '\n';
        return 0;
    }
    if (r <= c)
    {
        rep(i, r) 
        {
            rep(j, c) cout << (i + 1) * (r + j + 1) << ' ';
            cout << '\n';
        }
    }
    else
    {
        rep(i, r) 
        {
            rep(j, c) cout << (c + i + 1) * (j + 1) << ' ';
            cout << '\n';
        }
    }
}