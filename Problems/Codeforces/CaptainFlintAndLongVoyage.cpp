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
        int x = (N - 1) / 4 + 1;
        rep(i, N - x) cout << 9;
        rep(i, x) cout << 8;
        cout << '\n';
    }
}