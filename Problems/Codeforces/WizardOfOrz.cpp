#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;

        cout << 9;
        if (N > 1) cout << 8;
        if (N > 2) rep(i, N - 2) cout << (8 + i + 1) % 10;
        cout << '\n';
    }
}