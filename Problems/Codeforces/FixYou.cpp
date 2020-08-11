#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, M;
char d;

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> M;

        int ans = 0;
        rep(i, N) rep(j, M)
        {
            cin >> d;
            if (j == M - 1 && d == 'R') ans++;
            if (i == N - 1 && d == 'D') ans++;
        }
        cout << ans << '\n';
    }
}