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
        if (N == 1) cout << 0 << '\n';
        else if (N == 2) cout << 1 << '\n';
        else if (N == 3) cout << 2 << '\n';
        else if (N % 2 == 0) cout << 2 << '\n';
        else cout << 3 << '\n';
    }
}