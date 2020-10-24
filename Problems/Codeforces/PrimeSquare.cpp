#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N;

const int MAX = 1e5;

int main()
{
    cin >> T;

    while (T--)
    {
        cin >> N;

        rep(i, N)
        {
            rep(j, N)
            {
                if (j == N - i - 1) cout << 1 << ' ';
                else if (j == N - i - 2) cout << 1 << ' ';
                else if (i == N - 1 && j == N - 1) cout << 1 << ' ';
                else cout << 0 << ' ';
            }
            cout << '\n';
        }
    }
}