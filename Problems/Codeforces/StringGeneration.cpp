#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, K;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> K;

        rep(i, N)
        {
            if (i % 3 == 0) cout << 'a';
            if (i % 3 == 1) cout << 'b';
            if (i % 3 == 2) cout << 'c';
        }
        cout << '\n';
    }
}