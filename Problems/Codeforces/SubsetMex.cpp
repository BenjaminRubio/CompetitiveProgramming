#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)

int T, N, a, A[101];

int main()
{
    cin >> T;
    while (T--)
    {
        memset(A, 0, sizeof A);

        cin >> N;
        rep(i, N) { cin >> a; A[a]++; }

        int ans = 0, c = 0;
        rep(i, 101)
        {
            if (A[i] == 0) ans += i, c++;
            if (A[i] < 2 - c) ans += i, c++;
            if (c == 2) break;
        }

        cout << ans << '\n';
    }
}